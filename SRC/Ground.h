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

        //Constructor:
        Ground(){system("cls");     system("color 04");}

        //Methods:

        //The Ground Drawer:
        void DrawGround(bool flag);

        //The Methods shows Game Status:
        void ShowInfos(int , int , int, int);

        //This method when a player wins that run:
        void WinMenu(string Winner);

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

        //Draw Helps::
        Methods::SetTextColor(2);   Methods::SetCursor(Horizontal_Start, Highet + Vertical_Start + 6);
        cout << "W -> UP Player1 | S -> Down Player1 | U -> Up Player2 | J -> Down Player2 | CTRL -> exit from game";
    }

    else
    {
        system("cls");
    }
    return;
}


void Ground::ShowInfos(int Player1HP,    int Player2HP,  int ScorePlayer1, int ScorePlayer2)
{
    int HighetShowInfos = Highet + Vertical_Start + 3;

    Methods::SetCursor(Horizontal_Start, HighetShowInfos);
    for(int Counter = 0 ; Counter < Width - 10 ; Counter ++){cout << ' ';}

    Methods::SetCursor(Horizontal_Start, HighetShowInfos);

    Methods::SetTextColor(6);

    cout << "Player1 HP:";    for(int counter = 0 ; counter < Player1HP ; counter ++){cout << (char)3 << ' ';}
    cout << "\t\tScore Player1:" << ScorePlayer1 << "\t\t" << "Score Player2:" << ScorePlayer2;
    cout << "\t\t";
    cout << "Player2 HP:";  for(int Counter = 0 ; Counter < Player2HP ; Counter++){cout << (char)3 << ' ';}

    return;
}


void Ground::WinMenu(string Winner)
{

    //Clear Screen              Set Color                              Set Text Color:
    system("cls");     system("color 10");          Methods::SetTextColor(24);

    for(int HCounter = 0 ; HCounter < 10 ; HCounter ++)
    {
        for(int WCounter = 0 ; WCounter < 67 ; WCounter++)
        {
            Methods::SetCursor(WCounter + 45, HCounter + 15);

            if(WCounter > 64 || HCounter > 8){Methods::SetTextColor(16);}

            else{Methods::SetTextColor(24);}

            cout << (char)219;
        }
    }

    //Beep:

    Beep(300, 200);

    //Print Texts:
    Methods::SetTextColor(128);

    Methods::SetCursor(64, 16);     cout << Winner << " is Win!";
    Methods::SetCursor(47, 18);     cout << "Winner Winner Chicken enar!";
    Methods::SetCursor(47, 20);     cout << "1 --> Exit from Game:";
    Methods::SetCursor(47, 21);           system("pause");

    return;
}

#endif
