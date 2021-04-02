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
	// 배열 초기화
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++)
			board[y][x] = EMPTY;

	// 흑돌과 백돌 교차 후 시작
	board[3][3] = WHITE; board[3][4] = BLACK;
	board[4][3] = BLACK; board[4][4] = WHITE;
}

// 보드판 출력
void PrintBoard()
{
	std::string piece[8][8]; // 돌 출력용 배열

	// 보드판 검사 후 배열에 돌 or 공백 저장
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (myColor == turn && y == cursorY && x == cursorX)
			{
				piece[y][x] = (myColor == BLACK ? "◇" : "◆");
			}
			else
			{
				switch (board[y][x])
				{
				case EMPTY:
					piece[y][x] = "　";
					break;

				case BLACK:
					piece[y][x] = "○";
					break;

				case WHITE:
					piece[y][x] = "●";
					break;
				}
			}
		}
	}

	system("cls");
	
	std::cout << "┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n";
	
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			std::cout << "┃ " << piece[y][x];
		}
		
		std::cout << "┃\n";
		
		if (y != 7)
		{
			std::cout << "┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n";
		}
	}
	
	std::cout << "┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n";

	int whitePieceCount = 0, blackPieceCount = 0; // 돌 개수

	// 돌 개수 카운트
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

	// 돌 개수 출력
	
	if (turn == BLACK)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	// "　　　　　"

	std::cout << " 흑 ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
	std::cout << std::setfill('0') << std::setw(2) << blackPieceCount << " vs " << std::setfill('0') << std::setw(2) << whitePieceCount;

	if (turn == WHITE)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << " 백\n ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	std::cout << notification;

	return;

}

// 돌을 놓을 수 있는 위치인 지 체크
bool isAbleToPlace(int x, int y)
{
	int waiting; // 기다리고 있는 사람(뒤집힐 상대)

	if (turn == BLACK)
	{
		waiting = WHITE;
	}
	else {
		waiting = BLACK;
	}

	// 빈 공간이 아닌 경우 돌을 놓을 수 없음
	if (board[y][x] != EMPTY) return false;

	// 방향 별로 뒤집을 수 있는 돌이 있는지 검사
	for (int xDirection = -1; xDirection <= 1; xDirection++)
	{
		for (int yDirection = -1; yDirection <= 1; yDirection++)
		{
			if (xDirection == 0 && yDirection == 0)
			{
				continue;
			}

			// 검사하려는 방향에 상대 돌이 있을 경우 검사 시작
			if (board[y + yDirection][x + xDirection] == waiting)
			{
				int tempX = cursorX;
				int tempY = cursorY;

				while (true)
				{
					// 검사할 방향으로 한 칸씩 나아가며 검사
					tempX += xDirection;
					tempY += yDirection;

					// 보드판을 넘어가면 뒤집을 수 없음
					if (tempX < 0 || tempX > 7 || tempY < 0 || tempY > 7)
					{
						break;
					}

					// 빈공간이 있으면 뒤집을 수 없음
					if (board[tempY][tempX] == EMPTY)
					{
						break;
					}

					// 내 돌이 있으면 뒤집을 수 있음
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