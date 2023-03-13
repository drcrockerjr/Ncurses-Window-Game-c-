#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "mazeLocation.h"
#include "wall.h"

#define WALL '#'

Wall::Wall() : MazeLocation() {
    this->displayChar = WALL;
    this->isOcc = false;
}

Wall::~Wall() {
}

Wall::Wall(int column, int line) : MazeLocation() {
    this->startCoord.setColumn(column);
    this->startCoord.setLine(line);
    
    this->displayChar = WALL;
    this->isOcc = false;
}

void Wall::drawLocation(WINDOW * win) {
    //cout << "Wall::in drawLocation()" << endl;

    int endCol = this->startCoord.getColumn() + this->width;
    int endLine = this->startCoord.getLine() + this->height;

    int startCol = this->startCoord.getColumn();
    int startLine = this->startCoord.getLine();
    
    
    for(int l = this->startCoord.getLine(); l < endLine; l++) {
        for(int c = this->startCoord.getColumn(); c < endCol; c++) {

            
            if(c == startCol || l == startLine || c == (endCol - 1) || l == (endLine - 1)) {
                mvwaddch(win , l, c, this->displayChar);
            } 
        }
    }
}

bool Wall::isOccupiable() {
    return isOcc;
}

/*char Wall::getDisplayCharacter()  {
    return this->displayChar;
}*/
