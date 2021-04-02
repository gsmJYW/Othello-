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
	// 배열 초기화
	for (int row = 0; row < 8; row++)
		for (int column = 0; column < 8; column++)
			board[row][column] = EMPTY;

	// 흑돌과 백돌 교차 후 시작
	board[3][3] = WHITE; board[3][4] = BLACK;
	board[4][3] = BLACK; board[4][4] = WHITE;
}

// 보드판 출력
void PrintBoard()
{
	std::string piece[8][8]; // 돌 출력용 배열

	// 보드판 검사 후 배열에 돌 or 공백 저장
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			switch (board[row][column])
			{
			case 0:
				piece[row][column] = "　";
				break;

			case 1:
				piece[row][column] = "●";
				break;

			case 2:
				piece[row][column] = "○";
				break;
			}
		}
	}

	system("cls");
	
	std::cout << "┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n";
	
	for (int row = 0; row < 8; row++)
	{
		for (int column = 0; column < 8; column++)
		{
			std::cout << "┃ " << piece[row][column];
		}
		
		std::cout << "┃\n";
		
		if (row != 7)
		{
			std::cout << "┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n";
		}
	}
	
	std::cout << "┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n";

	int whitePieceCount = 0, blackPieceCount = 0; // 돌 개수

	// 돌 개수 카운트
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

	// 돌 개수 출력
	
	if (turn == BLACK)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "　　　　 흑 ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
	std::cout << std::setfill('0') << std::setw(2) << blackPieceCount << " vs " << std::setfill('0') << std::setw(2) << whitePieceCount;

	if (turn == WHITE)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << " 백";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	return;

}