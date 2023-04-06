/*
    This file has the important methods for program:
*/

#ifndef NeededMethods_H   
#define NeededMethods_H

//Import Needed Headers:
#include <windows.h>
#include <winuser.h>
#include <conio.h>

using namespace std;


HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Cursor;

namespace Methods
{

    void FullScreen(bool);
    
    void SetCursor(int, int);

    void SetTextColor(int);

    void HideCursor(bool);
};

void Methods::FullScreen(bool flag = true)
{
    if(flag == true)
    {
        ShowWindow(GetConsoleWindow(),SW_MAXIMIZE);
        SendMessage(GetConsoleWindow(),WM_SYSKEYDOWN,VK_RETURN,0x20000000);
    }
    else
    {
        SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
        system("mode con COLS=200");
    }
    return;
}

void Methods::SetCursor(int x = 0, int y = 0)
{
    Cursor.Y = y;
    Cursor.X = x;
    SetConsoleCursorPosition(Console, Cursor);
    return;
}

void Methods::SetTextColor(int Color_Number = 2)
{
    SetConsoleTextAttribute(Console, Color_Number);
    return;
}

void Methods::HideCursor(bool flag = true)
{

    CONSOLE_CURSOR_INFO CursorInfo;
    HANDLE Data = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleCursorInfo(Data, &CursorInfo);
    CursorInfo.bVisible = flag;
    SetConsoleCursorInfo(Data, &CursorInfo);
    return;
}
#endif