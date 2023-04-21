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
int KillGame(void);

//Select Color Menu:
void SelectColor(string* Color1, string* Color2);

//Start of main method:
int main(int argc ,char** arvg)
{
    //The Code:

    //Define the base vars:
    string Winner = "Nobody";  bool Game = true;  int Delay = 45;      bool is_HP_changed = false;        bool is_Score_changed = false;

    //Colors:
    string ColorPlayer1 = "Green";      string ColorPlayer2 = "Blue";

    //Window Setup:
    Methods::FullScreen(true);          Sleep(10);
    Methods::HideScrollBar(true);       Sleep(10);
    Methods::HideCursor(false);         Sleep(10);

    //Set Player Color:
    SelectColor(&ColorPlayer1, &ColorPlayer2);

    //Define the Objects:

    Ground PlayGround;

    Player GamePlayer1(ColorPlayer1, (PlayGround.GetGroundWidth() - 11), PlayGround.GetGroundHigh());

    Player GamePlayer2(ColorPlayer2, (PlayGround.GetGroundWidth()  - 114) , PlayGround.GetGroundHigh());

    Ball GameBall("Yellow", PlayGround.GetGroundWidth(), PlayGround.GetGroundHigh());
//==================================Start Main Game======================


    //Draw Ground, Players, and Ball:
    PlayGround.DrawGround(true);

    PlayGround.ShowInfos(GamePlayer1.GetPlayerHP(), GamePlayer2.GetPlayerHP(), GamePlayer1.GetPlayerScore(), GamePlayer2.GetPlayerScore());

    GamePlayer1.DrawBody(true);
    GamePlayer2.DrawBody(true);

    GameBall.DrawBall(true);
    //Main Loop:


    while(Game)
    {
        //Player logic:
             if(GamePlayer1.GetPlayerHP() == 0){ Game = false;       Winner = "Player 2";   PlayGround.WinMenu(Winner);}

        else if(GamePlayer2.GetPlayerHP() == 0){ Game = false;  Winner = "Player 1";   PlayGround.WinMenu(Winner);}

        //KeyBoard input control:

        if(GetAsyncKeyState(0x57) ){          GamePlayer1.ControlMovement('U');}//Move Player 1 to Up (check if press 'W')

        else if(GetAsyncKeyState(0x53)){     GamePlayer1.ControlMovement('D');}//Move Player 1 to Down (check if press 'S')

        else if(GetAsyncKeyState(0x55)){     GamePlayer2.ControlMovement('U');}//Move Player 2 to Up (check if press 'U')

        else if(GetAsyncKeyState(0x4A)){     GamePlayer2.ControlMovement('D');}//Move Player 2 to Down (check if press 'J')

        else if(GetAsyncKeyState(VK_CONTROL)){  Game = false;  break;}//that exit from game (Check if press CTRL(Control)):

        //Ball Logic and movement:

        GameBall.BallMovement();

        is_HP_changed = GameBall.BallLimit_Logic(GamePlayer1, GamePlayer2, Delay);

        is_Score_changed = GameBall.BallInteraction_Logic(GamePlayer1, GamePlayer2);


        if(is_HP_changed || is_Score_changed){   
           PlayGround.ShowInfos(GamePlayer1.GetPlayerHP(), GamePlayer2.GetPlayerHP(), GamePlayer1.GetPlayerScore(), GamePlayer2.GetPlayerScore());  
           is_Score_changed = is_HP_changed = false;}

        //wait:
        Sleep(Delay);
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

void SelectColor(string* Color1, string* Color2)
{

    //Clear the Screen:         //Set Background Color             //Set Text Color
    system("cls");      system("color 10");     Methods::SetTextColor(24);

    for(int HCounter = 0 ; HCounter < 11 ; HCounter ++)
    {
        for(int WCounter = 0 ; WCounter < 67 ; WCounter++)
        {
            Methods::SetCursor(WCounter + 45, HCounter + 15);

            if(WCounter > 64 || HCounter > 9){Methods::SetTextColor(16);}

            else{Methods::SetTextColor(24);}

            cout << (char)219;
        }
    }

    Methods::SetTextColor(128);

    //Texts:
    Methods::SetCursor(47, 20);     cout << "The PingPong is a free game on Github.com!! ";
    Methods::SetCursor(47, 21);     cout << "Powered by C++";

    //Input Color:
    Methods::SetCursor(47, 17);     cout << "Player 1 Color:";cin >> *Color1;
    Methods::SetCursor(77, 17);      cout << "Player 2 Color:";cin >> *Color2;

    return;
}