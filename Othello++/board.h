#include <stdio.h>
#include <Windows.h>
#include <iomanip>

#define EMPTY 0
#define BLACK 1
#define WHITE 2

// ������ �ʱ� ����
void initBoard(int board[][8])
{
	// �迭 �ʱ�ȭ
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++)
			board[y][x] = EMPTY;

	// �浹�� �鵹 ���� �� ����
	board[3][3] = WHITE; board[3][4] = BLACK;
	board[4][3] = BLACK; board[4][4] = WHITE;
}

// �� ���� ī��Ʈ
void CountPiece(int board[][8], int* blackPieceCount, int* whitePieceCount)
{
	*blackPieceCount = 0;
	*whitePieceCount = 0;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			switch (board[y][x])
			{
			case BLACK:
				(*blackPieceCount)++;
				break;

			case WHITE:
				(*whitePieceCount)++;
				break;
			}
		}
	}
}

// ������ ���
void PrintBoard(int board[][8], int myColor, int turn, int cursorX, int cursorY, std::string notification)
{
	system("cls");	
	std::cout << "������������������������������������������������������������������\n";
	
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			std::cout << "�� ";

			if (myColor == turn && y == cursorY && x == cursorX)
			{
				std::cout << (myColor == BLACK ? "��" : "��");
			}
			else
			{
				switch (board[y][x])
				{
				case EMPTY:
					std::cout << "��";
					break;

				case BLACK:
					std::cout << "��";
					break;

				case WHITE:
					std::cout << "��";
					break;
				}
			}
		}
		
		std::cout << "��\n";
		
		if (y != 7)
		{
			std::cout << "������������������������������������������������������������������\n";
		}
	}
	
	std::cout << "������������������������������������������������������������������\n";
	
	// �� ���� ���
	
	int whitePieceCount, blackPieceCount;
	CountPiece(board, &blackPieceCount, &whitePieceCount);
	
	if (turn == BLACK)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

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
bool isAvailable(int board[][8], int myColor, int x, int y)
{
	int opponentColor;

	if (myColor == BLACK)
	{
		opponentColor = WHITE;
	}
	else {
		opponentColor = BLACK;
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
			if (board[y + yDirection][x + xDirection] == opponentColor)
			{
				int tempX = x;
				int tempY = y;

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
					if (board[tempY][tempX] == myColor)
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

// ���� ���� �� �ִ� ���� �ִ� �� Ȯ��
bool isThereAvailablePlace(int board[][8], int myColor)
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (isAvailable(board, myColor, x, y))
			{
				return true;
			}
		}
	}

	return false;
}

// �� ��ġ �� ������
void placePiece(int board[][8], int myColor, int x, int y)
{
	int opponentColor; // ������ ���

	if (myColor == BLACK)
	{
		opponentColor = WHITE;
	}
	else {
		opponentColor = BLACK;
	}

	board[y][x] = myColor; // �� ��ġ

	// ���� ���� ������ �� �ִ� ���� �ִ��� �˻� �� ������
	for (int xDirection = -1; xDirection <= 1; xDirection++)
	{
		for (int yDirection = -1; yDirection <= 1; yDirection++)
		{
			if (xDirection == 0 && yDirection == 0)
			{
				continue;
			}

			// �˻��Ϸ��� ���⿡ ��� ���� ���� ��� �˻� ����
			if (board[y + yDirection][x + xDirection] == opponentColor)
			{
				int tempX = x;
				int tempY = y;

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
					if (board[tempY][tempX] == myColor)
					{
						// �˻��� ������ �ݴ�� �ǵ��ư� �� ������
						while (x != tempX || y != tempY)
						{
							board[tempY][tempX] = myColor;

							tempX -= xDirection;
							tempY -= yDirection;
						}

						break;
					}
				}
			}
		}
	}
}