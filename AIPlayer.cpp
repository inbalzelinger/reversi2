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
    for (Point p: possibleMoves) {
        movePoint = p;
        imageneriBoard = b;
        imageneriBoard.addToBoard(p.getX() , p.getY() , this->sigh);
        imageneriBoard.upside(this->sigh , p.getY() , p.getX());
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
    return Point(1 , 1);
}



char AIPlayer::getSigh() {
    return Player::getSigh();
}
