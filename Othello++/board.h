#include <stdio.h>
#include <Windows.h>
#include <iomanip>

#define EMPTY 0
#define BLACK 1
#define WHITE 2

// 보드판 초기 설정
void initBoard(int board[][8])
{
	// 배열 초기화
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++)
			board[y][x] = EMPTY;

	// 흑돌과 백돌 교차 후 시작
	board[3][3] = WHITE; board[3][4] = BLACK;
	board[4][3] = BLACK; board[4][4] = WHITE;
}

// 돌 개수 카운트
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

// 보드판 출력
void PrintBoard(int board[][8], int myColor, int turn, int cursorX, int cursorY, std::string notification)
{
	system("cls");	
	std::cout << "┏━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┳━━━┓\n";
	
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			std::cout << "┃ ";

			if (myColor == turn && y == cursorY && x == cursorX)
			{
				std::cout << (myColor == BLACK ? "◇" : "◆");
			}
			else
			{
				switch (board[y][x])
				{
				case EMPTY:
					std::cout << "　";
					break;

				case BLACK:
					std::cout << "○";
					break;

				case WHITE:
					std::cout << "●";
					break;
				}
			}
		}
		
		std::cout << "┃\n";
		
		if (y != 7)
		{
			std::cout << "┣━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━╋━━━┫\n";
		}
	}
	
	std::cout << "┗━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┻━━━┛\n";
	
	// 돌 개수 출력
	
	int whitePieceCount, blackPieceCount;
	CountPiece(board, &blackPieceCount, &whitePieceCount);
	
	if (turn == BLACK)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

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
			if (board[y + yDirection][x + xDirection] == opponentColor)
			{
				int tempX = x;
				int tempY = y;

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

// 돌을 놓을 수 있는 곳이 있는 지 확인
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

// 돌 배치 후 뒤집기
void placePiece(int board[][8], int myColor, int x, int y)
{
	int opponentColor; // 뒤집힐 상대

	if (myColor == BLACK)
	{
		opponentColor = WHITE;
	}
	else {
		opponentColor = BLACK;
	}

	board[y][x] = myColor; // 돌 배치

	// 방향 별로 뒤집을 수 있는 돌이 있는지 검사 후 뒤집기
	for (int xDirection = -1; xDirection <= 1; xDirection++)
	{
		for (int yDirection = -1; yDirection <= 1; yDirection++)
		{
			if (xDirection == 0 && yDirection == 0)
			{
				continue;
			}

			// 검사하려는 방향에 상대 돌이 있을 경우 검사 시작
			if (board[y + yDirection][x + xDirection] == opponentColor)
			{
				int tempX = x;
				int tempY = y;

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
					if (board[tempY][tempX] == myColor)
					{
						// 검사한 방향을 반대로 되돌아가 돌 뒤집기
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