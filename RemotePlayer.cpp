//
// Created by inbal on 05/12/17.
//

#include <map>
#include <unistd.h>
#include "RemotePlayer.h"
#include "ConsoleLogic.h"
#include "Client.h"

RemotePlayer::RemotePlayer(Symbol currentPlayer) : Player(currentPlayer) {
    this->client = new Client("127.0.0.1" , 8000);
    try {
        client->connectToServer();
    }catch (const char* msg){
        cout<<msg<<endl;
    }
}

Point RemotePlayer::makeMove(vector<Point> possibleMoves , Board &b) {
    char buff[3];
    read(client->getSocket() , buff , sizeof(buff));
    int row = buff[0];
    int col = buff[2];
    return (Point(row , col));
}

