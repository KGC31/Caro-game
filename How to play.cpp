#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

#define ESC 27	

void Set_Color(int color);

void Gotoxy(short x, short y);

void ShowCur(bool CursorVisibility);

int mainMenu(int text);

int How_to_play(int text)
{
	system("CHCP 437");
	Set_Color(text);
	//Print how to play title to the console screen
	Gotoxy(13, 1);
	cout << " ____     ____  ____________  _____   _____   _____     ____________  ____________     ____________  ____          ____________   ___    ___ ";
	Gotoxy(13, 2);
	cout << "|    |   |    ||    ____    |" << char(92) << "     " << char(92) << "_/     " << char(92) << "_/     /   |            ||    ____    |   |       __   ||    |        |     __     | " << char(92) << "   " << char(92) << "  /   /";
	Gotoxy(13, 3);
	cout << "|    |___|    ||   |    |   | " << char(92) << "                   /    |___      ___||   |    |   |   |      |__|  ||    |        |    |__|    |  " << char(92) << "   " << char(92) << "/   /";
	Gotoxy(13, 4);
	cout << "|             ||   |    |   |  " << char(92) << "                 /         |    |    |   |    |   |   |       _____||    |        |    ____    |   " << char(92) << "      / ";
	Gotoxy(13, 5);
	cout << "|     ___     ||   |    |   |   " << char(92) << "       _       /          |    |    |   |    |   |   |      |      |    |_______ |   |    |   |    |    |";
	Gotoxy(13, 6);
	cout << "|    |   |    ||   |____|   |    " << char(92) << "     / " << char(92) << "     /           |    |    |   |____|   |   |      |      |            ||   |    |   |    |    |";
	Gotoxy(13, 7);
	cout << "|____|   |____||____________|     " << char(92) << "___/   " << char(92) << "___/            |____|    |____________|   |______|      |____________||___|    |___|    |____| ";

	//How to move cursor
	Gotoxy(77, 10);
	cout << "HOW TO MOVE";
	Gotoxy(67, 11);
	cout << "------------------------------";
	Gotoxy(72, 12);
	cout << "Press "<< char(25) << " to move down";
	Gotoxy(73, 13);
	cout << "Press " << char(24) << " to move up";
	Gotoxy(72, 14);
	cout << "Press " << char(26) << " to move right";
	Gotoxy(73, 15);
	cout << "Press " << char(27) << " to move left";

	//How to win
	Gotoxy(77, 18);
	cout << "HOW TO WIN";
	Gotoxy(67, 19);
	cout << "------------------------------";
	Gotoxy(54, 20);
	cout << "In 3x3 mode, you need to get 3 straight to win or at least";
	Gotoxy(54, 21);
	cout << "tie with other player.";
	Gotoxy(54, 22);
	cout << "In 5x5 mode, it's gonna need more than that. You'll need to";
	Gotoxy(54, 23);
	cout << "have 5 straight to beat the other one.";

	char key;
	do
	{
		key = _getch();
	} while (key != ESC);
	system("cls");
		return mainMenu(text); 
}