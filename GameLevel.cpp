

#include <unistd.h>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include "GameLevel.h"
#include "LocalVsRemote.h"
#include "RemotePlayer.h"


GameLevel::GameLevel(Board &b,int playerChoice,ConsoleDisplay &consoleDisplay): playerChoice(playerChoice),board(&b)
        ,consoleDisplay(&consoleDisplay) {
    if (playerChoice == 1) {
        this->blackPlayer = new ConsolePlayer(X);
        this->whitePlayer = new ConsolePlayer(O);
    } else if (playerChoice == 2) {
        this->blackPlayer = new ConsolePlayer(X);
        this->whitePlayer = new AIPlayer(O);
    }
}




GameLevel::~GameLevel() {
    delete blackPlayer;
    delete whitePlayer;
    delete logic;
    delete client;

}



vector<Point> GameLevel::turn(Symbol playerSign) {
    vector<Point> playersOptions = this->logic->PossibleMoves(playerSign , *this->board);
    bool isPossibleToMove=!playersOptions.empty();
    consoleDisplay->showTurnMessage(playerSign,isPossibleToMove,*board);
    return playersOptions;
}


void GameLevel::play() {
    int numX = 0;
    int numO = 0;
    Point p;
    vector<Point> optionsBlack;
    vector<Point> optionsWhite;
    while (board->count(this->blackPlayer->getSign()) != 0 &&
            board->count(this->whitePlayer->getSign()) != 0) {
        optionsBlack = this->turn(this->blackPlayer->getSign());
        if (!optionsBlack.empty()) {
            consoleDisplay->showStepsOptions(optionsBlack);
            p = blackPlayer->makeMove(optionsBlack, *this->board);
            this->board->addToBoard(p.getRow(), p.getCol(), blackPlayer->getSign());
            this->logic->upside(blackPlayer->getSign(), p.getRow(), p.getCol(), *this->board);
        }
        optionsWhite = this->turn(this->whitePlayer->getSign());
        if (!optionsWhite.empty()) {
            consoleDisplay->showStepsOptions(optionsWhite);
            p = whitePlayer->makeMove(optionsWhite, *this->board);
            this->board->addToBoard(p.getRow(), p.getCol(), whitePlayer->getSign());
            this->logic->upside(whitePlayer->getSign(), p.getRow(), p.getCol(), *this->board);
        }
        if (optionsBlack.empty() && optionsWhite.empty()||
                (board->count(blackPlayer->getSign())+board->count(whitePlayer->getSign()))==board->getSize()*board->getSize()) {
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






