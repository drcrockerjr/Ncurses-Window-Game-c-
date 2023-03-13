/*********************************************************************
** Program Filename: game.h
** Author: Douglas Crocker
** Date: 3/6/2022
** Description: This file defines the main game functions, which handles: game controls, game UI, and gameState
** Input: Dimensions
** Output: Game UI
*********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <ncurses.h>
#include <vector>

#include "mazeLocation.h"
#include "maze.h"

using namespace std;

class Game {
    private:
        int gameState;

        int dimension;

        Maze * maze;

    public:
        Game();
        ~Game();



        void Start(int);
        void End();

        void Exit();

        void GameLost();
        void GameWon();
        void GameQuit();
        void Restart();

        void drawLocations();
        void drawMap();

        void handleControls();
        int returnKey();
        void screenUpdate();

        int getState();

};


#endif