

#include "Board.h"
#include "GameLevel.h"
#include "ConsoleDisplay.h"
#include "Client.h"
#include "RemoteGameFlow.h"


int main() {
    ConsoleDisplay consoleDisplay;
    int playerChoice;
    Board board(8);
    consoleDisplay.showMenu();
    cin >> playerChoice;
    if(playerChoice==3){
        RemoteGameFlow remoteGameFlow(consoleDisplay);
        remoteGameFlow.startRemoteGame();
    } else {
        GameLevel gameLevel(board,playerChoice,consoleDisplay);
        gameLevel.play();
    }
}

