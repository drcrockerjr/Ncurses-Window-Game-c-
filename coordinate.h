/*********************************************************************
** Program Filename: coordinate.h
** Author: Douglas Crocker
** Date: 3/6/2022
** Description: This class was created to simplify operations done with the ncurses coordinate system
** Input:
** Output:
*********************************************************************/

#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

class Coordinate {

    private:
        int line;
        int column;
    public:
        Coordinate();
        Coordinate(int, int);
        ~Coordinate();

        int getColumn() const;
        int getLine() const;
        void setColumn(const int);
        void setLine(const int);

        void mvNorth();
        void mvSouth();
        void mvWest();
        void mvEast();

        bool isSame(Coordinate *);
        float getDistance(int, int);
};

#endif