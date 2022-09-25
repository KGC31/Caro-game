#pragma warning(disable : 4996)
#include<fstream>
#include<string>
#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

//Keyboard evens definitions
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define ENTER 13

//Color definitions
#define RED 4
#define BLUE 1

static int _TURN = 1;

bool win_check(int** a, int row, int col);

int mainMenu(int text);

void Set_Color(int color);

void Gotoxy(short x, short y);

void ShowCur(bool CursorVisibility);

//This function is used to print board to the screen
void printBoard(int text)
{
	for (int i = 0; i < 8; i++)
	{
		Set_Color(text);
		Gotoxy(0, 2 + 5 * i);
		cout << " -------  -------  -------  -------  -------  -------  -------  -------  -------  ------- ";
		Gotoxy(0, 3 + 5 * i);
		cout << "|       ||       ||       ||       ||       ||       ||       ||       ||       ||       |";
		Gotoxy(0, 4 + 5 * i);
		cout << "|       ||       ||       ||       ||       ||       ||       ||       ||       ||       |";
		Gotoxy(0, 5 + 5 * i);
		cout << "|       ||       ||       ||       ||       ||       ||       ||       ||       ||       |";
		Gotoxy(0, 6 + 5 * i);
		cout << " -------  -------  -------  -------  -------  -------  -------  -------  -------  ------- ";
	}
}


//This fucntion is used to print side board
void printsideBoard(int text, char* player1, char* player2)
{
	Set_Color(text);
	Gotoxy(93, 0);
	cout << "__________________________________________________________________________";
	Gotoxy(93, 41);
	cout << "__________________________________________________________________________";
	Gotoxy(93, 7);
	cout << "__________________________________________________________________________";

	Set_Color(text);
	for (int i = 1; i <= 41; i++)
	{
		Gotoxy(92, i);
		cout << "|";
		Gotoxy(167, i);
		cout << "|";
	}

	Set_Color(text);
	Gotoxy(108, 3);
	cout << "Player 1";
	Gotoxy(143, 3);
	cout << "Player 2";

	Gotoxy(103, 4);
	cout << player1;
	Gotoxy(138, 4);
	cout << player2;
}

//This function used to print previous move to console screen
void Print_moves(int x, int y, int& _TURN, int countx, int county, int count)
{
	switch (countx)
	{
	case 0:
		Gotoxy(95, county + 8);
		cout << count << ".Player" << _TURN << ": " << "(" << x << ", " << y << ")";
		break;
	case 1:
		Gotoxy(120, county + 8);
		cout << count << ".Player" << _TURN << ": " << "(" << x << ", " << y << ")";
		break;
	case 2:
		Gotoxy(143, county + 8);
		cout << count << ".Player" << _TURN << ": " << "(" << x << ", " << y << ")";
		break;
	}

}
//This functions is used to get keyboard events
void moveCursor(int text, int** board, int& x, int& y, int& _TURN, int& countx, int& county, int& count)
{
	char ch;
	ch = getch();
	if (ch == UP && y > 0)
	{
		y -= 1;
	}

	if (ch == DOWN && y < 7)
	{
		y += 1;
	}

	if (ch == RIGHT && x < 9)
	{
		x += 1;
	}

	if (ch == LEFT && x > 0)
	{
		x -= 1;
	}

	//Print Player 1's moves to console 
	if (ch == ENTER && board[y][x] == 0 && _TURN == 1)
	{
		Set_Color(RED);
		board[y][x] = 1;
		cout << "X";
		_TURN += 1;
		Set_Color(text);
		Print_moves(x, y, _TURN, countx, county, count);
		if (countx < 2)
			countx++;
		else
		{
			countx = 0; county++;
		}
		count++;
	}

	//Print Player 2's moves to console
	if (ch == ENTER && board[y][x] == 0 && _TURN == 2)
	{
		Set_Color(BLUE);
		board[y][x] = 2;
		cout << "O";
		_TURN -= 1;
		Set_Color(text);
		Print_moves(x, y, _TURN, countx, county, count);
		if (countx < 2)
			countx++;
		else
		{
			countx = 0; county++;
		}
		count++;
	}
	
}

//This function is used to print choices when game is finished
int endMenu(int text)
{
	ShowCur(0);
	Set_Color(text);
	Gotoxy(93, 38);
	cout << "__________________________________________________________________________";
	
	//Print choices
	Gotoxy(124, 39);
	cout << "Play again?";

	Gotoxy(102, 40);
	cout << "1. Play again";

	Gotoxy(126, 40);
	cout << "2. Menu";

	Gotoxy(147, 40);
	cout << "3. Exit";

	//Get keyboard events
	char key;
	int count = 1;
	int Set[] = { text, abs(text - 7), abs(text - 7) };
	do {
		Gotoxy(101, 40);
		Set_Color(Set[0]);
		cout << ">";

		Gotoxy(125, 40);
		Set_Color(Set[1]);
		cout << ">";

		Gotoxy(146, 40);
		Set_Color(Set[2]);
		cout << ">";

		key = getch();
		if (key == RIGHT && count <=2)
			count++;
		if (key == LEFT && count >= 2)
			count--;

		Set[0] = abs(text - 7);
		Set[1] = abs(text - 7);
		Set[2] = abs(text - 7);
		if (count == 1)
			Set[0] = text;
		if (count == 2)
			Set[1] = text;
		if (count == 3)
			Set[2] = text;
	} while (key != ENTER);
	return count;
}

//This function is used to enter player's name
void Name(char player1[], char player2[], int text)
{
	system("cls");
	ShowCur(1);
	char key;
	Set_Color(text);

	//Player 1 name board
	Gotoxy(67, 13);
	cout << char(201);
	Gotoxy(99, 13);
	cout << char(187);
	Gotoxy(67, 15);
	cout << char(200);
	Gotoxy(99, 15);
	cout << char(188);
	Gotoxy(67, 14);
	cout << char(186);
	Gotoxy(99, 14);
	cout << char(186);

	Gotoxy(68, 14);
	cout << "Player 1:";

	//Player 2 name board
	Gotoxy(67, 18);
	cout << char(201);
	Gotoxy(99, 18);
	cout << char(187);
	Gotoxy(67, 20);
	cout << char(200);
	Gotoxy(99, 20);
	cout << char(188);
	Gotoxy(67, 19);
	cout << char(186);
	Gotoxy(99, 19);
	cout << char(186);

	Gotoxy(68, 19);
	cout << "Player 2:";

	for (int i = 68; i < 99; i++)
	{
		Gotoxy(i, 13);
		cout << char(205);
		Gotoxy(i, 15);
		cout << char(205);
		Gotoxy(i, 18);
		cout << char(205);
		Gotoxy(i, 20);
		cout << char(205);
	}

	Gotoxy(78, 14);
	cin.getline(player1, 30);
	Gotoxy(78, 19);
	cin.getline(player2, 30);
	system("cls");
	
}

//This is mauin function for gameplay
//Our game board is a 10x8 board
void Gameplay(int text)
{
	int countx = 0, county = 0, count = 1;
	char player1[25], player2[25];
	Name(player1, player2, text);
	ShowCur(1);
	//Initialize board array to store value for checking win condition
	int** board;

	board = new int* [9];
	for (int i = 0; i < 9; i++)
	{
		board[i] = new int[10];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			board[i][j] = 0;
		}
	}

	//Initilize beginning position of cursor
	int x = 0, y = 0;

	//Print gameplay board and information board to the screen
	printBoard(text);
	printsideBoard(text, player1, player2);

	//Main gameplay
	do
	{
		//Print arrow to screen so that players know who's turn it is
		if (_TURN == 1)
		{
			Set_Color(text);
			Gotoxy(112, 2);
			cout << char(25);

			Set_Color(abs(text - 7));
			Gotoxy(147, 2);
			cout << char(25);
		}

		if (_TURN == 2)
		{
			Set_Color(abs(text - 7));
			Gotoxy(112, 2);
			cout << char(25);

			Set_Color(text);
			Gotoxy(147, 2);
			cout << char(25);
		}

		//Print cursor
		Gotoxy(4 + x * 9, 4 + y * 5);

		//Move cursor by keyboard events
		moveCursor(text, board, x, y, _TURN, countx, county, count);
	} while (win_check(board, 9, 10) != true);

	if (_TURN == 2)
		_TURN--;
	else
		_TURN++;
	Gotoxy(123, 37);
	cout << "PLAYER " << _TURN << " WIN!";

	switch (endMenu(text))
	{
	case 1:
		system("cls");
		return Gameplay(text);
	case 2:
		system("cls");
		mainMenu(text);
		break;
	case 3:
		exit(0);
	}
}