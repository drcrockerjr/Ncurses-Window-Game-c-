#include <iostream>
#include <string>
#include <ncurses.h>

#include "game.h"

//#define STUDENT '*'

using namespace std;

int main(int argc, char **argv) {

    int d;
    cout << "Please enter a valid dimension: " << endl;
    cin >> d;

    if(d < 5) {
        cout << "Please enter a size dimension above 5: " << endl;
        cin >> d;
    } 

    Game game;
    game.Start(d);
    
    while(game.getState() != 0) {

        game.drawMap();

        game.handleControls();
 
    }

    return 0;
}


