#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "mazeLocation.h"
#include "coordinate.h"

using namespace std;

MazeLocation::MazeLocation() {
    this->width = 8;
    this->height = 4;
}

MazeLocation::~MazeLocation() {
}
 

void MazeLocation::setMazePerson(MazePerson* mp) {
    this->mazeperson = mp;
    this->hasStudent = true;
}
void MazeLocation::setHasStudent(const bool b) {this->hasStudent = b; }
bool MazeLocation::getHasStudent() const{ return this->hasStudent; }
char MazeLocation::getOccCharacter() const { return this->occupyChar; }
void MazeLocation::setOccCharacter(const char o) { this->occupyChar = o; }

int MazeLocation::getMidLine() {
    return (this->startCoord.getLine() + (this->height / 2));
}
int MazeLocation::getMidColumn() {
    return (this->startCoord.getColumn() + (this->width / 2));
}


