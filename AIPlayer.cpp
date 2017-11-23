//
// Created by hadar on 23/11/17.
//

#include "AIPlayer.h"

AIPlayer::AIPlayer(char currentPlayer) {
    this->sigh = ' ';
};

AIPlayer::AIPlayer() {};

Point AIPlayer::makeMove(vector<Point> possibleMoves) {
    return Point();
}

char AIPlayer::getSigh() {
    return Player::getSigh();
}
