

#ifndef UNTITLED2_LOGIC_H
#define UNTITLED2_LOGIC_H


#include "Player.h"

class Logic {
public:
    /**
    *return a list of board cells witch are possible moves for the given player
    * @param player
    * @return vector of board cells
    */
   virtual vector<Point> PossibleMoves(Symbol playerSigh) ;


};


#endif //UNTITLED2_LOGIC_H
