//
// Name: Inbal Zelinger
// ID: 311247340
//

#ifndef UNTITLED2_CONSOLELOGIC_H
#define UNTITLED2_CONSOLELOGIC_H


#include <vector>
#include "Point.h"
#include "Board.h"
#include "Logic.h"

class ConsoleLogic : public Logic{
private:
    Board* board;

public:
    ConsoleLogic(Board& b);

    ConsoleLogic();

    vector<Point> PossibleMoves(char playerSigh) const;

};


#endif //UNTITLED2_CONSOLELOGIC_H
