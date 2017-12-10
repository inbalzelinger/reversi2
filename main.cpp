

#include "Board.h"
#include "GameLevel.h"
#include "ConsoleDisplay.h"
#include "Client.h"


int main() {

    ConsoleDisplay consoleDisplay;
    int playerChoice;
    Board board(4);
    consoleDisplay.showMenu();
    cin >> playerChoice;
    GameLevel gameLevel(board,playerChoice,consoleDisplay);
    if(playerChoice==3){
        gameLevel.playRemote();
    } else {
        gameLevel.play();
    }
}

