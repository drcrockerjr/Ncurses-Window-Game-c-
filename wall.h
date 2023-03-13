/*********************************************************************
** Program Filename: wall.h
** Author: Douglas Crocker
** Date: 3/6/2022
** Description: This file defines the Wall class
** Input:
** Output:
*********************************************************************/

#ifndef WALL_H
#define WALL_H

#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "mazeLocation.h"
#include "coordinate.h"

using namespace std;

#define WALL '#'

class Wall : public MazeLocation {    
    public:
        Wall();
        Wall(int, int);
        ~Wall();

        void drawLocation(WINDOW*);
        bool isOccupiable();
        //char getDisplayCharacter();
    private:


};

#endif