#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <fstream>

#include "mazeLocation.h"
#include "coordinate.h"
#include "maze.h"
#include "wall.h"
#include "border.h"
#include "openSpace.h"
#include "intrepidStudent.h"
#include "mazePerson.h"
#include "ta.h"

#define STUDENT '*'
#define WALL '#'
#define OPENSPACE 8388702
#define PROGSKILL '$'
#define INSTRUCTOR '%'

using namespace std;

Maze::Maze() {

}

Maze::~Maze() {

    /*ofstream fout;
    fout.open("test.txt", ios::app);
    fout << "~Maze()" << endl;
    fout.close();
    //delete dereferenced border and all maze objects
    for(int i = 0; i < this->dimension; i++) {
        for(int j = 0; j < this->dimension; j++) {
            delete this->locations[i][j];
            this->locations[i][j] = NULL;
        }
    }

    for(int i = 0; i < this->numProgSkills; i++) {
        delete this->progskills[i];
    }
    for(int i = 0; i < this->numTAs; i++) {
        delete this->tas[i];
    }
    delete this->instructor;
    delete this->student;*/
}

int Maze::getMazeLines() const { return this->mazeLines;}
int Maze::getMazeColumns() const { return this->mazeColumns;}

MazePerson* Maze::getStudent() { return this->student;}

Coordinate* Maze::getStudCoord(){
    return this->student->getCoord();
}

void Maze::startMaze( int d) {

    initscr();
    keypad(stdscr, TRUE);
    cbreak();
    noecho();

    clear();

    //initalize maze attributes
    this->dimension = d;
    this->mazeColumns = this->dimension * this->locationColumns;
    this->mazeLines = this->dimension * this->locationLines;

    //initiate border mazelocation;
    this->border.setBorder(0, 0, this->mazeColumns, this->mazeLines);

    //create maze locations

    this->locations.resize(this->dimension, vector<MazeLocation*>(this->dimension, NULL));
    this->tas.resize(4, NULL);

    int startLine = 0;
    int startColumn = 0;

    int numWalls = 0;
    int columnWalls = 0;
    bool studSet = false;
    int taCount = 0;

    srand(time(NULL));

    for(int i = 0; i < this->dimension; i++) {
        startColumn = 0;
        for(int j = 0; j < this->dimension; j++) {

            int r = (rand() % 2);
            switch(r) {
                case 0:
                    if(numWalls < this->wallCap && (i != 0 && j != 0 && j != (this->dimension) && i != (this->dimension) && columnWalls < 2)) {
                        this->locations[i][j] = new Wall(startColumn, startLine); 
                        numWalls++;
                        columnWalls++;
                    } else {
                        this->locations[i][j] = new OpenSpace(startColumn, startLine);
                        if(taCount < this->numTAs) {
                            this->tas[taCount] = new Ta(this->locations[i][j]->getMidLine(), this->locations[i][j]->getMidColumn(), this->difficulty);
                            taCount++;
                        }
                    }
                    break;
                case 1: {
                    this->locations[i][j] = new OpenSpace(startColumn, startLine);
                    if(studSet == false) {
                        this->student = new IntrepidStudent(this->locations[i][j]->getMidLine(), this->locations[i][j]->getMidColumn());
                        studSet = true; 
                    }
                    break;
                }
            }
            
            startColumn = startColumn + this->locationColumns;
        }
        columnWalls = 0;
        startLine = startLine + this->locationLines;
    }

    this->setProgSkills();
    this->setInstructor();
}

void Maze::drawMaze() {
    //ncurses draw all locations
    clear();
    
    for(int i = 0; i < this->dimension; i++) {
        for(int j = 0; j < this->dimension; j++) {
            this->locations[i][j]->drawLocation(stdscr);
        }
    }


    this->drawProgSkills();
    this->drawInstructor();

    this->border.drawLocation(stdscr); //draw border

    this->drawControls();
    for(int i = 0; i < this->numTAs; i++) {
        this->tas[i]->getMove(this->student);
        this->tas[i]->drawTa(stdscr);
    }
    this->StudProgSkillCheck();
    mvwaddch(stdscr, this->student->getMpLine(), this->student->getMpColumn(), this->student->getDisplayChar());
    //wmove(stdscr, this->studCoord.getLine(), this->studCoord.getColumn());
    wmove(stdscr, this->student->getMpLine(), this->student->getMpColumn());
    refresh();
    wrefresh(this->controlsWin);
}

void Maze::drawControls() {
    this->controlsWin = newwin(15, 20, 0, this->mazeColumns);
    box(this->controlsWin, 0, 0);
    wmove(this->controlsWin, 1, 1);
    wprintw(this->controlsWin, "w - move up");
    wmove(this->controlsWin, 2, 1);
    wprintw(this->controlsWin, "s - move down");
    wmove(this->controlsWin, 3, 1);
    wprintw(this->controlsWin, "a - move left");
    wmove(this->controlsWin, 4, 1);
    wprintw(this->controlsWin, "d - move right");
    wmove(this->controlsWin, 5, 1);
    wprintw(this->controlsWin, "p - appease TA");
    wmove(this->controlsWin, 6, 1);
    wprintw(this->controlsWin, "i - AI move");
    wmove(this->controlsWin, 7, 1);
    wprintw(this->controlsWin, "q - quit");

    string ps = "Prog Skills: " + to_string((this->student->getProgSkills()));
    
    wmove(this->controlsWin, 10, 1);
    wprintw(this->controlsWin, ps.c_str());

}



void Maze::tryNorth() {

    int testLine = this->student->getMpLine() - 1;
    int testColumn = this->student->getMpColumn();
    int ch = mvinch(testLine, testColumn);
    
    if(ch == OPENSPACE || ch == 36 || ch == 37) {
        this->getStudCoord()->mvNorth();
    }
    //ofstream fout;
    //fout.open("test.txt", ios::app);
    //fout << "ch read: " << ch << "     A_INVIS ch: " << A_INVIS << endl;
    //fout.close();
}
void Maze::trySouth() {
    ofstream fout;

    fout.open("test.txt", ios::app);
    int testLine = this->student->getMpLine() + 1;
    int testColumn = this->student->getMpColumn();
    int ch = mvinch(testLine, testColumn);
    //fout << "ch read: " << ch <<  endl;
    if(ch == OPENSPACE || ch == 36 || ch == 37) {
        this->getStudCoord()->mvSouth();
    }
    fout.close();
}
void Maze::tryEast() {
     int testLine = this->student->getMpLine();
    int testColumn = this->student->getMpColumn() + 1;
    int ch = mvinch(testLine, testColumn);
    if(ch == OPENSPACE || ch == 36 || ch == 37) {
        this->getStudCoord()->mvEast();
    }
}
void Maze::tryWest() {
    int testLine = this->student->getMpLine();
    int testColumn = this->student->getMpColumn() - 1;
    int ch = mvinch(testLine, testColumn);
    if(ch == OPENSPACE || ch == 36 || ch == 37) {
        this->getStudCoord()->mvWest();
    }
}

void Maze::endMaze() {
    clear();
    //delete dereferenced border and all maze objects
    for(int i = 0; i < this->dimension; i++) {
        for(int j = 0; j < this->dimension; j++) {
            delete this->locations[i][j];
            this->locations[i][j] = NULL;
        }
    }

    for(int i = 0; i < this->numProgSkills; i++) {
        delete this->progskills[i];
    }
    for(int i = 0; i < this->numTAs; i++) {
        delete this->tas[i];
    }
    delete this->instructor;
    delete this->student;

    delwin(this->controlsWin);
    delwin(stdscr);
    endwin();
}

void Maze::restartMaze(int d) {
    clear();
    //delete dereferenced border and all maze objects
    for(int i = 0; i < this->dimension; i++) {
        for(int j = 0; j < this->dimension; j++) {
            delete this->locations[i][j];
            this->locations[i][j] = NULL;
        }
    }

    for(int i = 0; i < this->numProgSkills; i++) {
        delete this->progskills[i];
    }
    for(int i = 0; i < this->numTAs; i++) {
        delete this->tas[i];
    }
    delete this->instructor;
    delete this->student;
    this->startMaze(d);
}

MazeLocation* Maze::getLocation(Coordinate& coord) {

    for(int c = 0; c < this->dimension; c++) {
        for(int l = 0; l < this->dimension; l++) {
            if(coord.getLine() == l && coord.getColumn() == c) {
                return this->locations[c][l];
            }
        }
    }
}



int Maze::testStudent() {
    ofstream fout;
    fout.open("test.txt", ios::app);
    bool onTa = false;
    int taNum = 0;
    bool onInstructor = false;
    for(int i = 0; i < this->numTAs; i++) { 

        float dis = this->student->getCoord()->getDistance(this->tas[i]->getMpLine(), this->tas[i]->getMpColumn());
        //fout << "distance: " << dis << endl;
        //fout.close();
        if (dis < 2) {
            taNum = i;
            onTa = true;
        } else {
        }
    }

    if (this->getStudCoord()->isSame(this->instructor) == true) {
            onInstructor = true;
    } else {
    }
    //fout << "OnTa: " << onTa << "onInstructor: "<< onInstructor << endl;
    if(onTa == true && this->tas[taNum]->getIsAppeased() == false) {
        return 0; // end game lost
    } else  if(onInstructor == true){
        return 1; //end game won
    } else {
        return 2; // nothing
    }
    fout.close();
}

void Maze::tryAppease() {
    bool taAppeased = false;
    for(int i = 0; i < this->numTAs; i++) {
        float dis = this->student->getCoord()->getDistance(this->tas[i]->getMpLine(), this->tas[i]->getMpColumn());
        if(dis < 6 && this->student->getProgSkills() > 0) {
            this->tas[i]->setIsAppeased(true);
            this->student->setProgSkills((this->student->getProgSkills() - 1));
            taAppeased = true;
        }
    }
}

void Maze::setProgSkills() {

    this->progskills.resize(this->numProgSkills, NULL);

    srand(time(NULL));
    for (int i = 0; i < this->numProgSkills; i++) {
        int l = rand() % this->dimension;
        int c = rand() % this->dimension;

        while(!this->locations[l][c]->isOccupiable()) {
            l = rand() % this->dimension;
            c = rand() % this->dimension;  
        }
        int line = this->locations[l][c]->getMidLine();
        int col = this->locations[l][c]->getMidColumn();
        this->progskills[i] = new Coordinate(line, col);
        
    }
}

void Maze::setInstructor() {
    int line = this->locations[(this->dimension - 1)][(this->dimension - 1)]->getMidLine();
    int col = this->locations[(this->dimension - 1)][(this->dimension - 1)]->getMidColumn();
    this->instructor = new Coordinate(line, col);
}

void Maze::drawProgSkills() {
    for(int i = 0; i < this->numProgSkills; i++) {
        mvwaddch(stdscr, this->progskills[i]->getLine(), this->progskills[i]->getColumn(), PROGSKILL);
    }
}

void Maze::drawInstructor() {
    mvwaddch(stdscr, this->instructor->getLine(), this->instructor->getColumn(), INSTRUCTOR);
}

void Maze::StudProgSkillCheck() {
    bool getProgSkill = false;
    for(int i = 0; i < this->numProgSkills; i++) {
        if(this->student->getCoord()->isSame(this->progskills[i]) == true && getProgSkill == false) {
            this->student->setProgSkills(this->student->getProgSkills() + 1);
            delete this->progskills[i];
            this->progskills.erase((this->progskills.begin() + i));
            this->numProgSkills = (this->numProgSkills - 1);
            getProgSkill = true;
        } 
    }
}

bool Maze::getAIset() const{
    return this->aiSet;
}
void Maze::setAIset(const bool) {

}

char Maze::AImove() {

    ofstream fout;
    fout.open("test.txt", ios::app);
    

    //float ** closestMoves = new float[(this->numTAs)][2];
    vector<vector<float>> closestMvs;
    closestMvs.resize(this->numTAs, vector<float>(3, 0));

    for(int i = 0; i < this->numTAs; i++) {
        float dis = this->student->getCoord()->getDistance(this->tas[i]->getMpLine(), this->tas[i]->getMpColumn());
        if(dis < 6 && this->student->getProgSkills() > 0) {
            return 'p';
        }
    }
    for(int i = 0; i < this->numTAs; i++) {
        closestMvs[i][0] = static_cast<float>(i);
        float upDis = this->student->getCoord()->getDistance(this->progskills[i]->getLine() + 1, this->progskills[i]->getColumn());
        float downDis = this->student->getCoord()->getDistance(this->progskills[i]->getLine() - 1, this->progskills[i]->getColumn());
        float leftDis = this->student->getCoord()->getDistance(this->progskills[i]->getLine(), this->progskills[i]->getColumn() + 1);
        float rightDis = this->student->getCoord()->getDistance(this->progskills[i]->getLine(), this->progskills[i]->getColumn() - 1);
        float distances[4] = {upDis, downDis, leftDis, rightDis}; 

        //use for detecting how close ta is to student for appeasing and game ending
        float temp = distances[0];
        for(int i = 0; i < 4; i++) {
            if(distances[i] < temp) {
                temp = distances[i];
            }
        }
        bool mvMade = false;

        /*
        closestMvs[i][0] == i // i = numTA in this->tas[i]

        closestMvs[i][1] == dis // closest distance of this->ta[i]
        
        // move that this->student should make to get to closest TA
        closestMvs[i][2] == 0 // move is up
        closestMvs[i][2] == 1 // move is down
        closestMvs[i][2] == 2 // move is left
        closestMvs[i][2] == 3 // move is right
        */
        if(temp == upDis && mvMade != true) {
            //up is fastest to student
            int testLine = this->student->getCoord()->getLine() - 1;
            int testColumn = this->student->getCoord()->getColumn();
            int ch = mvinch(testLine, testColumn);
            if(ch == OPENSPACE || ch == 36 || ch == 37) {
                //this->student->getCoord()->mvNorth();
                closestMvs[i][1] = temp;
                closestMvs[i][2] = 0;
                mvMade = true;
            } else {
            }
            
        } else if(temp == downDis && mvMade != true) {
            //down is fastest to student
            int testLine = this->student->getCoord()->getLine() + 1;
            int testColumn = this->student->getCoord()->getColumn();
            int ch = mvinch(testLine, testColumn);
            if(ch == OPENSPACE || ch == 36 || ch == 37) {
                //this->student->getCoord()->mvSouth();
                closestMvs[i][1] = temp;
                closestMvs[i][2] = 1;
                mvMade = true;
            }else {
            }
        } else if(temp == leftDis && mvMade != true) {
            //left is fastest to student
            int testLine = this->student->getCoord()->getLine();
            int testColumn = this->student->getCoord()->getColumn() - 1;
            int ch = mvinch(testLine, testColumn);
            if(ch == OPENSPACE || ch == 36 || ch == 37) {
                //this->student->getCoord()->mvWest();
                closestMvs[i][1] = temp;
                closestMvs[i][2] = 2;
                mvMade = true;
            }else {
            }
        } else if(temp == rightDis && mvMade != true) {
            //right is fastest to student
            int testLine = this->student->getCoord()->getLine();
            int testColumn = this->student->getCoord()->getColumn() + 1;
            int ch = mvinch(testLine, testColumn);
            if(ch == OPENSPACE || ch == 36 || ch == 37) {
                //this->student->getCoord()->mvEast();
                closestMvs[i][1] = temp;
                closestMvs[i][2] = 3;
                mvMade = true;
            }else {
            }
        } else {
            //something wrong
        }
    }
    for(int i = 0; i < this->numTAs; i ++){
        fout << "ProgSkill#: " << closestMvs[i][0] << "     Distance: " << closestMvs[i][1] << "     MoveInt: " << closestMvs[i][2] << endl;
    }
    float temp = closestMvs[0][1];
    vector<float> mvMake = closestMvs[0];
    
    for(int i = 0; i < 4; i++) {
        if(closestMvs[i][1] < temp) {
            temp = closestMvs[i][1];
            mvMake = closestMvs[i];
        }
    }
    //fout << "ProgSkill#: " << mvMake[0] << "     Distance: " << mvMake[1] << "     MoveInt: " << mvMake[2] << endl;
    int dir = static_cast<int>(mvMake[2]);

    switch(dir) {
        case 0:
            //this->student->getCoord()->mvNorth();
            return 'w';
            break;
        case 1:
            //this->student->getCoord()->mvSouth();
            return 's';
            break;
        case 2:
            //this->student->getCoord()->mvWest();
            return 'a';
            break;
        case 3:
            //this->student->getCoord()->mvEast();
            return 'd';
            break;
    }
    fout.close();
}

void Maze::AITryMove(char mv) {

    switch(mv) {
        case 'w': 
            this->tryNorth();
            break;
        case 'a': 
            this->tryWest();
            break;
        case 's':
            this->trySouth();
            break;
        case 'd':
            this->tryEast();
            break;
        case 'p':
            this->tryAppease();
            break;
    }
}



