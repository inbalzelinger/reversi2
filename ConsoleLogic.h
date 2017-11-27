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
#include "ConsoleLogic.h"

class ConsoleLogic : public Logic{
private:

public:

    ConsoleLogic();

    vector<Point> PossibleMoves(char playerSigh , Board &b) const;

    void upside(char playerSigh , const int row , const int col , Board &b);


    };


#endif //UNTITLED2_CONSOLELOGIC_H
