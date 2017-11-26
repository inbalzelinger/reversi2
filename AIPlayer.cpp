//
// Created by hadar on 23/11/17.
//

#include <map>
#include "AIPlayer.h"
#include "ConsoleLogic.h"


AIPlayer::AIPlayer(char currentPlayer):Player(currentPlayer){};



Point AIPlayer::makeMove(vector<Point> possibleMoves , Board &b) {
    int numX = 0;
    int numO = 0;
    int maxNumZ = 0;
    std::map<int,Point> maxScoreOfMoves;
    Board copyOfB(b);
    Board imageneriBoard = copyOfB;
    vector<Point> imageneryOponentMoves;
    ConsoleLogic logic(imageneriBoard);
    for (int p = 0; p < possibleMoves.size() ; p++){
        imageneriBoard = copyOfB;
        imageneriBoard.addToBoard(possibleMoves[p].getX() ,possibleMoves[p].getY() , this->sigh);
        imageneriBoard.upside(this->sigh , possibleMoves[p].getY() , possibleMoves[p].getX());
        imageneryOponentMoves = logic.PossibleMoves('X');
        maxNumZ=0;
        for (int k = 0; k < imageneryOponentMoves.size() ; k++) {
            Board copyOfImaginaryBoard(imageneriBoard);
            Board imageneriBoard2 = copyOfImaginaryBoard;
            imageneriBoard2.addToBoard(imageneryOponentMoves[k].getX() , imageneryOponentMoves[k].getY() , 'X');
            imageneriBoard2.upside('X' , imageneryOponentMoves[k].getY() , imageneryOponentMoves[k].getX());
            numX = imageneriBoard2.count('X');
            numO = imageneriBoard2.count(this->sigh);
            if (numX - numO > maxNumZ) {
                maxNumZ = numX - numO;
            }
        }
        maxScoreOfMoves[maxNumZ]=possibleMoves[p];
    }
    //return the p with the min maxNumZ
    return maxScoreOfMoves[maxScoreOfMoves.rbegin()->first];
}
