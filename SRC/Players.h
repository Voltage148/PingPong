//
// Created by Voltage on 4/10/2023.
//

/*
 *  So this file can control the player and CPU(Computer Player):
 *      Contents:
 *              Player Class : Draw Player, Process Player, Control player input, Control player movement;
 *              ComputerPlayer Class : Draw Body, Process Computer Player, The Computer AI;
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
        Player(string Color, int GroundHighet)
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


            }

            //Set Player Start Drawing Place:
            StartPlace = (GroundHighet / 2) - 3;

        }


        //Define Methods:

        //That draws the player Body in ground:
        void DrawBody(void);

        //That controls keyboard input for Player Movement:
        void ControlInput(void);

        //That Controls Player Movements EZ:
        void Movement(void);

    private:

        //The Constants vars is here:
        const int Length = 7;   const int Width = 2;

        //They are unknown Vars (set by constructor when program running ):
        int ColorNumber = 0;    int StartPlace = 0;

        //The Header is so important:
        int Header = 0;

};

#endif
