#pragma warning(disable : 4996)
#pragma comment(lib,"winmm.lib")
#include<iostream>
#include<conio.h>
#include<cmath>
#include<windows.h>
#include<mmsystem.h>

using namespace std;

//Definitions of keyboard events
#define DOWN 80
#define UP 72
#define ESC 27
#define ENTER 13

//Definitions of color 
#define WHITE 7
#define BLACK 0

//Definitions of music mode
#define ON 1
#define OFF 0

void ShowCur(bool CursorVisibility); 

void Set_Color(int color);

void Gotoxy(short x, short y);

//This funcion is used to print SETTINGS text
void printSettings(int text)
{
    Set_Color(text);
    Gotoxy(23, 2);
    cout << " ____________   ____________   ____________   ____________   ____________   ____    ____   ____________   ____________";
    Gotoxy(23, 3);
    cout << "|            | |       _____| |            | |            | |___      ___| |    .  |    | |     _______| |            |";
    Gotoxy(23, 4);
    cout << "|      ______| |      |_____  |___      ___| |___      ___|     |    |     |     . |    | |    |  _____  |      ______|";
    Gotoxy(23, 5);
    cout << "|            | |       _____|     |    |         |    |         |    |     |      .|    | |    | |___  | |            |";
    Gotoxy(23, 6);
    cout << "|______      | |      |_____      |    |         |    |         |    |     |    |.      | |    |_____| | |______      |";
    Gotoxy(23, 7);
    cout << "|            | |            |     |    |         |    |      ___|    |___  |    | .     | |            | |            |";
    Gotoxy(23, 8);
    cout << "|____________| |____________|     |____|         |____|     |____________| |____|  .____| |____________| |____________|";
    cout << endl;
}

//This is function for events on settings menu
void settingsMenu(int& text, int& n, int& count, int& theme, int& music)
{
    //Set color for the whole console as chosen mode
    Set_Color(text);

    //Check which theme is set
    Gotoxy(72, 20);
    if (theme == WHITE)
        cout << "Theme mode: light mode";
    else
        cout << "Theme mode: dark mode";

    //Check which music setting is set
    Gotoxy(77, 21);
    if (music == ON)
        cout << "Music: on ";
    else
        cout << "Music: off";

    //Main keyboard events
    char ch;
    do
    {
        //Print to console cursor
        switch (count)
        {
        case 0:
        {
            Set_Color(text);
            Gotoxy(70, 20);
            cout << ">";
            Gotoxy(95, 20);
            cout << "<";

            Set_Color(abs(text - 7));
            Gotoxy(75, 21);
            cout << ">";
            Gotoxy(87, 21);
            cout << "<";
            break;
        }
        case 1:
        {
            Set_Color(abs(text - 7));
            Gotoxy(70, 20);
            cout << ">";
            Gotoxy(95, 20);
            cout << "<";

            Set_Color(text);
            Gotoxy(75, 21);
            cout << ">";
            Gotoxy(87, 21);
            cout << "<";
            break;
        }
        }

        //Get commands from keyboard
        ch = _getch();
        if (ch == DOWN && count < 1)
        {
            count++;
        }
        if (ch == UP && count > 0)
        {
            count--;
        }
        if (ch == ESC)
        {
            system("cls");
            n = 1;
        }

        //If theme mode is chosen 
        if (ch == ENTER && count == 0)
        {
            switch (theme)
            {
            case WHITE:
            {
                theme = BLACK;
                text = WHITE;
                system("cls");
                break;
            }
            case BLACK:
            {
                theme = WHITE;
                text = BLACK;
                system("cls");
                break;
            }
            }
            count = 0;
        }

        //If music setting is changed
        if (ch == ENTER && count == 1)
        {
            switch (music)
            {
            case ON:
                music = OFF;
                PlaySound(NULL, NULL, SND_ASYNC | SND_LOOP);
                break;
            case OFF:
                music = ON;
                PlaySound(TEXT("TTT.wav"), NULL, SND_ASYNC | SND_LOOP);
                break;
            }
        }
    } while (ch != ENTER && ch != ESC);
}

//This is main fucntion for settings menu 
void mainSettings(int& text, int& theme, int& music)
{
    //Count is used to define which setting the cursor is at. count = 0 means the cursor is at Theme mode, count = 1 means the cursor is at music setting
    //n is used as stop condition for settings menu
    int count = 0, n = 0;

    //This function is used to print SETTINGS and control events on settings menu 
    do
    {
        if (theme == WHITE)
        {
            system("color 7f");
            Set_Color(text);
        }
        else
        {
            system("color 0f");
            Set_Color(text);
        }
        printSettings(text);
        settingsMenu(text, n, count, theme, music);
    } while (n != 1);
}