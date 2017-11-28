

#ifndef UNTITLED2_CONSOLEPLAYER_H
#define UNTITLED2_CONSOLEPLAYER_H


#include "Player.h"

class ConsolePlayer : public Player{
private:
    Symbol sign;


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
    ConsolePlayer(Symbol currentPlayer);

    /**
* function name: makeMove
* makes one move at the play.
**/

    Point makeMove(vector<Point> possibleMoves , Board &b);


    /**
* function name: getCurrentPlayer
* makes one move at the play.
**/

    Symbol getSign();



};


#endif //UNTITLED2_CONSOLEPLAYER_H
