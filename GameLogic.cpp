//
// Name: Inbal Zelinger
// ID: 311247340
//

#include "GameLogic.h"


GameLogic::GameLogic(Board& b): board(&b) {}

GameLogic::GameLogic(){}


vector<Point> GameLogic::PossibleMoves(char playerSigh) const {
    vector<Point> moves1;
    char otherPlayer;
    int counter = 0;
    int counterCol = 0;
    int colForDiagnol = 0;
    if (playerSigh == 'X') {
        otherPlayer = 'O';
        } else {
            otherPlayer = 'X';
        }
        for (int i = 0; i < this->board->getSize(); i++) {
            for (int j = 0; j < this->board->getSize(); j++) {
                counter = 0;
                if (this->board->getBoard()[j][i] == playerSigh) {
                    //right side of 0
                    for (int col = j + 1; col < this->board->getSize(); col++) {
                        if (this->board->getBoard()[col][i] == playerSigh) {
                            break;
                        } else if (this->board->getBoard()[col][i] == otherPlayer) {
                            counter++;
                        } else if (this->board->getBoard()[col][i] == ' ') {
                            if (counter != 0) {
                                moves1.push_back(Point(col + 1 , i + 1));
                            }
                            break;
                        }
                    }
                    //left side of O
                    counter = 0;
                    for (int cool = j - 1; cool >= 0; cool--) {
                        if (this->board->getBoard()[cool][i] == playerSigh) {
                            break;
                        } else if (this->board->getBoard()[cool][i] == otherPlayer) {
                            counter++;
                        } else if (this->board->getBoard()[cool][i] == ' ') {
                            if (counter != 0) {
                                moves1.push_back(Point(cool + 1 , i + 1 ));
                            }
                            break;
                        }
                    }
                    //down side

                    counter = 0;
                    for (int row = i + 1; row < this->board->getSize(); row++) {
                        if (this->board->getBoard()[j][row] == playerSigh) {
                            break;
                        } else if (this->board->getBoard()[j][row] == otherPlayer) {
                            counter++;
                        } else if (this->board->getBoard()[j][row] == ' ') {
                            if (counter != 0) {
                                moves1.push_back(Point(j + 1 , row + 1));
                            }
                            break;
                        }
                    }
                    //up side

                    counter = 0;
                    for (int row = i - 1; row >= 0; row--) {
                        if (this->board->getBoard()[j][row] == playerSigh) {
                            counter = 0;
                            break;
                        } else if (this->board->getBoard()[j][row] == otherPlayer) {
                            counter++;
                        } else if (this->board->getBoard()[j][row] == ' ') {
                            if (counter != 0) {
                                moves1.push_back(Point(j + 1 , row + 1));
                                counter = 0;
                            }
                            break;
                        }
                    }
                    //soth east
                    counterCol = 0;
                    colForDiagnol = j + 1;
                    for (int row = i + 1; row < this->board->getSize(); row++) {
                        if (colForDiagnol < this->board->getSize()) {
                            if (this->board->getBoard()[colForDiagnol][row] == playerSigh) {
                                break;
                            } else if (this->board->getBoard()[colForDiagnol][row] == otherPlayer) {
                                colForDiagnol++;
                                counterCol++;
                            } else if (this->board->getBoard()[colForDiagnol][row] == ' ') {
                                if (counterCol != 0){

                                    moves1.push_back(Point(colForDiagnol + 1, row + 1));
                                }
                                break;

                            }
                        }
                    }

                    //north east
                    counterCol = 0;
                    colForDiagnol = j + 1;
                    for (int row = i - 1; row >= 0; row--) {
                        if (colForDiagnol < this->board->getSize()) {
                            if (this->board->getBoard()[colForDiagnol][row] == playerSigh) {
                                counterCol = 0;
                                break;
                            } else if (this->board->getBoard()[colForDiagnol][row] == otherPlayer) {
                                colForDiagnol++;
                                counterCol++;
                            } else if (this->board->getBoard()[colForDiagnol][row] == ' ') {
                                if (counterCol != 0) {
                                    moves1.push_back(Point(colForDiagnol + 1 , row + 1 ));
                                }
                                break;
                            }
                        }
                    }
                    //south west
                    counterCol = 0;
                    colForDiagnol = j - 1;
                    for (int row = i + 1; row <this->board->getSize(); row++) {
                        if (colForDiagnol > -1) {
                            if (this->board->getBoard()[colForDiagnol][row] == playerSigh) {
                                break;
                            } else if (this->board->getBoard()[colForDiagnol][row] == otherPlayer) {
                                colForDiagnol--;
                                counterCol++;
                            } else if (this->board->getBoard()[colForDiagnol][row] == ' ') {
                                if (counterCol != 0){

                                    moves1.push_back(Point(colForDiagnol + 1, row + 1));
                                }
                                break;
                            }
                        }
                    }
                    //north west

                    counterCol = 0;
                    colForDiagnol = j - 1;
                    for (int row = i - 1; row >= 0; row--) {
                        if (colForDiagnol > -1) {
                            if (this->board->getBoard()[colForDiagnol][row] == playerSigh) {
                                break;
                            } else if (this->board->getBoard()[colForDiagnol][row] == otherPlayer) {
                                colForDiagnol--;
                                counterCol++;
                            } else if (this->board->getBoard()[colForDiagnol][row] == ' ') {
                                if (counterCol != 0) {
                                    moves1.push_back(Point(colForDiagnol + 1 , row + 1));
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
        return moves1;


    }

