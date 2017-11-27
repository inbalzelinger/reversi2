//
// Name: Inbal Zelinger
// ID: 311247340
//

#include "ConsoleLogic.h"



ConsoleLogic::ConsoleLogic(){}


vector<Point> ConsoleLogic::PossibleMoves(char playerSigh , Board &b) const {
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
        for (int i = 0; i < b.getSize(); i++) {
            for (int j = 0; j < b.getSize(); j++) {
                counter = 0;
                if (b.getValueAt(i , j) == playerSigh) {
                    //right side of 0
                    for (int col = j + 1; col < b.getSize(); col++) {
                        if (b.getValueAt(i , col) == playerSigh) {
                            break;
                        } else if (b.getValueAt(i , col) == otherPlayer) {
                            counter++;
                        } else if (b.getValueAt(i , col) == ' ') {
                            if (counter != 0) {
                                moves1.push_back(Point(i + 1, col + 1));
                            }
                            break;
                        }
                    }
                    //left side of O
                    counter = 0;
                    for (int cool = j - 1; cool >= 0; cool--) {
                        if (b.getValueAt(i , cool) == playerSigh) {
                            break;
                        } else if (b.getValueAt(i , cool)== otherPlayer) {
                            counter++;
                        } else if (b.getValueAt(i , cool) == ' ') {
                            if (counter != 0) {
                                moves1.push_back(Point(i + 1 , cool + 1 ));
                            }
                            break;
                        }
                    }
                    //down side

                    counter = 0;
                    for (int row = i + 1; row < b.getSize(); row++) {
                        if (b.getValueAt(row , j) == playerSigh) {
                            break;
                        } else if (b.getValueAt(row , j) == otherPlayer) {
                            counter++;
                        } else if (b.getValueAt(row , j)== ' ') {
                            if (counter != 0) {
                                moves1.push_back(Point(row + 1 , j + 1));
                            }
                            break;
                        }
                    }
                    //up side

                    counter = 0;
                    for (int row = i - 1; row >= 0; row--) {
                        if (b.getValueAt(row , j) == playerSigh) {
                            counter = 0;
                            break;
                        } else if (b.getValueAt(row , j)  == otherPlayer) {
                            counter++;
                        } else if (b.getValueAt(row , j) == ' ') {
                            if (counter != 0) {
                                moves1.push_back(Point(row + 1 , j + 1));
                                counter = 0;
                            }
                            break;
                        }
                    }
                    //soth east
                    counterCol = 0;
                    colForDiagnol = j + 1;
                    for (int row = i + 1; row < b.getSize(); row++) {
                        if (colForDiagnol < b.getSize()) {
                            if (b.getValueAt(row , colForDiagnol) == playerSigh) {
                                break;
                            } else if (b.getValueAt(row , colForDiagnol)  == otherPlayer) {
                                colForDiagnol++;
                                counterCol++;
                            } else if (b.getValueAt(row , colForDiagnol)  == ' ') {
                                if (counterCol != 0){

                                    moves1.push_back(Point(row + 1 , colForDiagnol + 1));
                                }
                                break;

                            }
                        }
                    }
                    //north east
                    counterCol = 0;
                    colForDiagnol = j + 1;
                    for (int row = i - 1; row >= 0; row--) {
                        if (colForDiagnol < b.getSize()) {
                            if (b.getValueAt(row , colForDiagnol)  == playerSigh) {
                                counterCol = 0;
                                break;
                            } else if (b.getValueAt(row , colForDiagnol)  == otherPlayer) {
                                colForDiagnol++;
                                counterCol++;
                            } else if (b.getValueAt(row , colForDiagnol)  == ' ') {
                                if (counterCol != 0) {
                                    moves1.push_back(Point(row + 1 , colForDiagnol + 1 ));
                                }
                                break;
                            }
                        }
                    }
                    //south west
                    counterCol = 0;
                    colForDiagnol = j - 1;
                    for (int row = i + 1; row < b.getSize(); row++) {
                        if (colForDiagnol > -1) {
                            if (b.getValueAt(row , colForDiagnol) == playerSigh) {
                                break;
                            } else if (b.getValueAt(row , colForDiagnol) == otherPlayer) {
                                colForDiagnol--;
                                counterCol++;
                            } else if (b.getValueAt(row , colForDiagnol) == ' ') {
                                if (counterCol != 0){

                                    moves1.push_back(Point(row + 1 , colForDiagnol + 1));
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
                            if (b.getValueAt(row , colForDiagnol) == playerSigh) {
                                break;
                            } else if (b.getValueAt(row , colForDiagnol) == otherPlayer) {
                                colForDiagnol--;
                                counterCol++;
                            } else if (b.getValueAt(row , colForDiagnol) == ' ') {
                                if (counterCol != 0) {
                                    moves1.push_back(Point(row + 1 , colForDiagnol + 1));
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }



    int j = 0;
    int flag = 0;

    vector<Point> playesOptions;

    if (playesOptions.empty() && !moves1.empty()) {
        playesOptions.push_back(moves1[j]);
        j++;
    }
    while (j < moves1.size()) {
        for (int i = 0; i < playesOptions.size(); i++) {
            if (playesOptions[i] == (moves1[j])) {
                break;
            } else {
                flag++;
            }
        }
        if (flag == playesOptions.size()) {
            playesOptions.push_back(moves1[j]);
        }
        flag = 0;
        j++;
    }
        return playesOptions;

    }







void ConsoleLogic::upside(char playerSigh , const int row , const int col , Board &b) {
    char otherPlayer;
    int counter = 0;
    if (playerSigh == 'X')  {
        otherPlayer = 'O';
    } else {
        otherPlayer = 'X';
    }
// adds up
    for (int i = row ; i < b.getSize(); i++) {

        if (b.getValueAt(i , col - 1) == ' ') {
            break;

        } else if(b.getValueAt(i , col - 1) == otherPlayer) {
            counter++;
        } else if (b.getValueAt(i , col - 1) == playerSigh) {
            while (counter != 0) {
                b.addToBoard(i - counter + 1 , col , playerSigh);
                counter--;
            }
            break;

        }
    }
    counter = 0;
    // adds down
    for (int i = row - 2 ; i >= 0 ; i--) {
        if (b.getValueAt(i , col - 1) == ' ') {
            break;

        } else if(b.getValueAt(i , col - 1) == otherPlayer) {
            counter++;
        } else if (b.getValueAt(i , col - 1) == playerSigh) {
            while (counter != 0) {
                b.addToBoard(i + counter + 1 , col , playerSigh);
                counter--;
            }
            break;

        }
    }
    counter = 0;
    // adds left
    for (int i = col - 2 ; i >= 0 ; i--) {
        if (b.getValueAt(row - 1 , i) == ' ') {
            break;
        } else if(b.getValueAt(row - 1 , i) == otherPlayer) {
            counter++;
        } else if (b.getValueAt(row - 1 , i) == playerSigh) {
            while (counter != 0) {
                b.addToBoard(row, i + counter + 1 , playerSigh);
                counter--;
            }
            break;

        }
    }

    counter = 0;
    // adds right
    for (int i = col ; i < b.getSize() ; i++) {
        if (b.getValueAt(row - 1 , i) == ' ') {
            break;

        } else if(b.getValueAt(row - 1 , i) == otherPlayer) {
            counter++;
        } else if (b.getValueAt(row - 1 , i) == playerSigh) {
            while (counter != 0) {
               b.addToBoard(row , i , playerSigh);
                i--;
                counter--;
            }
            break;

        }
    }

    counter = 0;
    // diagnol up left
    int j = col;
    for (int i = row ; i < b.getSize() ; i++) {
        if ( j < b.getSize()) {
            if (b.getValueAt(i , j) == ' ') {
                break;
            } else if(b.getValueAt(i , j) == otherPlayer) {
                counter++;
                j++;
            } else if (b.getValueAt(i , j) == playerSigh) {
                while (counter != 0) {
                    b.addToBoard(i  , j, playerSigh);
                    j--;
                    i--;
                    counter--;
                }
                break;

            }
        }
    }
    // diagnol down right
    j = col - 2;
    counter = 0;
    for (int i = row - 2 ; i >= 0 ; i--) {
        if (j >= 0) {
            if (b.getValueAt(i , j) == ' ') {
                break;

            } else if(b.getValueAt(i , j) == otherPlayer) {
                counter++;
                j--;
            } else if (b.getValueAt(i , j) == playerSigh) {
                while (counter != 0) {
                    b.addToBoard(i + 2 , j + 2  , playerSigh);
                    j++;
                    i++;
                    counter--;
                }
                break;

            }
        }
    }
    // diagnol down left
    j = col - 2;
    counter = 0;
    for (int i = row ; i < b.getSize() ; i++) {
        if ( j >= 0) {
            if (b.getValueAt(i , j) == ' ') {
                break;
            } else if(b.getValueAt(i , j) == otherPlayer) {
                counter++;
                j--;
            } else if (b.getValueAt(i , j)  == playerSigh) {
                while (counter != 0) {
                    b.addToBoard(i, j + 2  , playerSigh);
                    j++;
                    i--;
                    counter--;
                }
                break;
            }

        }
    }
    j = col;
    counter = 0;
    for (int i = row - 2 ; i >= 0 ; i--) {
        if (j < b.getSize()) {

            if (b.getValueAt(i , j)  == ' ') {
                break;

            } else if(b.getValueAt(i , j)  == otherPlayer) {
                counter++;
                j++;
            } else if (b.getValueAt(i , j)  == playerSigh) {
                while (counter != 0) {
                    b.addToBoard(i + 2, j , playerSigh);
                    j--;
                    i++;
                    counter--;
                }
                break;
            }
        }

    }
}

