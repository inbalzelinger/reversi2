//
// Name: Inbal Zelinger
// ID: 311247340
//

#include "ConsolePlayer.h"



ConsolePlayer::ConsolePlayer() {
    this->sigh = ' ';
}
ConsolePlayer::ConsolePlayer(char currentPlayer) {
    this->sigh = currentPlayer;
}



Point ConsolePlayer::makeMove(vector<Point> possibleMoves , Board &b) {
    int col, row;
    int legalMoves = 0;
        cout <<endl << "enter your move column Space then row" << endl;
        while (legalMoves == 0) {
            cin >> col >> row;
            cin.clear();
            cin.ignore(100 , '\n');
            //check if the move is on the list.
            for (int i = 0 ; i<possibleMoves.size(); i++) {
                if (possibleMoves[i] == (Point(col , row))){
                    legalMoves = 1;
                    break;
                }
            }
            if (legalMoves == 0) {
                cout << "your move is illegal, please try again, " << endl;
            }
        }
    possibleMoves.clear();
    return (Point(col , row));
}


char ConsolePlayer::getSigh() {
    return this->sigh;
}
