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
using namespace std;

//Start of main method:
int main(int argc, char** arvg)
{
    //The Code:

    //Define the base vars:
    int PlayerHP = 3;   int Score = 0;  int Time = 0;   int PlayersMovement = 0;    bool Game = true; //Game is the important var in the program;

    //Define the Objects:

    Ground PlayGround;
    
//==================================Start Main Game======================

    //Showing the ground and set the window:

    //Window Setup:
    Methods::FullScreen(true);                                      Sleep(12);
    ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);     Sleep(12);
    Methods::HideCursor(false);

    //PlayGround:

    

    //Main Loop:


    return 0;
}