//
// Created by hadar on 23/11/17.
//

#include <map>
#include "AIPlayer.h"
#include "Board.h"
#include "ConsolePlayer.h"
#include "ConsoleLogic.h"



AIPlayer::AIPlayer() {
    this->sigh = ' ';
}

AIPlayer::AIPlayer(char currentPlayer) {
    this->sigh = currentPlayer;
};



Point AIPlayer::makeMove(vector<Point> possibleMoves , Board &b) {

    Board imageneriBoard(b.getSize());
    ConsolePlayer imageneryOponent('X');
    vector<Point> imageneryOponentMoves;
    GameLogic logic(b);
    int minPossibleScore = b.getSize()*b.getSize();
    Point movePoint;
    int place = 0;
    int oponentPossibleScore = 0;


    for (int p = 0; p < possibleMoves.size() ; p++){

        imageneriBoard = b;
        imageneriBoard.addToBoard(possibleMoves[p].getX() ,possibleMoves[p].getY() , this->sigh);
        imageneriBoard.upside(this->sigh , possibleMoves[p].getY() , possibleMoves[p].getX());
        imageneryOponentMoves = logic.PossibleMoves('X');



        for (Point p1: imageneryOponentMoves) {
            imageneriBoard.addToBoard(p1.getX() , p1.getY() , 'X');
            imageneriBoard.upside('X' , p1.getY() , p1.getX());
            for (int i = 0; i < b.getSize() ; i++) {
                for (int j = 0; j < b.getSize() ; j++) {
                    if (imageneriBoard.getBoard()[i][j] == 'X') {
                        oponentPossibleScore++;
                    }
                }
            }
            if (oponentPossibleScore < minPossibleScore) {
                ;
            }
        }
    }
    return Point(4 , 2);
}









char AIPlayer::getSigh() {
    return Player::getSigh();
}
