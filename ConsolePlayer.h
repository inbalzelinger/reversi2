//
// Name: Inbal Zelinger
// ID: 311247340
//

#ifndef UNTITLED2_CONSOLEPLAYER_H
#define UNTITLED2_CONSOLEPLAYER_H


#include "Player.h"

class ConsolePlayer : public Player{
private:
    char sign;


public:
/*
    /**
* function name: Player
* constuctor, construct a Player by given player sigh.
* @param - currentPlayer .

**
    ConsolePlayer();
*/

    /**
* function name: Player
* defult constuctor.
**/
    ConsolePlayer(char currentPlayer);

    /**
* function name: makeMove
* makes one move at the play.
**/

    Point makeMove(vector<Point> possibleMoves , Board &b);


    /**
* function name: getCurrentPlayer
* makes one move at the play.
**/

    char getSigh();

};


#endif //UNTITLED2_CONSOLEPLAYER_H
