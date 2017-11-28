//
// Name: Inbal Zelinger
// ID: 311247340
//

#ifndef UNTITLED2_MOVEMENT_H
#define UNTITLED2_MOVEMENT_H

#include <vector>
#include "Point.h"
#include "Board.h"
#include "Symbol.h"

class Player {

private:
     Symbol sign;

public:


    /**
 * function name: Player
 * constuctor, construct a Player by given player sigh.
 * @param - currentPlayer .

**/

    Player(Symbol currentPlayer);



    /**
* function name: makeMove
* makes one move at the play.
**/

    virtual Point makeMove(vector<Point> possibleMoves , Board &b) = 0;

    /**
* function name: getSigh
* return the sigh of th
**/

    Symbol getSign();

};



#endif //UNTITLED2_MOVEMENT_H
