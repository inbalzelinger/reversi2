//
// Name: Inbal Zelinger
// ID: 311247340
//

#include "Board.h"
#include "GameLevel.h"
#include "Point.h"


int main() {
    Board board(8);
    GameLevel gameLevel(board);
    gameLevel.play();
}

