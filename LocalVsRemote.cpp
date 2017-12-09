//
// Created by inbal on 05/12/17.
//

#include "LocalVsRemote.h"

LocalVsRemote::LocalVsRemote(Symbol currentPlayer) : Player(currentPlayer) {}

LocalVsRemote::LocalVsRemote(Symbol currentPlayer, Client *client): Player(currentPlayer) {
    this->client=client;
}



Point LocalVsRemote::makeMove(vector<Point> possibleMoves , Board &b) {
    if (possibleMoves.empty()) {
        char msg[7] = {"NoMove"};
        client->sendMove(msg);
        Point p(0 , 0);
        return p;

    } else {
        int col = -1, row = -1;
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
        char msg[7];

        char r = (char)row;

        msg[0]= r;
        cout << msg[0];

        char c = (char)col;

        msg[1]= c;
        client->sendMove(msg);
        return (Point(row , col));
    }

}

