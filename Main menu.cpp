#pragma warning(disable : 4996)
#pragma comment(lib,"winmm.lib")
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<mmsystem.h>

using namespace std;

#define LIGHT_GREEN 2
#define WHITE 7

#define UP 72
#define DOWN 80
#define ENTER 13

int music = 1;

void Set_Color(int color);

void Gotoxy(short x, short y);

void ShowCur(bool CursorVisibility);

void Gameplay(int text);

int How_to_play(int text);

void mainSettings(int& text, int& theme, int& music);

//This function is used to print TIC TAC TOE text to screen
void Logo(int text)
{
	Set_Color(text);
	Gotoxy(18, 2);
	cout << " ____________  ____________  ____________     ____________  ____________  ____________     ____________  ____________  ____________";
	Gotoxy(18, 3);
	cout << "|            ||___      ___||            |   |            ||     __     ||            |   |            ||    ____    ||       _____|";
	Gotoxy(18, 4);
	cout << "|____    ____|    |    |    |      ______|   |____    ____||    |__|    ||      ______|   |____    ____||   |    |   ||      |_____ ";
	Gotoxy(18, 5);
	cout << "    |    |        |    |    |     |              |    |    |     __     ||     |              |    |    |   |    |   ||       _____|";
	Gotoxy(18, 6);
	cout << "    |    |        |    |    |     |______        |    |    |    |  |    ||     |______        |    |    |   |    |   ||      |_____";
	Gotoxy(18, 7);
	cout << "    |    |     ___|    |___ |            |       |    |    |    |  |    ||            |       |    |    |   |____|   ||            |";
	Gotoxy(18, 8);
	cout << "    |____|    |____________||____________|       |____|    |____|  |____||____________|       |____|    |____________||____________|";
}

//This function is used to get keyboard events
int Menu(int text)
{
    int Set[] = { text, abs(text - 7), abs(text - 7), abs(text - 7) };
    int counter = 1;
    char key;
    //38
    //Print menu choices
    Gotoxy(79, 15);
    Set_Color(text);
    cout << "Play game";

    Gotoxy(78, 16);
    Set_Color(text);
    cout << "How to play";

    Gotoxy(79, 17);
    Set_Color(text);
    cout << "Settings";

    Gotoxy(81, 18);
    Set_Color(text);
    cout << "Exit";

    //Print corners
    Set_Color(text);
    Gotoxy(95, 13);
    cout << char(187);
    Gotoxy(71, 13);
    cout << char(201);
    Gotoxy(95, 20);
    cout << char(188);
    Gotoxy(71, 20);
    cout << char(200);

    //print horizontal lines
    for (int i = 0; i < 23; i++)
    {
        Gotoxy(72 + i, 13);
        cout << char(205);
        Gotoxy(72 + i, 20);
        cout << char(205);
    }

    //Print vertical lines
    for (int i = 0; i < 6; i++)
    {
        Gotoxy(71, 14 + i);
        cout << char(186);
        Gotoxy(95, 14 + i);
        cout << char(186);
    }

    //Get keyboard events
    for (int i = 0; ; )
    {
        Set_Color(Set[0]);
        Gotoxy(77, 15);
        cout << ">";
        Gotoxy(89, 15);
        cout << "<";

        Set_Color(Set[1]);
        Gotoxy(76, 16);
        cout << ">";
        Gotoxy(90, 16);
        cout << "<";

        Set_Color(Set[2]);
        Gotoxy(77, 17);
        cout << ">";
        Gotoxy(88, 17);
        cout << "<";

        Set_Color(Set[3]);
        Gotoxy(79, 18);
        cout << ">";
        Gotoxy(86, 18);
        cout << "<";


        key = getch();

        if (key == UP && counter >= 2 && counter <= 4)
        {
            counter--;
        }

        if (key == DOWN && counter >= 1 && counter <= 3)
        {
            counter++;
        }

        Set[0] = text;
        Set[1] = WHITE;
        Set[2] = WHITE;
        Set[3] = WHITE;

        if (counter != 1)
        {
            for (int i = 0; i < 4; i++)
                Set[i] = abs(text - 7);
        }
        if (counter == 1)
        {
            Set[0] = text;
            for (int i = 1; i < 4; i++)
                Set[i] = abs(text - 7);
        }
        if (counter == 2)
            Set[1] = text;
        if (counter == 3)
            Set[2] = text;
        if (counter == 4)
            Set[3] = text;

        if (key == '\r') //Enter key (choose)
        {
            if (counter == 1)
            {
                system("cls");
                return 1;
            }
            if (counter == 2)
            {
                system("cls");
                return 2;
            }
            if (counter == 3)
            {
                system("cls");
                return 3;
            }
            if (counter == 4)
            {
                system("cls");
                return 4;
            }
        }
    }
    return 0;
}



//This funtion is the main function for Menu
int mainMenu(int text)
{
    int theme = abs(text - 7);
    ShowCur(0);


    //Play sound or not
    if(music == 0)
        PlaySound(NULL, NULL, SND_ASYNC | SND_LOOP);

	//Print TIC TAC TOE logo to screen and print menu board
	Logo(text);

	//Get keyboard events and return value for next mode 
	switch (Menu(text))
	{
	case 1:
        system("cls");
        //Input_players_name(player_1, player_2);
		Gameplay(text);
        break;
    case 2:
        How_to_play(text);
        break;
    case 3:
        mainSettings(text, theme, music);
        return mainMenu(text);
	case 4:
		exit(0);
	}

	return 0;
}

