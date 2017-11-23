//
// Created by hadar on 23/11/17.
//

#ifndef UNTITLED2_AIPLAYER_H
#define UNTITLED2_AIPLAYER_H

#include "Player.h"
#include "Board.h"

class AIPlayer: public Player {


private:
    char sigh;


public:

    /**
* function name: Player
* constuctor, construct a Player by given player sigh.
* @param - currentPlayer .

**/
    AIPlayer();


    /**
* function name: Player
* defult constuctor.
**/
    AIPlayer(char currentPlayer);

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



#endif //UNTITLED2_AIPLAYER_H
