/*********************************************************************
** Program Filename: mazePerson.h
** Author: Douglas Crocker
** Date: 3/6/2022
** Description: This file defines abstract class MazePerson, which defines general functionality of classes: IntrepidStudent, TA, Wall.
** Input:  Terminal variables
** Output: Game UI
*********************************************************************/

#ifndef MAZEPERSON_H
#define MAZEPERSON_H

#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "coordinate.h"

using namespace std;

class MazePerson {
    protected:

        Coordinate * coord;

        char displayChar;
        bool isAppeased;
        int progSkills;
        int numTurns;

    public:
        MazePerson();
        virtual ~MazePerson();

        //virtual MazePerson& operator=(const MazePerson&);

        virtual int getMpLine() const;
        virtual int getMpColumn() const;
        virtual char getDisplayChar() const;
        Coordinate* getCoord() const;
        
        //virtual char getMove() = 0;
        virtual void getMove(MazePerson*);
        virtual void setLocation(int, int) = 0;
        
        virtual void setIsAppeased(const bool);
        virtual bool getIsAppeased() const;
        virtual void drawTa(WINDOW*);

        virtual int getProgSkills() const;
        virtual void setProgSkills(const int);

};

#endif