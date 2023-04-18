//
// Created by Voltage on 4/13/2023.
//

/*
 * This file will control the ball movement and logic:
 * */

#ifndef BALL_H
#define BALL_H

//imports:
#include <iostream>
#include <windows.h>
#include <time.h>
#include "NeededMethods.h"
#include "Ground.h"
using namespace std;


//The Ball class :
class Ball
{
public:

    //The Constructor:
    Ball(string Color , int GroundWidth, int GroundHigh)
    {
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

        //Point to Screen center:
        MidWidth = MainWidth = GroundWidth / 2 + 25 + 3;
        MidHigh  = MainHigh = (GroundHigh + 7 + 2) / 2;

        //Choose a random direction:
        srand(time(0));
        int RandNumber = rand() % (5 - 1) + 1;
        switch(RandNumber)
        {
            case 1: BallDirection = NW;     break;
            case 2: BallDirection = NE;     break;
            case 3: BallDirection = SW;     break;
            case 4: BallDirection = SE;     break;
        }

        BeforeDirection = BallDirection;
    }

    //define Methods:

    //that draws the ball:
    void DrawBall(bool);

    //that controls the ball movement events:
    void BallMovement(void);

    //that controls the ball logic(Score & ball direction):
    void Logic(int*, int *, int *, int *, int, int, int*);


private:

    //Vars:
    int MainWidth = 0 ;         int MainHigh = 0;       int MidWidth = 0;       int MidHigh = 0;
    int ColorNumber = 0;
    //Enum for movement:

    //The directions:
    enum Coordinate{NW = 1, NE = 2, SW = 3, SE = 4, W = 5, E = 6};        Coordinate  BallDirection,    BeforeDirection;

    Ground GroundOb;

};

void Ball::DrawBall(bool flag)
{
    //SetColor:
    Methods::SetTextColor(ColorNumber);
    //Print Ball:
    Methods::SetCursor(MainWidth, MainHigh);

    if(flag == true){cout << (char)219;}    else{cout << ' ';}
    return;
}

void Ball::BallMovement(void)
{
    //Set Color:
    Methods::SetTextColor(ColorNumber);

    switch (BallDirection)
    {
        case W:

            Methods::SetCursor(MainWidth, MainHigh);        cout << ' ';

            MainWidth -= 1;

            Methods::SetCursor(MainWidth, MainHigh);              cout << (char)219;
            break;

        case E:
            Methods::SetCursor(MainWidth, MainHigh);        cout << ' ';

            MainWidth += 1;

            Methods::SetCursor(MainWidth, MainHigh);              cout << (char)219;
            break;
        case NW:

            Methods::SetCursor(MainWidth, MainHigh);        cout << ' ';

            MainWidth -= 1;     MainHigh -= 1;

            Methods::SetCursor(MainWidth, MainHigh);              cout << (char)219;
            break;

        case NE:
            Methods::SetCursor(MainWidth, MainHigh);        cout << ' ';

            MainWidth += 1;     MainHigh -= 1;

            Methods::SetCursor(MainWidth, MainHigh);              cout << (char)219;
            break;

        case SW:
            Methods::SetCursor(MainWidth, MainHigh);        cout << ' ';

            MainWidth -= 1;     MainHigh += 1;

            Methods::SetCursor(MainWidth, MainHigh);              cout << (char)219;

            break;

        case SE:

            Methods::SetCursor(MainWidth, MainHigh);        cout << ' ';

            MainWidth += 1;     MainHigh += 1;

            Methods::SetCursor(MainWidth, MainHigh);              cout << (char)219;
            break;
    }

    BeforeDirection = BallDirection;

    return;
}

void Ball::Logic(int *Player1HP, int *Player2HP, int *ScorePlayer1, int *ScorePlayer2, int HighPlayer1, int HighPlayer2, int* Delay)
{
    //Thi method controls the Ball logic:

    //Control Ball limit:
    if(MainHigh == 33)
    {
        switch(BeforeDirection)
        {
            case SE:    BallDirection = NE;     break;
            case SW:    BallDirection = NW;     break;
        }
    }

    else if(MainHigh == 10)
    {
        switch(BeforeDirection)
        {
            case NW:    BallDirection = SW;     break;
            case NE:    BallDirection = SE;     break;
        }
    }


    else if(MainWidth == 32)
    {
        Sleep(1000);

        *Player2HP -= 1;
        GroundOb.ShowInfos(*Player1HP, *Player2HP, *ScorePlayer1, *ScorePlayer2);

        Methods::SetCursor(MainWidth, MainHigh);    cout << ' ';

        Methods::SetCursor(MidWidth, MidHigh);      cout << (char)219;

        MainWidth = MidWidth;       MainHigh = MidHigh;
        *Delay -= 5;
    }

    else if(MainWidth == 134)
    {
        Sleep(1000);

        *Player1HP -= 1;
        GroundOb.ShowInfos(*Player1HP, *Player2HP, *ScorePlayer1, *ScorePlayer2);

        Methods::SetCursor(MainWidth, MainHigh);    cout << ' ';

        Methods::SetCursor(MidWidth, MidHigh);      cout << (char)219;

        MainWidth = MidWidth;       MainHigh = MidHigh;
        *Delay -= 5;
    }

    //Check if the ball hit the player:

    int RandNumber = 0;

    if(MainWidth == 133)
    {
        for(int index = 0 ; index < 7 ;  index ++)
        {
            if(MainHigh == HighPlayer1 + index)
            {
                switch (BeforeDirection)
                {
                    case SE:
                        BallDirection = SW;
                        break;

                    case E:

                        //Choose a random direction:
                        srand(time(0) / 2);
                        RandNumber = rand() % (4 - 1) + 1;
                        switch (RandNumber) {
                            case 1:
                                BallDirection = NW;
                                break;
                            case 2:
                                BallDirection = W;
                                break;
                            case 3:
                                BallDirection = SW;
                                break;
                        }

                        break;

                    case NE:
                        BallDirection = NW;
                        break;

                }
                *ScorePlayer1 += 1;
                GroundOb.ShowInfos(*Player1HP, *Player2HP, *ScorePlayer1, *ScorePlayer2);
                break;
            }

        }
    }

    else if(MainWidth == 34)
    {
        for(int index = 0 ; index < 7 ;  index ++)
        {
            if(MainHigh == HighPlayer2 + index)
            {
                switch(BeforeDirection)
                {
                    case SW:    BallDirection = SE; break;

                    case W:
                        //Choose a random direction:
                        srand(time(0) / 2);
                        RandNumber = rand() % (4 - 1) + 1;
                        switch(RandNumber)
                        {
                            case 1: BallDirection = NE;     break;
                            case 2: BallDirection = E;     break;
                            case 3:BallDirection = SE;       break;
                        }

                        break;

                    case NW:    BallDirection = NE; break;
                }
                *ScorePlayer2 +=1;
                GroundOb.ShowInfos(*Player1HP, *Player2HP, *ScorePlayer1, *ScorePlayer2);
                break;
            }
        }
    }

    return;
}

#endif
