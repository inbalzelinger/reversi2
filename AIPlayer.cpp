//
// Created by hadar on 23/11/17.
//

#include <map>
#include "AIPlayer.h"
#include "ConsoleLogic.h"


AIPlayer::AIPlayer(Symbol currentPlayer):Player(currentPlayer){};



Point AIPlayer::makeMove(vector<Point> possibleMoves , Board &b) {
    int numX = 0;
    int numO = 0;
    int maxNumZ = 0;
    std::map<int, Point> maxScoreOfMoves;
    Board copyOfB(b);
    Board imageneriBoard = copyOfB;
    vector<Point> imageneryOponentMoves;

    ConsoleLogic logic;




    for (int p = 0; p < possibleMoves.size(); p++) {
        imageneriBoard = copyOfB;
        imageneriBoard.addToBoard(possibleMoves[p].getRow(), possibleMoves[p].getCol(), O);
        logic.upside(O, possibleMoves[p].getRow(), possibleMoves[p].getCol(), imageneriBoard);


        imageneryOponentMoves = logic.PossibleMoves(X, imageneriBoard);
        maxNumZ = 0;
        for (int k = 0; k < imageneryOponentMoves.size(); k++) {
            Board copyOfImaginaryBoard(imageneriBoard);
            Board imageneriBoard2 = copyOfImaginaryBoard;
            imageneriBoard2.addToBoard(imageneryOponentMoves[k].getRow(), imageneryOponentMoves[k].getCol(), X);
            logic.upside(X, imageneryOponentMoves[k].getRow(), imageneryOponentMoves[k].getCol(), imageneriBoard2);

            numX = imageneriBoard2.count(X);
            numO = imageneriBoard2.count(O);
            if (numX - numO > maxNumZ) {
                maxNumZ = numX - numO;
            }
        }
        maxScoreOfMoves[maxNumZ] = possibleMoves[p];

    }
    int k = maxScoreOfMoves.rbegin()->first;
    for (std::map<int, Point>::iterator iter = maxScoreOfMoves.begin(); iter != maxScoreOfMoves.end(); ++iter) {
        int current = iter->first;
        if (current < k) {
            k = current;
        }
        return maxScoreOfMoves[k];
    }
}
