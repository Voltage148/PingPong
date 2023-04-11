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

int KillGame(bool);

//Start of main method:
int main(int argc, char** arvg)
{
    //The Code:

    //Define the base vars:
    int PlayerHP = 5;   int Score = 0;  int Time = 0;   int PlayersMovement = 0;      bool Game = true; //Game is the important var in the program;

    //Define the Objects:

    Ground PlayGround;      Player GamePlayer("Yellow" ,   PlayGround.HighetCopy,  PlayGround.WidthCopy); //Red is default color
    
//==================================Start Main Game======================

    //Showing the ground and set the window:

    //Window Setup:
    Methods::FullScreen(true);          Sleep(12);
    Methods::HideScrollBar(true);       Sleep(12);
    Methods::HideCursor(false);


    PlayGround.DrawGround(true);
    PlayGround.ShowInfos(PlayerHP, PlayersMovement);
    GamePlayer.DrawBody(true);


    //Main Loop:

    while(Game == true)
    {
        GamePlayer.ControlInput(&Game);
        GamePlayer.Movement(&PlayersMovement);
    }

    //Exit of game:
    KillGame(true);
    return 0;
}

int KillGame(bool flag)
{
    if(flag == true)
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
    return 1;
}
