#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "connection.h"

#define BLACK 1
#define WHITE 2

#define TO_EXIT				0
#define	TO_START_MENU		1
#define TO_HELP_MENU		2
#define TO_CONNECTION_MENU	3
#define TO_SERVER_MENU		4
#define TO_CLIENT_MENU		5

// �ΰ� ���
void PrintLogo()
{
	std::cout << "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n"
		<< "�������������������������������������������������������������������������������������������������������� ��������\n"
		<< "���������ᡡ�������ᡡ�ᡡ�����ᡡ�����ᡡ�ᡡ���������ᡡ�������������ᡡ������������������������ ��\n"
		<< "�����ᡡ�����ᡡ�����ᡡ�����ᡡ�����ᡡ�ᡡ���������ᡡ���������ᡡ���������ᡡ�����ᡡ�����ᡡ���������ᡡ�� ��\n"
		<< "�����ᡡ�����ᡡ�����ᡡ�����ᡡ�����ᡡ�ᡡ���������ᡡ���������ᡡ���������ᡡ�����ᡡ�����ᡡ���������ᡡ�� ��\n"
		<< "�����ᡡ�����ᡡ�����ᡡ���������ᡡ�����ᡡ�ᡡ���������ᡡ���������ᡡ�����ᡡ�����ᡡ������ ��\n"
		<< "�����ᡡ�����ᡡ�����ᡡ�����ᡡ�����ᡡ�ᡡ���������ᡡ���������ᡡ���������ᡡ�����ᡡ�����ᡡ���������ᡡ�� ��\n"
		<< "�����ᡡ�����ᡡ�����ᡡ�����ᡡ�����ᡡ�ᡡ���������ᡡ���������ᡡ���������ᡡ�����ᡡ�����ᡡ���������ᡡ�� ��\n"
		<< "���������ᡡ�������ᡡ�����ᡡ�����ᡡ�����ᡡ�����ᡡ�����ᡡ�����ᡡ������������������������ ��\n"
		<< "�������������������������������������������������������������������������������������������������������� ��������\n"
		<< "������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������\n\n\n";
}

// ���� �޴� ���
void PrintStartMenu(int menu)
{
	system("cls");
	PrintLogo();

	// �޴� ���

	if (menu == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "�������������������������������������������� ������������������������������������������\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������  �����ۡ����� ��\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������������������������������������������\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	if (menu == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "�������������������������������������������� ������������������������������������������\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������  ���������� ��\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������������������������������������������\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	if (menu == 3)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "�������������������������������������������� ������������������������������������������\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������  �����ᡡ���� ��\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������������������������������������������\n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// ���� ���
int HelpMenu()
{
	system("cls");
	PrintLogo();

	std::cout << "\n\n\n Ű���� ����Ű�� �������� Ŀ��(�ߡ�)�� �̵���ų �� �ֽ��ϴ�.\n"
		<< " ���͸� �Է��ϸ� Ŀ���� �ִ� ��ġ�� ��(�ܡ�)�� �����ϴ�.\n"
		<< " ���� ���� ���� �� �ִ� ���� ���ٸ� �ڵ����� ���� �Ѱ����ϴ�.\n"
		<< " ���� ����, ���� �İ��̸� ��� ������ �������Դϴ�.\n"
		<< " �� ���� ���� ������� �����ο� �����ϴ�.\n\n"
		<< " Ȯ�� <��";

	// ���� �Է� �� ����
	while (_getch() != 13)
	{

	}

	return TO_START_MENU;
}

// ���� �޴�
int StartMenu()
{
	int menu = 1;
	PrintStartMenu(menu);

	while (true)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			// ��
			case 72:
				if (menu > 1)
				{
					menu--;
					PrintStartMenu(menu);
				}
				break;

			// �Ʒ�
			case 80:
				if (menu < 3)
				{
					menu++;
					PrintStartMenu(menu);
				}
				break;

			// ����
			case 13:
				switch (menu) {
				// ����
				case 1:
					return TO_CONNECTION_MENU;

				// ����
				case 2:
					return TO_HELP_MENU;
					break;

				// ����
				case 3:
					return TO_EXIT;
				}
			}
		}
	}
}

// ���� �޴� ���
void PrintConnectionMenu(int menu)
{
	system("cls");
	PrintLogo();

	// �޴� ���

	if (menu == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "�������������������������������������������� ������������������������������������������\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������  ���� ���⡡����\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������������������������������������������\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	if (menu == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "�������������������������������������������� ������������������������������������������\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ���������� �����ϱ⡡��\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������������������������������������������\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	if (menu == 3)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "�������������������������������������������� ������������������������������������������\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������  ����ҡ����� ��\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������������������������������������������\n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// ���� ���� �޴�
int ConnectionMenu()
{
	int menu = 1;
	PrintConnectionMenu(menu);

	while (true)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			// ��
			case 72:
				if (menu > 1)
				{
					menu--;
					PrintConnectionMenu(menu);
				}
				break;

			// �Ʒ�
			case 80:
				if (menu < 3)
				{
					menu++;
					PrintConnectionMenu(menu);
				}
				break;

			// ����
			case 13:
				switch (menu) {
				// ���� ����
				case 1:
					return TO_SERVER_MENU;

				// ���� �����ϱ�
				case 2:
					return TO_CLIENT_MENU;

				// ���
				case 3:
					return TO_START_MENU;
				}
			}
		}
	}
}

void ServerMenu(int* serverStatus)
{
	int previousServerStatus = UNCALLED;

	while (*serverStatus != CONNECTED)
	{
		if (previousServerStatus != *serverStatus)
		{
			system("cls");
			PrintLogo();

			std::cout << "\n\n\n\n\n\n";

			switch (*serverStatus)
			{
			case FAILED:
				std::cout << " ���� ���� ����\n"
					<< " Ȯ�� <��";
				while (_getch() != 13)
				{

				}
				exit(1);

			case UNCALLED:
				std::cout << " ���� ���� ��";
				break;

			case CONNECTING:
				std::cout << " ���� ���� �Ϸ�\n"
					<< " �����ڸ� ��ٸ��� ��";
				break;
			}

			previousServerStatus = *serverStatus;
		}
	}
}

void ClientMenu(int* clientStatus)
{
	int previousClientStatus = UNCALLED;

	while (*clientStatus != CONNECTED)
	{
		if (previousClientStatus != *clientStatus)
		{
			system("cls");
			PrintLogo();

			std::cout << "\n\n\n\n\n\n";

			switch (*clientStatus)
			{
			case FAILED:
				std::cout << " ���� ���� ����\n"
					<< " ���� <��";
				while (_getch() != 13)
				{

				}
				exit(1);

			case IP_INPUT:
				std::cout << " ip �ּ�:\n ";
				break;

			case CONNECTING:
				std::cout << " ���� ���� ��";
				break;
			}

			previousClientStatus = *clientStatus;
		}
	}
}

void PrintColorMenu(int menu, int color, int opponentColor)
{
	system("cls");
	PrintLogo();

	std::cout << "\n���������������������������������������������� ������ �����Դϴ�.\n\n\n";

	// �޴� ���

	if (menu == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "�������������������������������������������� ������������������������������������������\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������  �� �桡�������� "
		<< (color == 1 ? "���� ������" : (opponentColor == 1 ? "��밡 ������" : ""))
		<< "\n�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������������������������������������������\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	if (menu == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "�������������������������������������������� ������������������������������������������\n"
		<< "�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ���������� �顡�������� "
		<< (color == 2 ? "���� ������" : (opponentColor == 2 ? "��밡 ������" : ""))
		<< "\n�������������������������������������������� �������������������� ��\n"
		<< "�������������������������������������������� ������������������������������������������\n\n\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// ��� ���� �޴�
int ColorMenu(SOCKET sock, std::string* receive)
{
	int menu = 1;
	int color = 0;
	int opponentColor = 0;

	PrintColorMenu(menu, color, opponentColor);

	while (true)
	{
		if ((*receive).length() > 0)
		{
			if (*receive == "black")
			{
				opponentColor = BLACK;
			}
			else if (*receive == "white")
			{
				opponentColor = WHITE;
			}
			else
			{
				opponentColor = 0;
			}

			PrintColorMenu(menu, color, opponentColor);
			*receive = "";
		}

		if (_kbhit())
		{
			switch (_getch())
			{
			// ��
			case 72:
				if (menu > 1)
				{
					menu--;
					PrintColorMenu(menu, color, opponentColor);
				}
				break;

			// �Ʒ�
			case 80:
				if (menu < 2)
				{
					menu++;
					PrintColorMenu(menu, color, opponentColor);
				}
				break;

			// ����
			case 13:
				if (menu == 1 && opponentColor != BLACK)
				{	
					if (color == BLACK)
					{
						Send(sock, "cancel");
						color = 0;
					}
					else
					{
						Send(sock, "black");
						color = BLACK;
					}
					
					PrintColorMenu(menu, color, opponentColor);
				}
				else if (menu == 2 && opponentColor != WHITE)
				{
					if (color == WHITE)
					{
						Send(sock, "cancel");
						color = 0;
					}
					else {
						Send(sock, "white");
						color = WHITE;
					}

					PrintColorMenu(menu, color, opponentColor);
				}
				break;
			}
		}

		if (color != 0 && opponentColor != 0)
		{
			return color;
		}
	}
}