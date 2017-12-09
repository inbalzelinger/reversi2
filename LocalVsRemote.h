//
// Created by inbal on 05/12/17.
//

#ifndef REVERSITESTS_LOCALVSREMOTE_H
#define REVERSITESTS_LOCALVSREMOTE_H


#include "Player.h"
#include "Client.h"

class LocalVsRemote: public Player {
public:
    LocalVsRemote(Symbol currentPlayer);
    LocalVsRemote(Symbol currentPlayer,Client* client);

    Point makeMove(vector<Point> possibleMoves , Board &b);
    void sendEmpty();

private:
    Client *client;
    Symbol sign;

};


#endif //REVERSITESTS_LOCALVSREMOTE_H
