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

    void HideScrollBar(bool);
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

void Methods::HideScrollBar(bool flag = true)
{
    if(flag == true)
    {
        CONSOLE_SCREEN_BUFFER_INFO screenBufferInfo;

        // Get console handle and get screen buffer information from that handle.
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        GetConsoleScreenBufferInfo(hConsole, &screenBufferInfo);

        // Get rid of the scrollbar by setting the screen buffer size the same as
        // the console window size.
        COORD new_screen_buffer_size;

        // screenBufferInfo.srWindow allows us to obtain the width and height info
        // of the visible console in character cells.
        // That visible portion is what we want to set the screen buffer to, so that
        // no scroll bars are needed to view the entire buffer.
        new_screen_buffer_size.X = screenBufferInfo.srWindow.Right -
                                   screenBufferInfo.srWindow.Left + 1; // Columns
        new_screen_buffer_size.Y = screenBufferInfo.srWindow.Bottom -
                                   screenBufferInfo.srWindow.Top + 1; // Rows

        // Set new buffer size
        SetConsoleScreenBufferSize(hConsole, new_screen_buffer_size);
    }
    return;
}
#endif