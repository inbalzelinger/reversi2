//
// Name: Inbal Zelinger
// ID: 311247340
//

#include "Board.h"
#include "GameLevel.h"
#include "Point.h"


int main() {
    int playerChoice;
    Board board(4);
    cout <<"enter 1 for human player"<<endl<<"enter 2 for AI player"<<endl;
    cin >> playerChoice;
    GameLevel gameLevel(board,playerChoice);
    gameLevel.play();
}

