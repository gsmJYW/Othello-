#include <WS2tcpip.h>
#include <vector>
#include <regex>
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

	// 게임 열기
	if (menuNumber == TO_SERVER_MENU)
	{
		int serverStatus = 0;

		connection = std::thread(Server, &sock, &serverStatus, &receive);
		ServerMenu(&serverStatus);
	}
	// 게임 접속하기
	else
	{
		int clientStatus = 0;

		connection = std::thread(Client, &sock, &clientStatus, &receive);
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

	initBoard(board);  // 돌 교차 후 시작
	turn = BLACK; // 흑이 선공

	system("mode con:cols=34 lines=20");
	std::string notification;
	
	while (true)
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

				while (myColor == turn)
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
						refreshNeeded = false;
					}
				}
			}
			// 돌을 놓을 수 없을 경우
			else
			{
				notification = "돌을 놓을 공간이 없습니다.";
				turn = opponentColor;

				PrintBoard(board, myColor, turn, NULL, NULL, notification);
				Sleep(4000);

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

					turn = myColor;
					receive = "";
					break;
				}
			}
		}
	}

	int myCount, opponentCount;

	if (myColor == BLACK)
	{
		CountPiece(board, &myCount, &opponentCount);
	}
	else
	{
		CountPiece(board, &opponentCount, &myCount);
	}

	if (myCount > opponentCount)
	{
		notification = "당신의 승리입니다.";
	}
	else if (myCount < opponentCount)
	{
		notification = "상대의 승리입니다.";
	}
	else
	{
		notification = "무승부입니다.";
	}

	PrintBoard(board, myColor, 0, NULL, NULL, notification);
	std::cout << " 종료<┛";

	while (_getch() != 13)
	{

	}

	exit(0);
}