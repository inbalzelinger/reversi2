//
// Name: Inbal Zelinger
// ID: 311247340
//

#ifndef UNTITLED2_MOVEMENT_H
#define UNTITLED2_MOVEMENT_H

#include <vector>
#include "Point.h"
#include "Board.h"

class Player {

private:
    char sigh;

public:


    /**
 * function name: Player
 * constuctor, construct a Player by given player sigh.
 * @param - currentPlayer .

**/

    explicit Player(char currentPlayer);



    /**
* function name: Player
* defult constuctor.
**/

    Player();


    /**
* function name: makeMove
* makes one move at the play.
**/

    virtual Point makeMove(vector<Point> possibleMoves , Board &b) = 0;

    /**
* function name: getSigh
* return the sigh of th
**/

    virtual char getSigh();



};



#endif //UNTITLED2_MOVEMENT_H
