//
// Created by inbal on 05/12/17.
//

#ifndef REVERSITESTS_LOCALVSREMOTE_H
#define REVERSITESTS_LOCALVSREMOTE_H


#include "Player.h"
#include "Client.h"

class LocalVsRemote: public Player {
public:
    /**
     * constructors
     * @param currentPlayer
     */
    LocalVsRemote(Symbol currentPlayer);
    LocalVsRemote(Symbol currentPlayer,Client &client);
/**
 * virtual method implementation
 * @param possibleMoves
 * @param b
 * @return point of the move
 */
    Point makeMove(vector<Point> possibleMoves , Board &b);


private:
    Client *client;
    Symbol sign;

};


#endif //REVERSITESTS_LOCALVSREMOTE_H
