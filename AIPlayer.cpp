

#include <map>
#include "AIPlayer.h"
#include "ConsoleLogic.h"


AIPlayer::AIPlayer(Symbol currentPlayer):Player(currentPlayer){};



Point AIPlayer::makeMove(vector<Point> possibleMoves , Board &b) {
    int numX = 0;
    int numO = 0;
    int maxScoreForMove = 0;
    std::map<int, Point> maxScoreOfMoves;
    Board copyOfB(b);
    Board imaginaryBoard = copyOfB;
    vector<Point> imageneryOponentMoves;

    ConsoleLogic logic;




    for (int p = 0; p < possibleMoves.size(); p++) {
        imaginaryBoard = copyOfB;
        imaginaryBoard.addToBoard(possibleMoves[p].getRow(), possibleMoves[p].getCol(), O);
        logic.upside(O, possibleMoves[p].getRow(), possibleMoves[p].getCol(), imaginaryBoard);


        imageneryOponentMoves = logic.PossibleMoves(X, imaginaryBoard);
        maxScoreForMove = 0;
        for (int k = 0; k < imageneryOponentMoves.size(); k++) {
            Board copyOfImaginaryBoard(imaginaryBoard);
            Board imaginaryBoard2 = copyOfImaginaryBoard;
            imaginaryBoard2.addToBoard(imageneryOponentMoves[k].getRow(), imageneryOponentMoves[k].getCol(), X);
            logic.upside(X, imageneryOponentMoves[k].getRow(), imageneryOponentMoves[k].getCol(), imaginaryBoard2);

            numX = imaginaryBoard2.count(X);
            numO = imaginaryBoard2.count(O);
            if (numX - numO > maxScoreForMove) {
                maxScoreForMove = numX - numO;
            }
        }
        maxScoreOfMoves[maxScoreForMove] = possibleMoves[p];

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
