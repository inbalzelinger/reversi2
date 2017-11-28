

#ifndef UNTITLED2_CONSOLELOGIC_H
#define UNTITLED2_CONSOLELOGIC_H


#include <vector>
#include "Point.h"
#include "Board.h"
#include "Logic.h"
#include "ConsoleLogic.h"

class ConsoleLogic : public Logic{
private:

public:

    /**
* function name: ConsoleLogic
*constructor. build consoleLogic
*
**/

    ConsoleLogic();


    /**
* function name: PossibleMoves.
* the function return a vector of possible moves.
* @param playerSigh , b - board.
* @return vector<Point>
*
**/

    vector<Point> PossibleMoves(Symbol playerSigh , Board &b) const;

    /**
* function name: upside
* the function flips the symbols between the point  it gets to the other player sign.
* @param playerSigh , row , col , b - board.
* @return void.
*
**/


    void upside(Symbol playerSigh , const int row , const int col , Board &b);


    };


#endif //UNTITLED2_CONSOLELOGIC_H
