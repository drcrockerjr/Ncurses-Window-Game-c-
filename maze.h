/*********************************************************************
** Program Filename: maze.h
** Author: Douglas Crocker
** Date: 3/6/2022
** Description: This file defines the maze class, which handles: Game terminal UI, Game controls;
** Input: Terminal dimensions
** Output: Game UI, Character Movement, "AI" controls
*********************************************************************/

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "mazeLocation.h"
#include "coordinate.h"
#include "border.h"
#include "intrepidStudent.h"
#include "mazePerson.h"
#include "ta.h"

using namespace std;

class Maze {

    private:
        int dimension;

        vector<vector<MazeLocation*> > locations;

        Border border;

        int mazeLines;
        int mazeColumns;

        int locationColumns = 8;
        int locationLines = 4;

        int wallCap = 8; //cap on number of walls on screen
        int numTAs = 4; // sets number of TAs
        int difficulty = 0; // set to 2 for tracking TA | 0 for normal non-tracking TA
        int numProgSkills = 6;
        bool aiSet = false;

        //Coordinate studCoord;
        //MazeLocation * studentLocation;

        MazePerson * student;
        vector<MazePerson*> tas;
        vector<Coordinate*> progskills;
        Coordinate* instructor;


        WINDOW * terminal;
        WINDOW * controlsWin;

    public:
        Maze();
        //maze(int);
        ~Maze();

        int getMazeLines() const;
        int getMazeColumns() const;

        MazePerson* getStudent();
        Coordinate* getStudCoord();
        WINDOW* getTerminal();

        void startMaze(int);
        void drawMaze();
        void drawControls();

        /*void handleUp();
        void handleDown();
        void handleLeft();
        void handleRight();*/

        void tryNorth();
        void trySouth();
        void tryEast();
        void tryWest();

        void addMazeLocation();

        void endMaze();
        void restartMaze(int);

        MazeLocation* getLocation(Coordinate&);

        int testStudent();
        void tryAppease();

        void setProgSkills();
        void setInstructor();

        void drawProgSkills();
        void drawInstructor();

        void StudProgSkillCheck();

        bool getAIset() const;
        void setAIset(const bool);
        char AImove();
        void AITryMove(char);
};

#endif