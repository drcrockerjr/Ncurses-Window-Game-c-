/*********************************************************************
** Program Filename: intrepidStudent.h
** Author: Douglas Crocker
** Date: 3/6/2022
** Description: This file defines IntrepidStudent class, which handles: Student Positioning. The IntrepidStudent class is a child of MazePerson.
** Input: Student position
** Output: Student position
*********************************************************************/

#ifndef INTREPIDSTUDENT_H
#define INTREPIDSTUDENT_H

#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "coordinate.h"
#include "mazePerson.h"

using namespace std;

class IntrepidStudent : public MazePerson {

    public:
        IntrepidStudent();
        IntrepidStudent(int, int);
        ~IntrepidStudent();

        char getDisplayChar() const;
        
        char getMove();
        void setLocation(int, int);
    private:
};

#endif