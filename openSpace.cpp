#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "mazeLocation.h"
#include "openSpace.h"


OpenSpace::OpenSpace() : MazeLocation() {
    this->displayChar = 'O';
    this->isOcc = false;
}

OpenSpace::~OpenSpace() {
}

OpenSpace::OpenSpace(int column, int line) : MazeLocation() {
    this->startCoord.setColumn(column);
    this->startCoord.setLine(line);
    
    this->displayChar = 'O';
    this->isOcc = true;
}


void OpenSpace::drawLocation(WINDOW * win) {

    int endCol = this->startCoord.getColumn() + this->width;
    int endLine = this->startCoord.getLine() + this->height;

    int startCol = this->startCoord.getColumn();
    int startLine = this->startCoord.getLine();
    
    
    for(int l = this->startCoord.getLine(); l < endLine; l++) {
        for(int c = this->startCoord.getColumn(); c < endCol; c++) {
            //wattron(win, A_INVIS);
            mvwaddch(win , l, c, A_INVIS);
            //wattron(win, A_NORMAL);
             
        }
    }
}

bool OpenSpace::isOccupiable() {
    return isOcc;
}


