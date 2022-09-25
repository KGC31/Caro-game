#pragma comment(lib,"winmm.lib")
#include<iostream>
#include<windows.h>
#include<stdio.h>
#include<WinUser.h>
#include<mmsystem.h>

using namespace std;

void Set_Color(int color);

void Gotoxy(short x, short y);

void ShowCur(bool CursorVisibility);

void DisableResizeWindow();

void SetScreenBufferSize(SHORT width, SHORT height);

void DisableSelection();

void Animation_Loading(int text)
{
    int x, y;
    x = 45, y = 18;
    Gotoxy(x, y);
    Set_Color(text);
    cout << char(218);
    for (int i = 1; i <= 80; i++) cout << char(196);
    cout << char(191);
    Gotoxy(x, y + 1);
    cout << char(179);
    for (int i = 1; i <= 80; i++) cout << " ";
    cout << char(179);
    Gotoxy(x, y + 2);
    cout << char(192);
    for (int i = 1; i <= 80; i++) cout << char(196);
    cout << char(217);
    Set_Color(text);

    Set_Color(text);
    Gotoxy(x + 1, y + 3);
    for (int i = 1; i <= 80; i++)
    {
        if (i == 1)
        {
            Gotoxy(x + 86, y + 1);
            cout << "%";
            Gotoxy(x + 31, y + 3);
            cout << ". . . LOADING . . .";
            Gotoxy(x + 1, y + 1);
        }
        cout << char(219);
        Gotoxy(x + 83, y + 1);
        cout << i + 20;
        Gotoxy(i + x + 1, y + 1);
        if (i + 20 == 100)
        {
            Gotoxy(x + 31, y + 3);
            Set_Color(text);
            cout << ". . . COMPLETE . . .";
            Set_Color(text);
        }
        Sleep(40);
    }
    Gotoxy(x + 87, y + 1);
    Sleep(3000);
    system("cls");
}

int mainMenu(int text);

int main()
{
    //Console set-ups
    //Hide cursor
    ShowCur(0);

    //Disable resize and selection
    DisableResizeWindow();
    DisableSelection();
 
    //Set console screen to max size
    system("mode 650");
    system("mode con COLS=700");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

    //Set console buffer size
    SetScreenBufferSize(44, 168);

    //Set console color
    system("color 0f");

    //Hide scroll bars
    ShowScrollBar(GetConsoleWindow(), SB_BOTH, 0);

    SetConsoleTitle(L"Tic Tac Toe");

    //Default theme for game
    int text = 7, theme = 0;

    Animation_Loading(text);
    PlaySound(TEXT("TTT.wav"), NULL, SND_ASYNC | SND_LOOP);
    mainMenu(text);

    exit(0);
}