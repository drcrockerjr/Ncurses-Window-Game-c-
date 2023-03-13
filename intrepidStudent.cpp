#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "coordinate.h"
#include "mazePerson.h"
#include "intrepidStudent.h"

using namespace std;

#define STUDENT '*'

IntrepidStudent::IntrepidStudent() : MazePerson() {
    this->displayChar = STUDENT;
}

IntrepidStudent::IntrepidStudent(int l, int c) {
    this->coord = new Coordinate();
    this->coord->setLine(l);
    this->coord->setColumn(c);
    this->displayChar = STUDENT;
    this->progSkills = 0;
}

IntrepidStudent::~IntrepidStudent() {
    if(this->coord != NULL) {
            delete this->coord;
    }
}

/*IntrepidStudent& operator=(const IntrepidStudent& ip) {
    this->row = ip.getRow();
    this->column = ip.getColumn();

    this->displayChar = ip.getDisplayChar();
}*/

//nt IntrepidStudent::getMpLine() const { return this->coord->getLine(); }
//int IntrepidStudent::getMpColumn() const { return this->coord->getColumn(); }
char IntrepidStudent::getDisplayChar() const { return this->displayChar;}

char IntrepidStudent::getMove() {
    return 0;
}

void IntrepidStudent::setLocation(int l, int c) {
    
    this->coord->setLine(l);
    this->coord->setColumn(c);
}

