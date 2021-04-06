#include <WS2tcpip.h>
#include <vector>
#include <regex>
#include <chrono>
#include "menu.h"
#include "board.h"

// 문자열을 특정 문자 기준으로 나눠 vector에 저장
std::vector<std::string> Split(std::string str, char sep = ' ')
{
	std::vector<std::string> vec;
	std::string word = "";

	for (int index = 0; index < str.length(); index++)
	{
		if (str[index] == sep)
		{
			if (word.length() > 0)
			{
				vec.push_back(word);
				word = "";
			}
		}
		else if (index == str.length() - 1)
		{
			word += str[index];
			vec.push_back(word);
		}
		else
		{
			word += str[index];
		}
	}

	return vec;
}

int main()
{
	std::thread connection;
	int menuNumber = 1;

	SetConsoleTitleA("Othello++");
	system("mode con:cols=112 lines=30");

	while (menuNumber <= 3)
	{
		switch (menuNumber)
		{
			// 종료
		case TO_EXIT:
			exit(0);

			// 시작 메뉴
		case TO_START_MENU:
			menuNumber = StartMenu();
			break;

			// 설명 메뉴
		case TO_HELP_MENU:
			menuNumber = HelpMenu();
			break;

			// 접속 메뉴 
		case TO_CONNECTION_MENU:
			menuNumber = ConnectionMenu();
			break;
		}
	}

	SOCKET sock;
	std::string receive;
	bool isGameGoingOn;

	// 게임 열기
	if (menuNumber == TO_SERVER_MENU)
	{
		int serverStatus = 0;

		connection = std::thread(Server, &sock, &serverStatus, &receive, &isGameGoingOn);
		ServerMenu(&serverStatus);
	}
	// 게임 접속하기
	else
	{
		int clientStatus = 0;

		connection = std::thread(Client, &sock, &clientStatus, &receive, &isGameGoingOn);
		ClientMenu(&clientStatus);
	}

	int myColor = ColorMenu(sock, &receive); // 색 선택
	int opponentColor;

	if (myColor == BLACK)
	{
		opponentColor = WHITE;
	}
	else
	{
		opponentColor = BLACK;
	}

	int board[8][8];
	int turn;

	initBoard(board);	// 돌 교차 후 시작
	turn = BLACK;		// 흑이 선공

	system("mode con:cols=34 lines=22");
	std::string notification;
	
	int time = 60 * 5; // 제한 시간 5분
	bool timeout = false;

	while (!timeout)
	{
		bool AmIAbleToPlace = isThereAvailablePlace(board, myColor);
		bool isOpponentAbleToPlace = isThereAvailablePlace(board, opponentColor);

		// 두 명 모두 돌을 놓을 수 없을 경우 게임 종료
		if (!AmIAbleToPlace && !isOpponentAbleToPlace)
		{
			break;
		}

		// 내 턴일 때
		if (myColor == turn)
		{
			if (AmIAbleToPlace)
			{
				notification = "당신 차례입니다.";

				int cursorX = 0;
				int cursorY = 0;

				bool refreshNeeded = true;

				// 시간 측정
				std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
				std::chrono::duration<double> elapsedSecs;

				while (myColor == turn && time > elapsedSecs.count())
				{
					if (_kbhit())
					{
						switch (_getch())
						{
							// 위
						case 72:
							if (cursorY > 0)
							{
								cursorY--;
								refreshNeeded = true;
							}
							break;

							// 오른쪽
						case 75:
							if (cursorX > 0)
							{
								cursorX--;
								refreshNeeded = true;
							}
							break;

							// 왼쪽
						case 77:
							if (cursorX < 7)
							{
								cursorX++;
								refreshNeeded = true;
							}
							break;

							// 아래
						case 80:
							if (cursorY < 7)
							{
								cursorY++;
								refreshNeeded = true;
							}
							break;

							// 엔터
						case 13:
							if (isAvailable(board, myColor, cursorX, cursorY))
							{
								refreshNeeded = true;
								placePiece(board, myColor, cursorX, cursorY);

								Send(sock, "place " + std::to_string(myColor) + " " + std::to_string(cursorX) + " " + std::to_string(cursorY));
								turn = opponentColor;
							}
							break;
						}
					}

					if (refreshNeeded)
					{
						PrintBoard(board, myColor, turn, cursorX, cursorY, notification);
						std::cout << "\n";
						refreshNeeded = false;
					}
					
					elapsedSecs = std::chrono::system_clock::now() - start;
					printf("\33[2K\r 제한 시간: %.1f", time - elapsedSecs.count());
				}

				time -= elapsedSecs.count();

				// 시간 초과
				if (time <= 0)
				{
					timeout = true;
					Send(sock, "timeout");
				}
			}
			// 돌을 놓을 수 없을 경우
			else
			{
				notification = "돌을 놓을 공간이 없습니다.";
				turn = opponentColor;

				PrintBoard(board, myColor, turn, NULL, NULL, notification);
				Sleep(3000);

				Send(sock, "pass");
			}
		}
		else {
			if (isOpponentAbleToPlace)
			{
				notification = "상대 차례입니다.";
			}
			else
			{
				notification = "상대가 돌을 놓을 공간이 없습니다.";
			}
			
			PrintBoard(board, myColor, turn, NULL, NULL, notification);

			while (true)
			{
				if (receive.length() > 0)
				{
					std::vector<std::string> receiveArgs = Split(receive);

					if (receiveArgs[0] == "place")
					{
						placePiece(board, std::stoi(receiveArgs[1]), std::stoi(receiveArgs[2]), std::stoi(receiveArgs[3]));
					}
					else if (receiveArgs[0] == "timeout")
					{
						timeout = true;
					}

					turn = myColor;
					receive = "";
					break;
				}
			}
		}
	}

	PrintBoard(board, myColor, NULL, NULL, NULL, "");

	int winner;
	isGameGoingOn = false;

	if (timeout)
	{
		if (time <= 0)
		{
			std::cout << "시간을 다 썼습니다.";
			winner = opponentColor;
		}
		else
		{
			std::cout << "상대가 시간을 다 썼습니다.";
			winner = myColor;
		}
	}
	else
	{
		int blackPieceCount, whitePieceCount;

		CountPiece(board, &blackPieceCount, &whitePieceCount);

		if (blackPieceCount > whitePieceCount)
		{
			std::cout << "흑돌이 더 많습니다.";
			winner = BLACK;
		}
		else if (whitePieceCount > blackPieceCount)
		{
			std::cout << "백돌이 더 많습니다.";
			winner = WHITE;
		}
		else
		{
			std::cout << "돌 수가 같습니다.";
			winner = 0;
		}
	}

	std::cout << "\n ";

	if (winner == 0)
	{
		std::cout << "무승부입니다.";
	}
	else
	{
		std::cout << (winner == myColor ? "당신" : "상대")
			<< "의 승리입니다.";
	}

	std::cout << " 종료<┛";

	while (_getch() != 13)
	{

	}

	exit(0);
}