/*********************************************************************
** Program Filename: mazeLocation.h
** Author: Douglas Crocker
** Date: 3/6/2022
** Description: This file defines the MazeLocation abstract class, which defines general functionality of classes: Wall, Border, OpenSpace
** Input: MazeLocation Size
** Output: Game UI
*********************************************************************/

#ifndef MAZELOCATION_H
#define MAZELOCATION_H

#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "coordinate.h"
#include "mazePerson.h"

using namespace std;

class MazeLocation {
    protected:
        Coordinate startCoord;
        char displayChar; 
        char occupyChar;
        bool isOcc;
        bool hasStudent = false;

        int height;
        int width;

        MazePerson * mazeperson;

    public:
        MazeLocation();
        virtual ~MazeLocation();


        void setDisplayChar(const char);
        virtual void setMazePerson(MazePerson*); 
        
        char getOccCharacter() const;
        void setOccCharacter(const char);
        void setHasStudent(const bool);
        bool getHasStudent() const;

        virtual void drawLocation(WINDOW*) = 0;
        virtual bool isOccupiable() = 0;
        int getMidLine();
        int getMidColumn();
        //virtual char getDisplayCharacter();
        //virtual void drawOccupyChar(char); //for drawing prog skills and TAs

};

#endif