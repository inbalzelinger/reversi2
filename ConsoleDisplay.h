//
// Created by hadar on 28/11/17.
//

#ifndef UNTITLED2_CONSOLEDISPLAY_H
#define UNTITLED2_CONSOLEDISPLAY_H

#include "Symbol.h"
#include "Board.h"
#include <vector>


class ConsoleDisplay {

public:
    void showMenu();
    void showTurnMessage(Symbol playerSymbol,bool isPossibleToMove,Board &board);
    void showEndingStatus(Symbol winnerSymbol,int points);
    void showStepsOptions(vector<Point> moves);
};


#endif //UNTITLED2_CONSOLEDISPLAY_H
