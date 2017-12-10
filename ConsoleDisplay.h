

#ifndef UNTITLED2_CONSOLEDISPLAY_H
#define UNTITLED2_CONSOLEDISPLAY_H

#include "Symbol.h"
#include "Board.h"
#include <vector>


class ConsoleDisplay {

public:

    /**
* function name: showMenu
* prints the menu of the game.
* @return void.
**/
    void showMenu();

    /**
* function name: showTurnMessage
* prints the messages which represent the current turn.
* @param board , isPossibleToMove , playerSymbol
* @return void.
**/
    void showTurnMessage(Symbol playerSymbol, bool isPossibleToMove, Board &board);

    /**
* function name: showEndingStatus
* prints the the winner and his points number.
* @param points , winnerSymbol.
* @return void.
**/

    void showEndingStatus(Symbol winnerSymbol, int points);


    /**
* function name: showStepsOptions
* prints the possible steps.
* @param moves.
* @return void.
**/

    void showStepsOptions(vector<Point> moves);

    /**
     * print what move the other player played
     * @param symbol
     * @param point
     */
    void showRemotePlayerMove(Symbol symbol, Point point);

    /**
 * print massage to first client
 */
    void firstConnectionMassage();
/**
 * prints what is the player symbol;
 */
    void whoAmIMassage(char symbol);
};
#endif //UNTITLED2_CONSOLEDISPLAY_H
