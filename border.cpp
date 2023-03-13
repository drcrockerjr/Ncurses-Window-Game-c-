#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "mazeLocation.h"
#include "border.h"
#include "game.h"

#define BORDER '#'

Border::Border() : MazeLocation() {
    this->displayChar = BORDER;
}

Border::~Border() {
}

void Border::setBorder(int startCol, int startLine, int h, int w) {
    this->startCoord.setColumn(startCol);
    this->startCoord.setLine(startLine);

    this->height = h;
    this->width = w;
    
    this->displayChar = BORDER;
    this->isOcc = true;
}

void Border::drawLocation(WINDOW * win) {

    int endCol = this->startCoord.getColumn() + this->width;
    int endLine = this->startCoord.getLine() + this->height;

    int startCol = this->startCoord.getColumn();
    int startLine = this->startCoord.getLine();
    
    for(int l = this->startCoord.getLine(); l < endLine; l++) {
        for(int c = this->startCoord.getColumn(); c < endCol; c++) {
            
            if(c == startCol || l == startLine || c == (endCol - 1) || l == (endLine - 1)) {
                mvwaddch(win , c, l, this->displayChar);
            } 
        }
    }
    
}

bool Border::isOccupiable() {
    return isOcc;
}

/*char Border::getDisplayCharacter()  {
    return this->displayChar;
}*/

