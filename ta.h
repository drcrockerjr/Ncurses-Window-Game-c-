/*********************************************************************
** Program Filename: ta.h
** Author: Douglas Crocker
** Date: 3/6/2022
** Description: This file defines the Ta class
** Input:
** Output:
*********************************************************************/

#ifndef TA_H
#define TA_H

#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "coordinate.h"
#include "mazePerson.h"
#include "intrepidStudent.h"

using namespace std;

class Ta : public MazePerson {

    public:
        Ta();
        Ta(int, int, int);
        ~Ta();

        //Ta& operator=(const Ta&);

        //int getLine() const;
        //int getColumn() const;
        char getDisplayChar() const;
        void drawTa(WINDOW*);
        
        char getMove();
        void getMove(MazePerson*);
        void setLocation(int, int);
        void setIsAppeased();
    private:
        int difficulty;
};

#endif