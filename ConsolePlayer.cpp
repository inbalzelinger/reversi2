

#include "ConsolePlayer.h"


/*
ConsolePlayer::ConsolePlayer() {
    this->sigh = ' ';*/

ConsolePlayer::ConsolePlayer(Symbol currentPlayer): Player(currentPlayer){};




Point ConsolePlayer::makeMove(vector<Point> possibleMoves , Board &b) {

    int col, row;
    int legalMoves = 0;
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

