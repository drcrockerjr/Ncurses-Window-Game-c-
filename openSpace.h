/*********************************************************************
** Program Filename: openSpace.h
** Author: Douglas Crocker
** Date: 3/6/2022
** Description: This file defines the class OpenSpace, which represents a occupiable space in game. OpenSpace is a derived class of MazePerson.
** Input: Game variables
** Output: Game UI
*********************************************************************/

#ifndef OPENSPACE_H
#define OPENSPACE_H

#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "mazeLocation.h"
#include "coordinate.h"
#include "mazePerson.h"


using namespace std;

//#define OPENSPACE 'O'

class OpenSpace : public MazeLocation {    
    public:
        OpenSpace();
        OpenSpace(int, int);
        ~OpenSpace();

        void drawLocation(WINDOW*);
        bool isOccupiable();

    private:


};

#endif