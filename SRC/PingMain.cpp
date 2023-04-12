/*
    The Start of Main File:
        This file has Life Loop and this file controls the game cycle
        The main method set the default vars.
*/

//Start:

//Import the headers:
#include <windows.h>
#include <winuser.h>


#include "NeededMethods.h"
#include "Ground.h"
#include "Players.h"
using namespace std;

//Define the exit function:

int KillGame();

//Start of main method:
int main(int argc, char** arvg)
{
    //The Code:

    //Define the base vars:
    int Player1HP = 3;   int Player2HP = 3;    int Score = 0;    bool Game = true; //Game is the important var in the program;

    //Colors:
    string ColorPlayer1 = "Green";      string ColorPlayer2 = "Purple";

    //Define the Objects:

    Ground PlayGround;
    Player GamePlayer1(ColorPlayer1, 134, (29 / 2) - 3 + 7);
    Player GamePlayer2(ColorPlayer2, 31, (29 / 2) - 3 + 7);
    
//==================================Start Main Game======================

    //Showing the ground and set the window:

    //Window Setup:
    Methods::FullScreen(true);          Sleep(12);
    Methods::HideScrollBar(true);       Sleep(12);
    Methods::HideCursor(false);


    PlayGround.DrawGround(true);
    PlayGround.ShowInfos(Player1HP, Player2HP, Score);
    GamePlayer1.DrawBody(true);
    GamePlayer2.DrawBody(true);

    //Main Loop:

    while(Game == true)
    {
        //KeyBoard input control:

        if(GetAsyncKeyState(0x57)){          GamePlayer1.ControlMovement('U');}//Move Player 1 to Up (check if press 'W')

        else if(GetAsyncKeyState(0x53)){     GamePlayer1.ControlMovement('D');}//Move Player 1 to Down (check if press 'S')

        else if(GetAsyncKeyState(0x55)){     GamePlayer2.ControlMovement('U');}//Move Player 2 to Up (check if press 'U')

        else if(GetAsyncKeyState(0x4A)){     GamePlayer2.ControlMovement('D');}//Move Player 2 to Down (check if press 'J')

        else if(GetAsyncKeyState(0x45)){           Game = false;}

        //Ball Logic and movement:

        


        //wait:
        Sleep(50);
    }

    //Exit of game:
    KillGame();
    return 0;
}

int KillGame(void)
{

        //Set Default color:
        system("color");

        //Clear Screen:
        system("cls");

        //Normalize Screen:
        Methods::FullScreen(false);

        //Show console Cursor:
        Methods::HideCursor(true);
        return 0;
}
