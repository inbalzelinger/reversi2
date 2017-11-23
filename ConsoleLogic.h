//
// Name: Inbal Zelinger
// ID: 311247340
//

#ifndef UNTITLED2_GAMELOGIC_H
#define UNTITLED2_GAMELOGIC_H


#include <vector>
#include "Point.h"
#include "Board.h"
#include "Logic.h"

class GameLogic : public Logic{
private:
    Board* board;

public:
    GameLogic(Board& b);

    GameLogic();

    vector<Point> PossibleMoves(char playerSigh) const;

};


#endif //UNTITLED2_GAMELOGIC_H
