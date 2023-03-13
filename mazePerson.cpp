#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "mazePerson.h"
#include "coordinate.h"

using namespace std;

MazePerson::MazePerson() {

}

MazePerson::~MazePerson() {
}

/*MazePerson& MazePerson::operator=(const MazePerson& oldM) {
    this->coord.getLine() = oldM.getMpLine();
    this->column = oldM.getMpColumn();

    this->displayChar = oldM.getDisplayChar();
    
}*/
int MazePerson::getMpLine() const { return this->coord->getLine(); }
int MazePerson::getMpColumn() const { return this->coord->getColumn(); }
char MazePerson::getDisplayChar() const { return this->displayChar; }
Coordinate* MazePerson::getCoord() const { return this->coord; }

void MazePerson::drawTa(WINDOW* win) {
}

void MazePerson::getMove(MazePerson* stud) {

}
void MazePerson::setIsAppeased(const bool b) {
    this->isAppeased = b;
    this->numTurns = 0;
}
bool MazePerson::getIsAppeased() const {
    return this->isAppeased;
}

int MazePerson::getProgSkills() const { return this->progSkills; }
void MazePerson::setProgSkills(const int p) { this->progSkills = p; }




