//
// Created by inbal on 05/12/17.
//

#include <map>
#include <unistd.h>
#include <cstring>
#include "RemotePlayer.h"
#include "ConsoleLogic.h"
#include "Client.h"

RemotePlayer::RemotePlayer(Symbol currentPlayer, Client* client) :Player(currentPlayer){
    this->client=client;
}
RemotePlayer::RemotePlayer(Symbol currentPlayer) : Player(currentPlayer) {}




Point RemotePlayer::makeMove(vector<Point> possibleMoves , Board &b) {
    char buff[7];
    read(client->getSocket() , buff , sizeof(buff));
    if(strcmp(buff,"NoMove")==0){
        return Point(0,0);
    }

    int row = buff[0];
    int col = buff[1];
    return (Point(row , col));
}
