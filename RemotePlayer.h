//
// Created by inbal on 05/12/17.
//

#ifndef REVERSITESTS_REMOTEPLAYER_H
#define REVERSITESTS_REMOTEPLAYER_H


#include "Player.h"
#include "Client.h"

class RemotePlayer: public Player {

private:
    Client* client;

public:
    /**
     * constructor
     * @param currentPlayer
     */
    RemotePlayer(Symbol currentPlayer);

    /**
     * constructor
     * @param currentPlayer
     */
    RemotePlayer(Symbol currentPlayer, Client &client);
    /**
* function name: makeMove
* makes one move at the play.
**/

    Point makeMove(vector<Point> possibleMoves , Board &b);

};


#endif //REVERSITESTS_REMOTEPLAYER_H
