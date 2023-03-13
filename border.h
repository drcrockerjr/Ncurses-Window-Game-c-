/*********************************************************************
** Program Filename: border.h
** Author: Douglas Crocker
** Date: 3/6/2022
** Description: This File define the border derived class of MazeLocation, the border represents the outside border of the game terminal
** Input: game terminal width
** Output: border of game terminal
*********************************************************************/


#ifndef BORDER_H
#define BORDER_H

#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "mazeLocation.h"
#include "coordinate.h"

using namespace std;

#define BORDER '#'

class Border : public MazeLocation {    
    public:
        Border();
        Border(int, int, int, int);
        ~Border();

        void setBorder(int, int, int, int);
        void drawLocation(WINDOW *);
        bool isOccupiable();
    private:


};

#endif