//
// Name: Inbal Zelinger
// ID: 311247340
//

#include "ConsolePlayer.h"


/*
ConsolePlayer::ConsolePlayer() {
    this->sigh = ' ';*/

ConsolePlayer::ConsolePlayer(Symbol currentPlayer): Player(currentPlayer){};




Point ConsolePlayer::makeMove(vector<Point> possibleMoves , Board &b) {


    cout << "your options are:" << endl;
    for (int i = 0; i < possibleMoves.size(); i++) {
        cout<<possibleMoves[i]<<" ";
    }

    int col, row;
    int legalMoves = 0;
        cout <<endl << "enter your move row Space then col" << endl;
        while (legalMoves == 0) {
            cin >> row >> col;
            cin.clear();
            cin.ignore(100 , '\n');
            //check if the move is on the list.
            for (int i = 0 ; i < possibleMoves.size(); i++) {
                if (possibleMoves[i] == (Point(row , col))){
                    legalMoves = 1;
                    break;
                }
            }
            if (legalMoves == 0) {
                cout << "your move is illegal, please try again, " << endl;
            }
        }
    possibleMoves.clear();
    return (Point(row , col));
}

