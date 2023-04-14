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
#include "Ball.h"
using namespace std;

//Define the exit function:

int KillGame();

//Start of main method:
int main(void)
{
    //The Code:

    //Define the base vars:
    int Player1HP = 3;   int Player2HP = 3;    int ScorePlayer1 = 0;    int ScorePlayer2 = 0;  string Winner = "Nobody";    bool Game = true; //Game is the important var in the program;
    int Time = 50;
    //Colors:
    string ColorPlayer1 = "Green";      string ColorPlayer2 = "Blue";

    //Define the Objects:

    Ground PlayGround;
    Player GamePlayer1(ColorPlayer1, 134, (29 / 2) - 3 + 7);
    Player GamePlayer2(ColorPlayer2, 31, (29 / 2) - 3 + 7);

    Ball GameBall("Yellow", 117, 29);
//==================================Start Main Game======================

    //Showing the ground and set the window:

    //Window Setup:
    Methods::FullScreen(true);          Sleep(12);
    Methods::HideScrollBar(true);       Sleep(12);
    Methods::HideCursor(false);


    PlayGround.DrawGround(true);
    PlayGround.ShowInfos(Player1HP, Player2HP, 0, 0);
    GamePlayer1.DrawBody(true);
    GamePlayer2.DrawBody(true);
    GameBall.DrawBall(true);
    //Main Loop:


    while(Game == true)
    {
        //KeyBoard input control:

        if(GetAsyncKeyState(0x57)){          GamePlayer1.ControlMovement('U');}//Move Player 1 to Up (check if press 'W')

        else if(GetAsyncKeyState(0x53)){     GamePlayer1.ControlMovement('D');}//Move Player 1 to Down (check if press 'S')

        else if(GetAsyncKeyState(0x55)){     GamePlayer2.ControlMovement('U');}//Move Player 2 to Up (check if press 'U')

        else if(GetAsyncKeyState(0x4A)){     GamePlayer2.ControlMovement('D');}//Move Player 2 to Down (check if press 'J')

        //that will remove:
        else if(GetAsyncKeyState(VK_CONTROL)){     Time -= 2;}

        else if(GetAsyncKeyState(0x45)){           Game = false;}

        //Ball Logic and movement:

        GameBall.BallMovement();
        GameBall.Logic(&Player1HP,
                       &Player2HP,
                       &ScorePlayer1,
                       &ScorePlayer2,
                       GamePlayer1.StartPlace,
                       GamePlayer2.StartPlace);

        //Players Logic:

        if(Player1HP == 0)
        {
            Winner = "Player2";
            Game = false;
        }

        else if(Player2HP == 0)
        {
            Winner = "Player1";
            Game = false;
        }

        //wait:
        Sleep(Time);
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
