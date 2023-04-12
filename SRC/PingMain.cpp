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
#include "Rocket.h"
using namespace std;

//Define the exit function:

int KillGame(bool);

//Start of main method:
int main(int argc, char** arvg)
{
    //The Code:

    //Define the base vars:
    int PlayerHP = 5;   int ComputerHP = 5;    int Score = 0;    bool Game = true; //Game is the important var in the program;

    //Define the Objects:

    Ground PlayGround;
    Player GamePlayer("Green", 134, (29 / 2) - 3 + 7);
    Player Computer("Purple", 31, (29 / 2) - 3 + 7);
    
//==================================Start Main Game======================

    //Showing the ground and set the window:

    //Window Setup:
    Methods::FullScreen(true);          Sleep(12);
    Methods::HideScrollBar(true);       Sleep(12);
    Methods::HideCursor(false);


    PlayGround.DrawGround(true);
    PlayGround.ShowInfos(PlayerHP, ComputerHP, Score);
    GamePlayer.DrawBody(true);
    Computer.DrawBody(true);

    //Main Loop:

    while(Game == true)
    {
        GamePlayer.ControlInput_Movement(&Game);
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
