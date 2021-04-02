#include <stdio.h>
#include <Windows.h>
#include <iomanip>

int turn;
int myColor;
int cursorX, cursorY;
int board[8][8];

std::string notification;

#define EMPTY 0
#define BLACK 1
#define WHITE 2

void initBoard()
{
	// �迭 �ʱ�ȭ
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++)
			board[y][x] = EMPTY;

	// �浹�� �鵹 ���� �� ����
	board[3][3] = WHITE; board[3][4] = BLACK;
	board[4][3] = BLACK; board[4][4] = WHITE;
}

// ������ ���
void PrintBoard()
{
	std::string piece[8][8]; // �� ��¿� �迭

	// ������ �˻� �� �迭�� �� or ���� ����
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (myColor == turn && y == cursorY && x == cursorX)
			{
				piece[y][x] = (myColor == BLACK ? "��" : "��");
			}
			else
			{
				switch (board[y][x])
				{
				case EMPTY:
					piece[y][x] = "��";
					break;

				case BLACK:
					piece[y][x] = "��";
					break;

				case WHITE:
					piece[y][x] = "��";
					break;
				}
			}
		}
	}

	system("cls");
	
	std::cout << "������������������������������������������������������������������\n";
	
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			std::cout << "�� " << piece[y][x];
		}
		
		std::cout << "��\n";
		
		if (y != 7)
		{
			std::cout << "������������������������������������������������������������������\n";
		}
	}
	
	std::cout << "������������������������������������������������������������������\n";

	int whitePieceCount = 0, blackPieceCount = 0; // �� ����

	// �� ���� ī��Ʈ
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			switch (board[y][x])
			{
			case BLACK:
				blackPieceCount++;
				break;

			case WHITE:
				whitePieceCount++;
				break;
			}
		}
	}

	// �� ���� ���
	
	if (turn == BLACK)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	// "����������"

	std::cout << " �� ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
	std::cout << std::setfill('0') << std::setw(2) << blackPieceCount << " vs " << std::setfill('0') << std::setw(2) << whitePieceCount;

	if (turn == WHITE)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << " ��\n ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	std::cout << notification;

	return;

}

// ���� ���� �� �ִ� ��ġ�� �� üũ
bool isAbleToPlace(int x, int y)
{
	int waiting; // ��ٸ��� �ִ� ���(������ ���)

	if (turn == BLACK)
	{
		waiting = WHITE;
	}
	else {
		waiting = BLACK;
	}

	// �� ������ �ƴ� ��� ���� ���� �� ����
	if (board[y][x] != EMPTY) return false;

	// ���� ���� ������ �� �ִ� ���� �ִ��� �˻�
	for (int xDirection = -1; xDirection <= 1; xDirection++)
	{
		for (int yDirection = -1; yDirection <= 1; yDirection++)
		{
			if (xDirection == 0 && yDirection == 0)
			{
				continue;
			}

			// �˻��Ϸ��� ���⿡ ��� ���� ���� ��� �˻� ����
			if (board[y + yDirection][x + xDirection] == waiting)
			{
				int tempX = cursorX;
				int tempY = cursorY;

				while (true)
				{
					// �˻��� �������� �� ĭ�� ���ư��� �˻�
					tempX += xDirection;
					tempY += yDirection;

					// �������� �Ѿ�� ������ �� ����
					if (tempX < 0 || tempX > 7 || tempY < 0 || tempY > 7)
					{
						break;
					}

					// ������� ������ ������ �� ����
					if (board[tempY][tempX] == EMPTY)
					{
						break;
					}

					// �� ���� ������ ������ �� ����
					if (board[tempY][tempX] == turn)
					{
						return true;
						break;
					}
				}
			}
		}
	}

	return false;
}