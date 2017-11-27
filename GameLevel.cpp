//
// Name: Inbal Zelinger
// ID: 311247340
//

#include "GameLevel.h"
#include "ConsoleLogic.h"


GameLevel::GameLevel(Board &b,int playerChoice): playerChoice(playerChoice),board(&b) , blackTurn(true) , whiteTurn(false) {
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
    vector<Point> playesOptions = this->logic->PossibleMoves(playerSign , *this->board);
    char playerSymbol;
    if (!playesOptions.empty()) {
        cout<<*this->board;
        switch (playerSign){
            case X:
                playerSymbol='X';
            case O:
                playerSymbol='O';
        }
        cout << playerSymbol <<" its your turn" << endl;
    } else {
        cout<<playerSymbol<<":"<<"no possible moves for you"<<endl;
    }
    return playesOptions;
}




void GameLevel::play() {
    int numX = 0;
    int numO = 0;
    Point p;
    vector<Point> optionsBlack;
    vector<Point> optionsWhite;
    while (this->points(*this->blackPlayer)!=0 && this->points(*this->whitePlayer)!=0) {
        optionsBlack = this->turn(this->blackPlayer->getSign());
        if (!optionsBlack.empty()) {
          p = blackPlayer->makeMove(optionsBlack ,  *this->board);
            this->board->addToBoard(p.getRow() , p.getCol() , blackPlayer->getSign());
            this->logic->upside(blackPlayer->getSign() , p.getRow() , p.getCol() , *this->board);
        }
        optionsWhite = this->turn(this->whitePlayer->getSign());
        if (!optionsWhite.empty()) {
           p = whitePlayer->makeMove(optionsWhite , *this->board);
            this->board->addToBoard(p.getRow() , p.getCol() , whitePlayer->getSign());
            this->logic->upside(whitePlayer->getSign() , p.getRow() , p.getCol() , *this->board);
        }
        if (optionsBlack.empty() && optionsWhite.empty()) {
            break;
        }
    }
    numX = this->points(*this->blackPlayer);
    numO = this->points(*this->whitePlayer);
    cout<<*board;
    if (numX > numO) {
        cout<<"X you win with: "<<numX<<" points" <<endl;
    } else if (numO > numX) {
        cout<<"O you win with: "<<numO<<" points" <<endl;
    } else {
        cout<<"its a tie" <<endl;
    }
}
