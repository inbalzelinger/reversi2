//
// Name: Inbal Zelinger
// ID: 311247340
//

#include "GameLevel.h"
#include "ConsoleLogic.h"


GameLevel::GameLevel(Board &b,int playerChoice,ConsoleDisplay &consoleDisplay): playerChoice(playerChoice),board(&b)
        ,consoleDisplay(&consoleDisplay){
    this->blackPlayer = new ConsolePlayer(X);
    if(playerChoice==1){
    this->whitePlayer = new ConsolePlayer(O);
    } else if(playerChoice==2){
        this->whitePlayer= new AIPlayer(O);
    }
    this->logic = new ConsoleLogic();
}



GameLevel::~GameLevel() {
    delete blackPlayer;
    delete whitePlayer;
    delete logic;

}


int GameLevel::points(Player &p) {
    int num = 0;
    for(int i = 0; i < this->board->getSize(); i++) {
        for (int j = 0; j < this->board->getSize(); j++) {
            if (this->board->getValueAt(i,j) == p.getSign()) {
                num++;
            }
        }
    }
    return num;
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
    while (this->points(*this->blackPlayer) != 0 && this->points(*this->whitePlayer) != 0) {
        optionsBlack = this->turn(this->blackPlayer->getSign());
        if (!optionsBlack.empty()) {
            consoleDisplay->showStepsOptions(optionsBlack);
        }
        p = blackPlayer->makeMove(optionsBlack, *this->board);

        this->board->addToBoard(p.getRow(), p.getCol(), blackPlayer->getSign());
        this->logic->upside(blackPlayer->getSign(), p.getRow(), p.getCol(), *this->board);
        optionsWhite = this->turn(this->whitePlayer->getSign());
        if (!optionsWhite.empty()) {
            consoleDisplay->showStepsOptions(optionsWhite);
        }
        p = whitePlayer->makeMove(optionsWhite, *this->board);
        this->board->addToBoard(p.getRow(), p.getCol(), whitePlayer->getSign());
        this->logic->upside(whitePlayer->getSign(), p.getRow(), p.getCol(), *this->board);

        if (optionsBlack.empty() && optionsWhite.empty()) {
            break;
        }
    }
    numX = board->count(this->blackPlayer->getSign());
    numO = board->count(this->whitePlayer->getSign());
    cout<<*board;
    Symbol winnerSymbol=empty;
    int winnerScore;
    if (numX > numO) {
        winnerSymbol=X;
        winnerScore=numX;
    } else if (numO > numX) {
        winnerSymbol=O;
        winnerScore=numO;
    }
    consoleDisplay->showEndingStatus(winnerSymbol,winnerScore);
}

