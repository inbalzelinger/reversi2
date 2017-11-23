//
// Name: Inbal Zelinger
// ID: 311247340
//

#include "GameLevel.h"
#include "ConsoleLogic.h"


GameLevel::GameLevel(Board &b,int playerChoice): playerChoice(playerChoice),board(&b) , blackTurn(true) , whiteTurn(false) {
    this->blackPlayer = new ConsolePlayer('X');
    if(playerChoice==1){
    this->whitePlayer = new ConsolePlayer('O');
    } else if(playerChoice==2){
        this->whitePlayer= new AIPlayer('O');
    }
    this->logic = new GameLogic(b);
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
            if (this->board->getBoard()[i][j] == p.getSigh()) {
                num++;
            }
        }
    }
    return num;
}



vector<Point> GameLevel::turn(char playerSigh) {
    int j = 0;
    int flag = 0;
    vector<Point> playesOptions;
    vector<Point> playesOptionsToCheck = this->logic->PossibleMoves(playerSigh);
    if (playesOptions.empty() && !playesOptionsToCheck.empty()) {
        playesOptions.push_back(playesOptionsToCheck[j]);
        j++;
    }
    while (j < playesOptionsToCheck.size()) {
        for (int i = 0; i < playesOptions.size(); i++) {
            if (playesOptions[i] == (playesOptionsToCheck[j])) {
                break;
            } else {
                flag++;
            }
        }
        if (flag == playesOptions.size()) {
            playesOptions.push_back(playesOptionsToCheck[j]);
        }
        flag = 0;
        j++;
    }
    if (!playesOptions.empty()) {
        cout<<*this->board;
        cout << playerSigh <<" its your turn" << endl;
        cout << "your options are:" << endl;
        for (int i = 0; i < playesOptions.size(); i++) {
            cout<<playesOptions[i]<<" ";
        }
    } else {
        cout<<playerSigh<<":"<<"no possible moves for you"<<endl;
    }
    playesOptionsToCheck.clear();
    return playesOptions;
}




void GameLevel::play() {
    int numX = 0;
    int numO = 0;
    Point p;
    vector<Point> optionsBlack;
    vector<Point> optionsWhite;
    while (this->points(*this->blackPlayer)!=0 && this->points(*this->whitePlayer)!=0) {
        optionsBlack = this->turn(this->blackPlayer->getSigh());
        if (!optionsBlack.empty()) {
          p = blackPlayer->makeMove(optionsBlack ,  *this->board);
            this->board->addToBoard(p.getX() , p.getY() , blackPlayer->getSigh());
            this->board->upside(blackPlayer->getSigh() , p.getY() , p.getX());
        }
        optionsWhite = this->turn(this->whitePlayer->getSigh());
        if (!optionsWhite.empty()) {
           p = whitePlayer->makeMove(optionsWhite , *this->board);
            this->board->addToBoard(p.getX() , p.getY() , whitePlayer->getSigh());
            this->board->upside(whitePlayer->getSigh() , p.getY() , p.getX());
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
