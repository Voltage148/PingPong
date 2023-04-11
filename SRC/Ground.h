/*
    Ground.h: This file can control ground buffer and draw, process and show the PlayGround:
*/
#ifndef GROUND_H
#define GROUND_H

//Import Headers:
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "NeededMethods.h"

using namespace std;

//Start Class:

class Ground
{
    public:

        int HighetCopy = Highet + Vertical_Start + Highet_Thickness;    int WidthCopy = Width + Horizontal_Start + Width_Thickness;

        //Constructor:
        Ground(){system("cls");     system("color 04");}

        //Methods:

        //The Ground Drawer:
        void DrawGround(bool flag);

        //The Methods shows Game Status:
        void ShowInfos(int HP, int Movements);

        //When You lose, this method loaded:
        void LoseAndWinMenu(int, int, int, bool*, string);

        //When you win the game, this method shows the menu:
        void WinMenu(int ,int ,int);

    private:

        //Ground Specifications:

        int Width = 117;    int Highet = 29;    int Width_Thickness = 3; int Highet_Thickness = 5;

        int Horizontal_Start = 25;   int Vertical_Start = 7;

};


//The Body of Methods zone:

void Ground::DrawGround(bool flag  = true)
{
    if(flag == true)
    {
        for (int Highet_Counter = 0; Highet_Counter < Highet; Highet_Counter++) {

            for (int Width_Counter = 0; Width_Counter < Width; Width_Counter++) {
                Methods::SetCursor(Horizontal_Start + Width_Counter, Vertical_Start + Highet_Counter);

                if (Width_Counter >= Highet_Thickness - 1 && Width_Counter <= Width - Highet_Thickness) {
                    if (Highet_Counter >= Width_Thickness - 1 && Highet_Counter <= Highet - Width_Thickness) {
                        cout << ' ';
                    } else {
                        cout << (char) 219;
                    }
                } else {
                    cout << (char) 219;
                }
            }

        }
    }

    else
    {
        system("cls");
    }
    return;
}


void Ground::ShowInfos(int HP, int Movements)
{
    int HighetShowInfos = Highet + Vertical_Start + 3;

    Methods::SetCursor(Horizontal_Start, HighetShowInfos);
    for(int Counter = 0 ; Counter < Width - 10 ; Counter ++){cout << ' ';}

    Methods::SetCursor(Horizontal_Start, HighetShowInfos);

    Methods::SetTextColor(6);

    cout << "HP:";    for(int counter = 0 ; counter < HP ; counter ++){cout << (char)3 << ' ';}
    cout << "\t\tTime:";
    cout << "\t\tMovement:" << Movements;
    cout << "\t\tPlayer VS Computer";

    return;
}

void Ground::LoseAndWinMenu(int Time, int Movements, int Score, bool *Game, string EndText)
{
    //Clear the Screen:
    system("cls");
    Methods::SetTextColor(3);

    int BoxWidth = 47;      int BoxHighet = 12;

    for(int H_Counter = 0 ; H_Counter < BoxHighet ; H_Counter ++)
    {

        for(int W_Counter = 0 ; W_Counter < BoxWidth ; W_Counter ++)
        {
            Methods::SetCursor(60 + W_Counter  ,   10 + H_Counter);

            if(W_Counter >= 2-1   &&  W_Counter <= BoxWidth - 2)
            {
                if(H_Counter >= 2-1   &&  H_Counter <= BoxHighet - 2){cout << ' ';}

                else{cout << (char)219;}
            }
            else{cout << (char)219;}
        }
    }

    Methods::SetTextColor(7);       Methods::SetCursor(80, 11);     cout << EndText;
    Methods::SetTextColor(2);       Methods::SetCursor(62, 13);     cout << "Score:" << Score << "\t\t" << "Move:" << Movements << "\t\t" << "Time : " << Time;
    Methods::SetTextColor(5);       Methods::SetCursor(62, 15);     cout << "1 -> Play Again Game";
    Methods::SetCursor(62, 17);            cout << "2 -> Exit From Game";

    Methods::SetTextColor(7);   Methods::SetCursor(1, 20);      cout << "Input:";   char Get = 'N' ;    cin >> Get;

    switch(Get)
    {
        case '1':
        case '!':
            *Game = true;
            break;

        case '2':
        case '@':
            system("cls && color && exit");
            Methods::FullScreen(false);
            return;
            break;
    }

    return;
}


#endif
