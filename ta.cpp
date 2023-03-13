#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <random>

#include "coordinate.h"
#include "mazePerson.h"
#include "ta.h"

using namespace std;

#define TA 'T'
#define APPEASED 'A'
#define OPENSPACE 8388702

Ta::Ta() : MazePerson() {
    this->displayChar = TA;
    this->isAppeased = false;
}

Ta::Ta(int l, int c, int diff) {
    this->coord = new Coordinate();
    this->coord->setLine(l);
    this->coord->setColumn(c);
    this->displayChar = TA;
    this->isAppeased = false;
    this->difficulty = diff;
    this->numTurns= 0;
}

Ta::~Ta() {
    if(this->coord != NULL) {
        delete this->coord;
    }
}

/*Ta& operator=(const Ta& ip) {
    this->row = ip.getRow();
    this->column = ip.getColumn();

    this->displayChar = ip.getDisplayChar();
}*/

char Ta::getDisplayChar() const { return this->displayChar;}

void Ta::drawTa(WINDOW* win) {
    for(int l = (this->coord->getLine() - 1);  l < (this->coord->getLine() + 1); l++) {
        for(int c = (this->coord->getColumn() - 1); c < (this->coord->getColumn() + 2); c++) {
            if(this->isAppeased == false) {
                mvwaddch(win, l, c, this->displayChar);
            } else if(this->isAppeased == true) {
                mvwaddch(win, l, c, APPEASED);
            }
        }
    }
}

/*char Ta::getMove() {

}*/

void Ta::getMove(MazePerson* stud) {
    srand(time(NULL));
    this->numTurns = this->numTurns + 1;

    if(this->numTurns > 10) {
        this->isAppeased = false;
        this->numTurns = 0;
    }
    //if(this->isAppeased == false) {
        
        if(this->difficulty == 2) {
            //find distance from ta to stud for every move
            float upDis = this->coord->getDistance(stud->getMpLine() + 1, stud->getMpColumn());
            float downDis = this->coord->getDistance(stud->getMpLine() - 1, stud->getMpColumn());
            float leftDis = this->coord->getDistance(stud->getMpLine(), stud->getMpColumn() + 1);
            float rightDis = this->coord->getDistance(stud->getMpLine(), stud->getMpColumn() - 1);
            float distances[4] = {upDis, downDis, leftDis, rightDis}; 

            //use for detecting how close ta is to student for appeasing and game ending
            float temp = distances[0];
            for(int i = 0; i < 4; i++) {
                if(distances[i] < temp) {
                    temp = distances[i];
                }
            }
            bool mvMade = false;
            if(temp == upDis && mvMade != true) {
                //up is fastest to student
                int testLine = this->coord->getLine() - 1;
                int testColumn = this->coord->getColumn();
                int ch = mvinch(testLine, testColumn);
                if(ch == OPENSPACE) {
                    this->coord->mvNorth();
                    mvMade = true;
                } else {
                }
                
            } else if(temp == downDis && mvMade != true) {
                //down is fastest to student
                int testLine = this->coord->getLine() + 1;
                int testColumn = this->coord->getColumn();
                int ch = mvinch(testLine, testColumn);
                if(ch == OPENSPACE) {
                    this->coord->mvSouth();
                    mvMade = true;
                }else {
                }
            } else if(temp == leftDis && mvMade != true) {
                //left is fastest to student
                int testLine = this->coord->getLine();
                int testColumn = this->coord->getColumn() - 1;
                int ch = mvinch(testLine, testColumn);
                if(ch == OPENSPACE) {
                    this->coord->mvWest();
                    mvMade = true;
                }else {
                }
            } else if(temp == rightDis && mvMade != true) {
                //right is fastest to student
                int testLine = this->coord->getLine();
                int testColumn = this->coord->getColumn() + 1;
                int ch = mvinch(testLine, testColumn);
                if(ch == OPENSPACE) {
                    this->coord->mvEast();
                    mvMade = true;
                }else {
                }
            } else {
                //something wrong
            }
        } else {
            int r = (rand() % 4);
            switch(r) {
                case 0: {
                    int testLine = this->coord->getLine() - 1;
                    int testColumn = this->coord->getColumn();
                    int ch = mvinch(testLine, testColumn);
                    if(ch == OPENSPACE) {
                        this->coord->mvNorth();
                    } else {
                    }
                    break;
                }
                case 1: {
                    int testLine = this->coord->getLine() + 1;
                    int testColumn = this->coord->getColumn();
                    int ch = mvinch(testLine, testColumn);
                    if(ch == OPENSPACE) {
                        this->coord->mvSouth();
                    }else {
                    }
                    break;
                }
                case 2: {
                    int testLine = this->coord->getLine();
                    int testColumn = this->coord->getColumn() - 1;
                    int ch = mvinch(testLine, testColumn);
                    if(ch == OPENSPACE) {
                        this->coord->mvWest();
                    }else {
                    }
                    break;
                }
                case 3: {
                    int testLine = this->coord->getLine();
                    int testColumn = this->coord->getColumn() + 1;
                    int ch = mvinch(testLine, testColumn);
                    if(ch == OPENSPACE) {
                        this->coord->mvEast();
                    }else {
                    }
                    break;
                }
            }
        }
    //}
}

void Ta::setLocation(int l, int c) {
    
    this->coord->setLine(l);
    this->coord->setColumn(c);
}

