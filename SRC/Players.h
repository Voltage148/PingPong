//
// Created by Voltage on 4/10/2023.
//

/*
 *  So this file can control the player and CPU(Computer Player):
 *      Contents:
 *              Player Class : Draw Player, Process Player, Control player input, Control player movement;
 *              ComputerPlayer Class : Draw Body
 */

#ifndef PLAYERS_H
#define PLAYERS_H

//Imports:
#include "NeededMethods.h"
#include <Windows.h>
#include <conio.h>

using namespace std;

//The Player Class:

class Player
{
    public:
        //Constructor:

        Player(string Color, int Width, int Highet)
        {
            //Convert Color to Number:
            switch(Color[0])
            {
                case 'R':
                case 'r':
                    ColorNumber = 4;
                    break;

                case 'G':
                case 'g':
                    ColorNumber = 2;
                    break;

                case 'B':
                case 'b':
                    ColorNumber = 1;
                    break;

                case 'Y':
                case 'y':
                    ColorNumber = 6;
                    break;

                case 'A':
                case 'a':
                    ColorNumber = 3;
                    break;

                case 'P':
                case 'p':
                    ColorNumber = 5;
                    break;

                default:
                    ColorNumber = 7;
                    break;
            }

            //Set Player Start Drawing Place:
            StartPlace = Highet / 2;
            StartWidth = Width;

        }


        //Define Methods:

            //That draws the player Body in ground:
            void DrawBody(bool);

            //That controls input and movement:
            void ControlMovement(char);

            //Get Methods:

            int GetPlayerHP(void);

            int GetPlayerScore(void);

            int GetPlayerWidth(void);

            int GetPlayerHigh(void);

            //Set Methods:

            void SetPlayerHP(int);

            void SetPlayerScore(int);

            void SetPlayerWidth(int);

            void SetPlayerHigh(int);



    private:

        //The Constants vars is here:
        const int Length = 7;   const int Width = 2;     int PlayerHP = 3;      int PlayerScore = 0;
        
        int StartPlace = 0;     int StartWidth = 0;

        //They are unknown Vars (set by constructor when program running ):
        int ColorNumber = 0;


};

void Player::DrawBody(bool flag)
{

    //Start Drawing Body:
    //Set Color:
    Methods::SetTextColor(ColorNumber);

    //Draw Process:
    for(int index = 0   ;   index < Length   ;   index++)
    {
        for(int Counter = 0     ;   Counter < 2    ;   Counter++)
        {
            Methods::SetCursor(StartWidth + Counter, StartPlace + index);

            //Draw Player on Screen:
            if(flag == true){   cout << (char)219;  }

            //Remove player on Screen:
            else{   cout << ' ';    }
        }
    }
    return;
}

void Player::ControlMovement(char Coord)
{
    //Set the player color:
    Methods::SetTextColor(ColorNumber);
    switch(Coord)
    {
                //if coord is UP:
            case 'U':
                //Player body limit
                if(StartPlace > 9)
                {
                    //Go to Player bottom  and clear:
                    Methods::SetCursor(StartWidth, StartPlace + Length - 1);
                    for (int Counter = 0; Counter < 2; Counter++) { cout << ' '; }

                    //Update Value
                    StartPlace--;

                    //Go to Player top and draw:
                    Methods::SetCursor(StartWidth, StartPlace);
                    for (int Counter = 0; Counter < 2; Counter++) { cout << (char) 219; }
                }
                break;
                //if Player Down:
            case 'D':
                //Player body limit
                if(StartPlace < 27)
                {
                    //Go to Player Top and clear:
                    Methods::SetCursor(StartWidth, StartPlace);
                    for (int Counter = 0; Counter < 2; Counter++) { cout << ' '; }

                    //Update value:
                    StartPlace++;

                    //Go to Player bottom and Draw:
                    Methods::SetCursor(StartWidth, StartPlace + Length - 1);
                    for (int Counter = 0; Counter < 2; Counter++) { cout << (char) 219; }
                }
                break;
    }


    return;
}

int Player::GetPlayerHP(void){return PlayerHP;}

int Player::GetPlayerScore(void){return PlayerScore;}

int Player::GetPlayerWidth(void){return StartWidth;}

int Player::GetPlayerHigh(void){return StartPlace;}



void Player::SetPlayerScore(int Score){PlayerScore = Score;     return;}

void Player::SetPlayerHP(int HP){PlayerHP = HP;     return;}

void Player::SetPlayerWidth(int Width){StartWidth = Width;      return;}

void Player::SetPlayerHigh(int High){StartPlace = High;     return;}

#endif