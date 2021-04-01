#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "connection.h"

#define BLACK 1
#define WHITE 2

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
		<< "�������������������������������������������� ������������������������������������������\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// ���� ���
int Help()
{
	system("cls");
	PrintLogo();

	std::cout << "\n\n\n Ű���� ����Ű�� �������� Ŀ��(���)�� �̵���ų �� �ֽ��ϴ�.\n"
		<< " ���͸� �Է��ϸ� Ŀ���� �ִ� ��ġ�� ��(�ܡ�)�� �����ϴ�.\n"
		<< " ���� ���� ���� �� �ִ� ���� ���ٸ� �ڵ����� ���� �Ѱ����ϴ�.\n"
		<< " ���� ����, ���� �İ��̸� ��� ������ �������Դϴ�.\n"
		<< " �� ���� ���� ������� �����ο� �����ϴ�.\n\n"
		<< " Ȯ�� <��";

	// ���� �Է� �� ����
	while (true)
	{
		if (_kbhit())
		{
			if (_getch() == 13)
			{
				break;
			}
		}
	}

	return 1;
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
			int key = _getch();

			switch (key) {
			
			// ���� �޴��� �̵�
			case 72:
				if (menu > 1)
				{
					menu--;
					PrintStartMenu(menu);
				}
				break;

			// �Ʒ��� �޴��� �̵�
			case 80:
				if (menu < 3)
				{
					menu++;
					PrintStartMenu(menu);
				}
				break;

			// �޴� ����
			case 13:
				switch (menu) {
				// ����
				case 1:
					return 3; // ���� �޴��� �̵�

				// ����
				case 2:
					return 2; // �������� �̵�
					break;

				// ����
				case 3:
					return 0;
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
		<< "�������������������������������������������� ������������������������������������������\n";

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
			int key = _getch();

			switch (key) {
			case 72:
				if (menu > 1)
				{
					menu--;
					PrintConnectionMenu(menu);
				}
				break;

			case 80:
				if (menu < 3)
				{
					menu++;
					PrintConnectionMenu(menu);
				}
				break;

			case 13:
				switch (menu) {
				case 1:
					return 4;

				case 2:
					return 5;

				case 3:
					return 1;
				}
			}
		}
	}
}

void ServerMenu(int serverStatus)
{
	system("cls");
	PrintLogo();

	std::cout << "\n\n\n\n\n\n";

	switch (serverStatus)
	{
	case -1:
		std::cout << " ���� ���� ����\n"
			<< " Ȯ�� <��";
		break;

	case 0:
		std::cout << " ���� ���� ��";
		break;

	case 1:
		std::cout << " ���� ���� �Ϸ�\n"
			<< " �����ڸ� ��ٸ��� ��";
		break;
	}
}

void ClientMenu(int clientStatus)
{
	system("cls");
	PrintLogo();

	std::cout << "\n\n\n\n\n\n";

	switch (clientStatus)
	{
	case -1:
		std::cout << " ���� ���� ����\n"
			<< " ���� <��";
		break;

	case 0:
		std::cout << " ip �ּ�:\n ";
		break;

	case 1:
		std::cout << " ���� ���� ��";
		break;
	}
}

void PrintColorMenu(int menu, int color, int opponentColor)
{
	system("cls");
	PrintLogo();

	std::cout << "\n���������������������������������������������� ������ �����Դϴ�\n\n\n";

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
		<< "�������������������������������������������� ������������������������������������������\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// ��� ���� �޴�
int ColorMenu()
{
	int menu = 1;
	int color = 0;
	int opponentColor = 0;

	PrintColorMenu(menu, color, opponentColor);

	while (true)
	{
		if (receive.length() > 0)
		{
			if (receive == "black")
			{
				opponentColor = BLACK;
			}
			else if (receive == "white")
			{
				opponentColor = WHITE;
			}
			else
			{
				opponentColor = 0;
			}

			PrintColorMenu(menu, color, opponentColor);
			receive = "";
		}

		if (_kbhit())
		{
			int key = _getch();

			switch (key) {

				// ���� �޴��� �̵�
			case 72:
				if (menu > 1)
				{
					menu--;
					PrintColorMenu(menu, color, opponentColor);
				}
				break;

				// �Ʒ��� �޴��� �̵�
			case 80:
				if (menu < 2)
				{
					menu++;
					PrintColorMenu(menu, color, opponentColor);
				}
				break;

				// �޴� ����
			case 13:
				if (menu == 1 && opponentColor != BLACK)
				{	
					if (color == BLACK)
					{
						Send("cancel");
						color = 0;
					}
					else
					{
						Send("black");
						color = BLACK;
					}
					
					PrintColorMenu(menu, color, opponentColor);
				}
				else if (menu == 2 && opponentColor != WHITE)
				{
					if (color == WHITE)
					{
						Send("cancel");
						color = 0;
					}
					else {
						Send("white");
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