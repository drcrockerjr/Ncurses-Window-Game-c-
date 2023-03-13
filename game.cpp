#include <iostream>
#include <string>
#include <ncurses.h>
#include <fstream>
#include <chrono>

#include "game.h"
#include "maze.h"

#define STUDENT '*'
#define WALL '#'

Game::Game() {
    
}

Game::~Game() {
    //this->End();
    clear();
    this->maze->endMaze();
    this->Exit();

    if(this->maze != NULL) {
        delete this->maze;
    }
    exit(0);
}

void Game::Start(int d) {
    this->dimension = d;
    gameState = 1;
    this->maze = new Maze();
    this->maze->startMaze(this->dimension);
}

void Game::End() {
}

void Game::Exit() {
    clear();
    this->maze->endMaze();
    this->maze->~Maze();
    this->gameState = 0; 
    exit(0);
}

void Game::GameLost() {
    clear();
    wmove(stdscr, (this->maze->getMazeLines() / 2), (this->maze->getMazeColumns() / 2));
    wprintw(stdscr, "Game Over");
    wmove(stdscr, ((this->maze->getMazeLines() / 2) + 1), (this->maze->getMazeColumns() / 2));
    wprintw(stdscr, "You Lost");
    wmove(stdscr, ((this->maze->getMazeLines() / 2) + 2), ((this->maze->getMazeColumns() / 2) - 4));
    wprintw(stdscr, "press (q to exit | r to restart)");

    bool selectionMade = false;

    while(selectionMade == false) {
        int in = this->returnKey();
        if(in == 'r') {
            clear();
            selectionMade = true;
            this->Restart();
        } else if(in == 'q') {
            clear();
            selectionMade = true;
            this->gameState = 0;
            this->Exit();
        }
    }
}

void Game::GameWon() {
    clear();
    wmove(stdscr, (this->maze->getMazeLines() / 2), ((this->maze->getMazeColumns() / 2) - 2));
    wprintw(stdscr, "Congratulations!");
    wmove(stdscr, ((this->maze->getMazeLines() / 2) + 1), (this->maze->getMazeColumns() / 2));
    wprintw(stdscr, "You Won");
    wmove(stdscr, ((this->maze->getMazeLines() / 2) + 2), ((this->maze->getMazeColumns() / 2) - 4));
    wprintw(stdscr, "press (q to exit | r to restart)");
    
    bool selectionMade = false;

    while(selectionMade == false) {
        int in = this->returnKey();
        if(in == 'r') {
            clear();
            selectionMade = true;
            this->Restart();
        } else if(in == 'q') {
            clear();
            selectionMade = true;
            this->gameState = 0;
            this->Exit();
        }
    }
}

void Game::GameQuit() {
    clear();
    wmove(stdscr, (this->maze->getMazeLines() / 2), ((this->maze->getMazeColumns() / 2)));
    wprintw(stdscr, "You have Quit");
    wmove(stdscr, ((this->maze->getMazeLines() / 2) + 1), ((this->maze->getMazeColumns() / 2) - 2));
    wprintw(stdscr, "Thank You For Playing");
    wmove(stdscr, ((this->maze->getMazeLines() / 2) + 2), ((this->maze->getMazeColumns() / 2) - 4));
    wprintw(stdscr, "press (q to exit | r to restart)");
    

    bool selectionMade = false;
    while(selectionMade == false) {
        int in = this->returnKey();
        if(in == 'r') {
            clear();
            selectionMade = true;
            this->Restart();
        } else if(in == 'q') {
            clear();
            selectionMade = true;
            this->gameState = 0;
            this->Exit();
        }
    }
    
}

void Game::Restart() {
    this->gameState = 1;
    //this->maze->restartMaze(this->dimension);
    this->Exit();

}


void Game::drawMap() {
    this->maze->drawMaze();
    
}

void Game::handleControls() {

    if (this->maze->testStudent() == 0) {
        this->GameLost();
    } else if(this->maze->testStudent() == 1 && this->maze->getStudent()->getProgSkills() >= 3) {
        this->GameWon();
    } else if(this->maze->testStudent() == 1 && this->maze->getStudent()->getProgSkills() < 3) {
        this->GameLost();
    } else {

    }
    bool mvMade = false;
    
    int move = this->returnKey();

    switch ( move ) {
            case 'w': 
                this->maze->tryNorth();
                break;
            case 'a': 
                this->maze->tryWest();
                break;
            case 's':
                this->maze->trySouth();
                break;
            case 'd':
                this->maze->tryEast();
                break;
            case 'q':
                this->GameQuit();
                break;
            case 'p': 
                this->maze->tryAppease();
                break;
            case 'i':
                //add ai functionality
                this->maze->AITryMove(this->maze->AImove());
                //break;
    }
}

int Game::returnKey() {
    return getch();
}

void Game::screenUpdate() {
    clear();
}

int Game::getState() {
    return this->gameState;
}