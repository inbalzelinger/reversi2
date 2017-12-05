

#include "Board.h"
#include "GameLevel.h"
#include "ConsoleDisplay.h"
#include "Client.h"


int main() {
    Client clientX("127.0.0.1", 8000);
    try {
        clientX.connectToServer();
    }catch (const char* msg){
        cout<<msg<<endl;
    }
    Client clientO("127.0.0.1", 8000);
    try {
        clientO.connectToServer();
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
