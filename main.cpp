//
// Name: Inbal Zelinger
// ID: 311247340
//

#include "Board.h"
#include "GameLevel.h"
#include "ConsoleDisplay.h"


int main() {
    ConsoleDisplay consoleDisplay;
    int playerChoice;
    Board board(8);
    consoleDisplay.showMenu();
    cin >> playerChoice;
    GameLevel gameLevel(board,playerChoice,consoleDisplay);
    gameLevel.play();
}

