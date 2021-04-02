#include <WS2tcpip.h>
#include "menu.h"
#include "board.h"

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

	// 게임 열기
	if (menuNumber == TO_SERVER_MENU)
	{
		connection = std::thread(Server);
		int previousServerStatus = 0;

		while (true)
		{
			// 클라이언트 연결 완료
			if (serverStatus == 2)
			{
				break;
			}
			// 연결 진행도 변함
			else if (previousServerStatus != serverStatus)
			{
				ServerMenu(serverStatus);
				previousServerStatus = serverStatus;
			}
			// 연결 실패
			else if (_kbhit() && serverStatus == -1)
			{
				if (_getch() == 13)
				{
					exit(1);
				}
			}
		}
	}
	// 게임 접속하기
	else
	{
		connection = std::thread(Client);
		int previousClientStatus = -1;

		while (true)
		{
			if (clientStatus == 2)
			{
				break;
			}
			else if (previousClientStatus != clientStatus)
			{
				ClientMenu(clientStatus);
				previousClientStatus = clientStatus;
			}
			else if (_kbhit() && clientStatus == -1)
			{
				if (_getch() == 13)
				{
					exit(1);
				}
			}
		}
	}

	myColor = ColorMenu(); // 색 선택

	initBoard();  // 돌 교차 후 시작
	turn = BLACK; // 흑이 선공

	system("mode con:cols=34 lines=20");
	
	while (true)
	{
		// 내 턴일 때
		if (myColor == turn)
		{
			notification = "당신 차례입니다.";

			cursorX = 0;
			cursorY = 0;
			PrintBoard();

			while (true)
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
							PrintBoard();
						}
						break;

					// 오른쪽
					case 75:
						if (cursorX > 0)
						{
							cursorX--;
							PrintBoard();
						}
						break;

					// 왼쪽
					case 77:
						if (cursorX < 7)
						{
							cursorX++;
							PrintBoard();
						}
						break;

					// 아래
					case 80:
						if (cursorY < 7)
						{
							cursorY++;
							PrintBoard();
						}
						break;

					// 엔터
					case 13:
						std::cout << isAbleToPlace() << std::endl;
						break;
					}
				}
			}
		}
		else {
			notification = "상대 차례입니다.";
			PrintBoard();

			while (receive.length() <= 0)
			{

			}
		}
	}

	exit(0);
}