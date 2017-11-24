//
// Created by hadar on 23/11/17.
//

#include <map>
#include "AIPlayer.h"
#include "Board.h"
#include "ConsolePlayer.h"
#include "ConsoleLogic.h"


/*
AIPlayer::AIPlayer() {
    this->sigh = ' ';
}*/

AIPlayer::AIPlayer(char currentPlayer):Player(currentPlayer){};



Point AIPlayer::makeMove(vector<Point> possibleMoves , Board &b) {
    int numX = 0;
    int numO = 0;
    int maxNumZ = 0;
    std::map<int,Point> maxScoreOfMoves;
    Board imageneriBoard(b.getSize());
    Board imageneriBoard2(b.getSize());
    vector<Point> imageneryOponentMoves;
    GameLogic logic(b);
    for (int p = 0; p < possibleMoves.size() ; p++){
        imageneriBoard = b;
        imageneriBoard.addToBoard(possibleMoves[p].getX() ,possibleMoves[p].getY() , this->sigh);
        imageneriBoard.upside(this->sigh , possibleMoves[p].getY() , possibleMoves[p].getX());
        imageneryOponentMoves = logic.PossibleMoves('X');
        maxNumZ=0;
        for (int k = 0; k < imageneryOponentMoves.size() ; k++) {
            imageneriBoard2 = imageneriBoard;
            imageneriBoard2.addToBoard(imageneryOponentMoves[k].getX() , imageneryOponentMoves[k].getY() , 'X');
            imageneriBoard2.upside('X' , imageneryOponentMoves[k].getY() , imageneryOponentMoves[k].getX());
            for (int i = 0; i < b.getSize() ; i++) {
                for (int j = 0; j < b.getSize() ; j++) {
                    if (imageneriBoard2.getBoard()[i][j] == 'X') {
                        numX++;
                    }
                }
            }
            for (int i = 0; i < b.getSize() ; i++) {
                for (int j = 0; j < b.getSize() ; j++) {
                    if (imageneriBoard2.getBoard()[i][j] == 'O') {
                        numO++;
                    }
                }
            }
            if (numX - numO > maxNumZ) {
                maxNumZ = numX - numO;
            }
        }
        maxScoreOfMoves[maxNumZ]=possibleMoves[p];
    }
    //return the p with the min maxNumZ
    return maxScoreOfMoves[maxScoreOfMoves.rbegin()->first];
}

/*
char AIPlayer::getSigh() {
    return Player::getSigh();
}
*/