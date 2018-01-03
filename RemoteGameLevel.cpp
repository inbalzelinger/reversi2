//
// Created by hadar on 02/01/18.
//

#include "RemoteGameLevel.h"


#include <unistd.h>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include "GameLevel.h"
#include "LocalVsRemote.h"
#include "RemotePlayer.h"


RemoteGameLevel:: RemoteGameLevel(Client &client,ConsoleDisplay &consoleDisplay, char returnedSymbol): client(&client)
        ,consoleDisplay(&consoleDisplay) {
    if (returnedSymbol == '1') {
        consoleDisplay.whoAmIMassage(returnedSymbol);
        this->blackPlayer = new LocalVsRemote(X, client);
        this->whitePlayer=new RemotePlayer(O, client);
        localPlayer=X;
    } else if (returnedSymbol == '2') {
        consoleDisplay.whoAmIMassage(returnedSymbol);
        this->whitePlayer = new LocalVsRemote(O, client);
        this->blackPlayer=new RemotePlayer(X, client);
        localPlayer=O;
    }
    board = new Board(3);
   logic = new ConsoleLogic;

}





void RemoteGameLevel::play()  {
    int numX = 0;
    int numO = 0;
    Point p;
    Point notValid(0 , 0);
    Point exitServer(-1,-1);
    vector<Point> optionsBlack;
    vector<Point> optionsWhite;
    while (board->count(this->blackPlayer->getSign()) != 0 &&
           board->count(this->whitePlayer->getSign()) != 0) {
        optionsBlack = this->turn(this->blackPlayer->getSign());
        if (!optionsBlack.empty()) {
            if (localPlayer==X) {
                consoleDisplay->showStepsOptions(optionsBlack);
            }
            p = blackPlayer->makeMove(optionsBlack, *this->board);
            if(p==exitServer){
                return;
            }
            if (!(p == notValid)) {
                this->board->addToBoard(p.getRow(), p.getCol(), blackPlayer->getSign());
                this->logic->upside(blackPlayer->getSign(), p.getRow(), p.getCol(), *this->board);
                if(localPlayer==O){
                    consoleDisplay->showRemotePlayerMove(X,p);
                }
            }
        }
        else{
            p = blackPlayer->makeMove(optionsBlack, *this->board);
        }
        optionsWhite = this->turn(this->whitePlayer->getSign());
        if (!optionsWhite.empty()) {
            if (localPlayer==O) {
                consoleDisplay->showStepsOptions(optionsWhite);
            }
            p = whitePlayer->makeMove(optionsWhite, *this->board);
            if(p==exitServer){
                return;
            }
            if (!(p == notValid)) {
                this->board->addToBoard(p.getRow(), p.getCol(), whitePlayer->getSign());
                this->logic->upside(whitePlayer->getSign(), p.getRow(), p.getCol(), *this->board);
                if(localPlayer==X){
                    consoleDisplay->showRemotePlayerMove(O,p);
                }
            }
        }
        else{
            p = whitePlayer->makeMove(optionsWhite, *this->board);
        }
        if (optionsBlack.empty() && optionsWhite.empty()||
            (board->count(blackPlayer->getSign())+board->count(whitePlayer->getSign()))==board->getSize()*board->getSize()) {
            char endMassage[7]={"E" "N" "D"};
            write(this->client->getSocket(), endMassage, sizeof(endMassage));
            break;
        }
    }
    numX = board->count(this->blackPlayer->getSign());
    numO = board->count(this->whitePlayer->getSign());
    cout<<*board;
    Symbol winnerSymbol=empty;
    int winnerScore=0;
    if (numX > numO) {
        winnerSymbol=X;
        winnerScore=numX;
    } else if (numO > numX) {
        winnerSymbol=O;
        winnerScore=numO;
    }
    consoleDisplay->showEndingStatus(winnerSymbol,winnerScore);
}


RemoteGameLevel::~RemoteGameLevel() {
    delete logic;
    //delete client;
    delete whitePlayer;
    delete blackPlayer;

}



vector<Point> RemoteGameLevel::turn(Symbol playerSign) {
    vector<Point> playersOptions = this->logic->PossibleMoves(playerSign , *this->board);
    bool isPossibleToMove=!playersOptions.empty();
    consoleDisplay->showTurnMessage(playerSign,isPossibleToMove,*board);
    return playersOptions;
}




