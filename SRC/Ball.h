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

        MidWidth = MainWidth = GroundWidth / 2 + 25 + 3;
        MidHigh  = MainHigh = (GroundHigh + 7 + 2) / 2;

        //Choose a random direction:
        srand(time(0));
        int RandNumber = rand() % (7 - 1) + 1;
        switch(RandNumber)
        {
            case 1: BallDirection = NW;     break;
            case 2: BallDirection = NE;     break;
            case 3: BallDirection = SW;     break;
            case 4: BallDirection = SE;     break;
            case 5: BallDirection = W ;     break;
            case 6: BallDirection = E ;     break;
        }

        BeforeDirection = BallDirection;
    }

    //define Methods:
    //that draws the ball:
    void DrawBall(bool);

    //that controls the ball movement events:
    void BallMovement(void);

    //that controls the ball logic(Score & ball direction):
    void Logic(int*, int *, int *);


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
    if(flag == true)
    {
        //Print Ball:
        Methods::SetCursor(MainWidth, MainHigh);
        cout << (char)219;
    }

    else
    {
        //Print Ball:
        Methods::SetCursor(MainWidth, MainHigh);
        cout << ' ';
    }
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

void Ball::Logic(int *Player1HP, int *Player2HP, int *Score)
{
    //Thi method controls the Ball logic:

    //Control Ball limit:
    if(MainHigh == 33)
    {
        if(BeforeDirection == SE){BallDirection = NE; }

        else if(BeforeDirection == SW){BallDirection = NW; }

    }

    else if(MainHigh == 9)
    {
        if(BeforeDirection == NW){BallDirection = SW; }

        else if(BeforeDirection == NE){BallDirection = SE;}
    }

    else if(MainWidth == 29)
    {
        *Player2HP -= 1;
        GroundOb.ShowInfos(*Player1HP, *Player2HP, 10);
        Sleep(1000);

        Methods::SetCursor(MainWidth, MainHigh);    cout << ' ';
        Methods::SetCursor(MidWidth, MidHigh);      cout << (char)219;

        MainWidth = MidWidth;       MainHigh = MidHigh;
    }

    else if(MainWidth == 137)
    {
        *Player1HP -= 1;
        GroundOb.ShowInfos(*Player1HP, *Player2HP, 10);
        Sleep(1000);

        Methods::SetCursor(MainWidth, MainHigh);    cout << ' ';
        Methods::SetCursor(MidWidth, MidHigh);      cout << (char)219;

        MainWidth = MidWidth;       MainHigh = MidHigh;
    }

    return;
}

#endif
