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
			// 종료 메뉴
		case 0:
			exit(0);

			// 시작 메뉴
		case 1:
			menuNumber = StartMenu();
			break;

			// 설명
		case 2:
			menuNumber = Help();
			break;

			// 접속 메뉴 
		case 3:
			menuNumber = ConnectionMenu();
			break;
		}
	}

	// 게임 열기
	if (menuNumber == 4)
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

	int myColor = ColorMenu();
	turn = BLACK;

	system("mode con:cols=34 lines=19");
	initBoard();
	PrintBoard();
	
	while (true)
	{

	}

	exit(0);
}