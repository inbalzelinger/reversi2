//
// Created by hadar on 02/01/18.
//

#ifndef REVERSITESTS_REMOTEGAMELEVEL_H
#define REVERSITESTS_REMOTEGAMELEVEL_H


#include "Client.h"
#include "ConsoleDisplay.h"
#include "Player.h"
#include "ConsoleLogic.h"

class RemoteGameLevel {
public:
    RemoteGameLevel(Client &client , ConsoleDisplay &consoleDisplay, char returnedSymbol);
    void play();
    vector<Point> turn(Symbol playerSign);
    ~RemoteGameLevel();

private:
    Client* client;
    ConsoleDisplay* consoleDisplay;

    Player* blackPlayer;
    Player* whitePlayer;
    Board* board;
    ConsoleLogic* logic;
    Symbol localPlayer;



};


#endif //REVERSITESTS_REMOTEGAMELEVEL_H
