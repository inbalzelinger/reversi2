

#include "ConsoleDisplay.h"
using namespace std;

void ConsoleDisplay::showMenu() {
    cout <<"enter 1 for local human player"<<endl<<"enter 2 for AI player"<<endl
         <<"enter 3 for remote player"<<endl;
}
void ConsoleDisplay::showTurnMessage(Symbol playerSymbol, bool isPossibleToMove,Board &board) {
    char symbolToPrint;
    switch (playerSymbol){
        case X:
            symbolToPrint='X';
            break;
        case O:
            symbolToPrint='O';
            break;
    }
    if (isPossibleToMove) {
        cout<<board<<endl;
        cout <<"its "<<symbolToPrint<<" turn" << endl;
    } else {
        cout<<"no possible moves for "<<symbolToPrint<<endl;
    }
}


void ConsoleDisplay::showEndingStatus(Symbol winnerSymbol,int points) {
    char symbolToPrint;
    switch (winnerSymbol){
        case X:
            symbolToPrint='X';
            break;
        case O:
            symbolToPrint='O';
            break;
    }
    if (winnerSymbol!=empty){
        cout<< symbolToPrint <<" you win with: "<<points<<" points" <<endl;
    } else {
        cout<<"its a tie" <<endl;
    }
}

void ConsoleDisplay::showStepsOptions(vector<Point> moves) {
    cout << "your options are:" << endl;
    for (int i = 0; i < moves.size(); i++) {
        cout << moves[i] << " ";
    }
    cout <<endl << "enter your move row Space then col" << endl;
}

void ConsoleDisplay::showRemotePlayerMove(Symbol symbol,Point point) {
    char symbolToPrint;
    switch (symbol) {
        case X:
            symbolToPrint = 'X';
            break;
        case O:
            symbolToPrint = 'O';
            break;
    }
    if (point == Point(0, 0)) {
        cout << symbolToPrint << " didn't move" << endl;
    } else {
        cout << symbolToPrint << " played " << point << endl;
    }
}

void ConsoleDisplay::firstConnectionMassage() {
    cout<<"waiting for another player to connect.."<<endl;
}
void  ConsoleDisplay::whoAmIMassage(char symbol){
    char symbolToPrint;
    switch (symbol) {
        case '1':
            symbolToPrint = 'X';
            break;
        case '2':
            symbolToPrint = 'O';
            break;
    }
    cout<<"you are "<<symbolToPrint<<endl;
}




