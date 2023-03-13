#include <iostream>
#include <cmath>

#include "coordinate.h"

Coordinate::Coordinate() {

}
Coordinate::Coordinate(int l, int c) {
    this->line = l;
    this->column = c;
}

Coordinate::~Coordinate() {
}

int Coordinate::getColumn() const {return this->column; }
int Coordinate::getLine() const {return this->line; }

void Coordinate::setColumn(const int c) {this->column = c; }
void Coordinate::setLine(const int l) {this->line = l; }

void Coordinate::mvNorth() {
    this->line = (this->line - 1);
}
void Coordinate::mvSouth() {
    this->line = (this->line + 1);
}
void Coordinate::mvWest() {
    this->column = (this->column - 1);
}
void Coordinate::mvEast() {
    this->column = (this->column + 1);
}

bool Coordinate::isSame(Coordinate* cord) {
    if( this->column == cord->getColumn() && this->line == cord->getLine()) {
        return true;
    } else {
        return false;
    }
}

float Coordinate::getDistance(int line, int column){
    //distance formula for two coordinates
    return sqrt(pow((column - this->getColumn()),2) + pow((line - this->getLine()),2));
}