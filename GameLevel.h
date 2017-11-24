//
// Name: Inbal Zelinger
// ID: 311247340
//

#ifndef UNTITLED2_GAMELEVEL_H
#define UNTITLED2_GAMELEVEL_H

#include "Board.h"
#include "ConsolePlayer.h"
#include "ConsoleLogic.h"
#include "AIPlayer.h"

class GameLevel {

private:
    bool blackTurn;
    bool whiteTurn;
    Player* blackPlayer;
    Player* whitePlayer;
    Board* board;
    ConsoleLogic* logic;
    int playerChoice;


    /**
* function name: turn
* prints the possible moves and notice the playe ist is turn
*@param playerSigh.
*@return vector<Point>.
**/

    vector<Point> turn(char playerSigh);
    /**
* function name: points
* count the points of the p and return them.
*@param p - player.
*@return int.
**/
    int points(Player &p);



public:


    /**
* function name: GameLevel
* constuctor, construct a new game with the given board.
* @param - board - the game board.

**/

    GameLevel(Board &b, int playerChoice);


    /**
* function name: ~GameLevel
* distructor.
**/




    ~GameLevel();


    /**
* function name: GameLevel
* copy constuctor.
* @param - .

**/

    GameLevel(const GameLevel &gameLevelToCopy);

    /**
* function name: play
* the game logic. 'manage' the game.
**/

    void play();




};


#endif //UNTITLED2_GAMELEVEL_H
