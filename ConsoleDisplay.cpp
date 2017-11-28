//
// Created by hadar on 28/11/17.
//

#include "ConsoleDisplay.h"
#include "iostream"
using namespace std;

void ConsoleDisplay::showMenu() {
    cout <<"enter 1 for human player"<<endl<<"enter 2 for AI player"<<endl;
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
        cout << symbolToPrint <<" its your turn" << endl;
    } else {
        cout<<symbolToPrint<<":"<<"no possible moves for you"<<endl;
    }
}
void ConsoleDisplay::showEndingStatus(Symbol winnerSymbol,int points) {
    if (winnerSymbol!=NULL){
        cout<< winnerSymbol <<" you win with: "<<points<<" points" <<endl;
    } else {
        cout<<"its a tie" <<endl;
    }
}

void ConsoleDisplay::showStepsOptions(vector<Point> moves) {
    cout << "your options are:" << endl;
    for (int i = 0; i < moves.size(); i++) {
        cout << moves[i] << " ";
    }
    cout<<endl;
}



