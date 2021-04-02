#include <stdio.h>
#include <Windows.h>
#include <iomanip>

int turn;
int board[8][8];

#define EMPTY 0
#define BLACK 1
#define WHITE 2

void initBoard()
{
	// �迭 �ʱ�ȭ
	for (int row = 0; row < 8; row++)
		for (int column = 0; column < 8; column++)
			board[row][column] = EMPTY;

	// �浹�� �鵹 ���� �� ����
	board[3][3] = WHITE; board[3][4] = BLACK;
	board[4][3] = BLACK; board[4][4] = WHITE;
}

// ������ ���
void PrintBoard()
{
	std::string piece[8][8]; // �� ��¿� �迭

	// ������ �˻� �� �迭�� �� or ���� ����
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			switch (board[row][column])
			{
			case 0:
				piece[row][column] = "��";
				break;

			case 1:
				piece[row][column] = "��";
				break;

			case 2:
				piece[row][column] = "��";
				break;
			}
		}
	}

	system("cls");
	
	std::cout << "������������������������������������������������������������������\n";
	
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			std::cout << "�� " << piece[row][column];
		}
		
		std::cout << "��\n";
		
		if (row != 7)
		{
			std::cout << "������������������������������������������������������������������\n";
		}
	}
	
	std::cout << "������������������������������������������������������������������\n";

	int whitePieceCount = 0, blackPieceCount = 0; // �� ����

	// �� ���� ī��Ʈ
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			switch (board[row][column])
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

	std::cout << "�������� �� ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
	std::cout << std::setfill('0') << std::setw(2) << blackPieceCount << " vs " << std::setfill('0') << std::setw(2) << whitePieceCount;

	if (turn == WHITE)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << " ��";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	return;

}