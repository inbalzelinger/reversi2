

#include "Board.h"
#include "GameLevel.h"
#include "ConsoleDisplay.h"
#include "Client.h"


int main() {
    Client client("172.18.8.77", 8000);
    try {
        client.connectToServer();
    }catch (const char* msg){
        cout<<msg<<endl;
    }
}
/*
    ConsoleDisplay consoleDisplay;
    int playerChoice;
    Board board(8);
    consoleDisplay.showMenu();
    cin >> playerChoice;
    GameLevel gameLevel(board,playerChoice,consoleDisplay);
    gameLevel.play();
}
*/
