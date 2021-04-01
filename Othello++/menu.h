#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "connection.h"

#define BLACK 1
#define WHITE 2

// ·Î°í Ãâ·Â
void PrintLogo()
{
	std::cout << "¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n"
		<< "¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¡¡¡¡¡¡¦­\n"
		<< "¦­¡¡¡¡¡á¡á¡á¡¡¡¡¡á¡á¡á¡á¡á¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡á¡á¡á¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¦­¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡ ¦­\n"
		<< "¦­¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡ ¦­\n"
		<< "¦­¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡á¡á¡á¡á¡¡¡á¡á¡á¡á¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡á¡á¡á¡á¡¡¡á¡á¡á¡á¡á ¦­\n"
		<< "¦­¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡ ¦­\n"
		<< "¦­¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡ ¦­\n"
		<< "¦­¡¡¡¡¡á¡á¡á¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡¡¡¡¡á¡¡¡á¡á¡á¡á¡á¡¡¡á¡á¡á¡á¡á¡¡¡á¡á¡á¡á¡á¡¡¡¡¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¡¡¡¡¡¡¦­\n"
		<< "¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n\n\n";
}

// ½ÃÀÛ ¸Þ´º Ãâ·Â
void PrintStartMenu(int menu)
{
	system("cls");
	PrintLogo();

	// ¸Þ´º Ãâ·Â

	if (menu == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡  ¡¡½ÃÀÛ¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	if (menu == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡  ¡¡¼³¸í¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	if (menu == 3)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡  ¡¡Á¾·á¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// ¼³¸í Ãâ·Â
int Help()
{
	system("cls");
	PrintLogo();

	std::cout << "\n\n\n Å°º¸µå ¹æÇâÅ°·Î º¸µåÆÇÀÇ Ä¿¼­(¡á¡à)¸¦ ÀÌµ¿½ÃÅ³ ¼ö ÀÖ½À´Ï´Ù.\n"
		<< " ¿£ÅÍ¸¦ ÀÔ·ÂÇÏ¸é Ä¿¼­°¡ ÀÖ´Â À§Ä¡¿¡ µ¹(¡Ü¡Û)À» ³õ½À´Ï´Ù.\n"
		<< " ¸¸¾à µ¹À» ³õÀ» ¼ö ÀÖ´Â °÷ÀÌ ¾ø´Ù¸é ÀÚµ¿À¸·Î ÅÏÀÌ ³Ñ°ÜÁý´Ï´Ù.\n"
		<< " ÈæÀÌ ¼±°ø, ¹éÀÌ ÈÄ°øÀÌ¸ç Èæ¹é ¼±ÅÃÀº ¼±Âø¼øÀÔ´Ï´Ù.\n"
		<< " ÀÌ ¿ÜÀÇ ·êÀº º¸µå°ÔÀÓ ¿Àµ¨·Î¿Í °°½À´Ï´Ù.\n\n"
		<< " È®ÀÎ <¦°";

	// ¿£ÅÍ ÀÔ·Â ½Ã Á¾·á
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

// ½ÃÀÛ ¸Þ´º
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
			
			// À§ÂÊ ¸Þ´º·Î ÀÌµ¿
			case 72:
				if (menu > 1)
				{
					menu--;
					PrintStartMenu(menu);
				}
				break;

			// ¾Æ·¡ÂÊ ¸Þ´º·Î ÀÌµ¿
			case 80:
				if (menu < 3)
				{
					menu++;
					PrintStartMenu(menu);
				}
				break;

			// ¸Þ´º ¼±ÅÃ
			case 13:
				switch (menu) {
				// ½ÃÀÛ
				case 1:
					return 3; // ¿¬°á ¸Þ´º·Î ÀÌµ¿

				// ¼³¸í
				case 2:
					return 2; // ¼³¸íÀ¸·Î ÀÌµ¿
					break;

				// Á¾·á
				case 3:
					return 0;
				}
			}
		}
	}
}

// ½ÃÀÛ ¸Þ´º Ãâ·Â
void PrintConnectionMenu(int menu)
{
	system("cls");
	PrintLogo();

	// ¸Þ´º Ãâ·Â

	if (menu == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡  °ÔÀÓ ¿­±â¡¡¡¡¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	if (menu == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡°ÔÀÓ Âü¿©ÇÏ±â¡¡¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	if (menu == 3)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡  ¡¡Ãë¼Ò¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// ¿¬°á ¼³Á¤ ¸Þ´º
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
		std::cout << " °ÔÀÓ »ý¼º ½ÇÆÐ\n"
			<< " È®ÀÎ <¦°";
		break;

	case 0:
		std::cout << " °ÔÀÓ »ý¼º Áß";
		break;

	case 1:
		std::cout << " °ÔÀÓ »ý¼º ¿Ï·á\n"
			<< " Á¢¼ÓÀÚ¸¦ ±â´Ù¸®´Â Áß";
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
		std::cout << " °ÔÀÓ Á¢¼Ó ½ÇÆÐ\n"
			<< " Á¾·á <¦°";
		break;

	case 0:
		std::cout << " ip ÁÖ¼Ò:\n ";
		break;

	case 1:
		std::cout << " °ÔÀÓ Á¢¼Ó Áß";
		break;
	}
}

void PrintColorMenu(int menu, int color, int opponentColor)
{
	system("cls");
	PrintLogo();

	std::cout << "\n¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¡ØÈæÀÌ ¼±°øÀÔ´Ï´Ù\n\n\n";

	// ¸Þ´º Ãâ·Â

	if (menu == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡  ¡¡ Èæ¡¡¡¡¡¡¡¡¦­ "
		<< (color == 1 ? "³»°¡ ¼±ÅÃÇÔ" : (opponentColor == 1 ? "»ó´ë°¡ ¼±ÅÃÇÔ" : ""))
		<< "\n¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	if (menu == 2)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	}

	std::cout << "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡ ¹é¡¡¡¡¡¡¡¡¦­ "
		<< (color == 2 ? "³»°¡ ¼±ÅÃÇÔ" : (opponentColor == 2 ? "»ó´ë°¡ ¼±ÅÃÇÔ" : ""))
		<< "\n¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦­\n"
		<< "¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

// Èæ¹é ¼±ÅÃ ¸Þ´º
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

				// À§ÂÊ ¸Þ´º·Î ÀÌµ¿
			case 72:
				if (menu > 1)
				{
					menu--;
					PrintColorMenu(menu, color, opponentColor);
				}
				break;

				// ¾Æ·¡ÂÊ ¸Þ´º·Î ÀÌµ¿
			case 80:
				if (menu < 2)
				{
					menu++;
					PrintColorMenu(menu, color, opponentColor);
				}
				break;

				// ¸Þ´º ¼±ÅÃ
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