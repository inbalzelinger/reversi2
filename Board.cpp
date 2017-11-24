
//
// Name: Inbal Zelinger
// ID: 311247340
//

#include "Board.h"
using namespace std;



Board::Board(int size): size(size) {
   this->board = new char* [this->size];
    for(int i = 0; i < this->size; i++) {
        this->board[i] = new char[this->size];
    }
    for(int i = 0; i < this->size; i++) {
        for(int j = 0; j < this->size ; j++) {
            this->board[i][j] = ' ';
        }
    }
    this->board[size / 2][size / 2] = 'O';
    this->board[(size / 2) - 1][(size / 2) - 1] = 'O';
    this->board[size / 2][(size / 2) - 1] = 'X';
    this->board[(size / 2) - 1][size / 2] = 'X';
}



Board::Board(const Board &boardToCopy) {
    this->size = boardToCopy.size;
    this->board = new char* [this->size];
    for(int i = 0; i < this->size; i++) {
        this->board[i] = new char[this->size];
    }
    for(int i = 0; i < this->size; i++) {
        for(int j = 0; j < this->size ; j++) {
            this->board[i][j] = boardToCopy.board[i][j];
        }
    }
}





ostream &operator <<(ostream &out , const Board &board1) {
    out<<" |";
    for (int i = 1; i <= board1.size; i++) {
        out<<"  " << i <<"  |";
    }
    out<<endl;
    out<<" ";
    for (int i = 0; i < board1.size*3; i = i + 3) {
        out<<"_ _ _ ";
    }
    out<<endl;

    for (int j = 0;  j < board1.size ; j = j + 1) {
        for (int i = 0;  i < board1.size ; i = i + 1) {
            if (i == 0) {
                out <<j + 1 <<"|";
            }
            if (board1.board[i][j] == 'X' ||board1.board[i][j] == 'O') {
                out << board1.board[i][j] << "    |";
            } else {
                out << "     |";
            }
        }
        out << endl;
        out<<" ";
        for (int i = 0; i < board1.size*3; i = i + 3) {
            out<<"_ _ _ ";
        }
        out<<endl;
    }
    out<<endl;
    return out;
}






 Board::~Board()  {
 for(int i = 0; i < this->size; i++){
   delete [] board[i];
 }
  delete [] board;
}



Board& Board::operator = (const Board& b) {
    if (this != &b) {
        delete[] board;
        board =new char*[this->getSize()];
        for(int i = 0; i < this->size; i++) {
            this->board[i] = new char[this->size];
        }
        for(int i = 0; i < this->size; i++) {
            for(int j = 0; j < this->size ; j++) {
                this->board[i][j] = b.board[i][j];
            }
        }
    }
    return *this;
}



int Board::getSize() const {
    return this->size;
}


char** Board::getBoard() const {
    return this->board;
}

void Board::addToBoard(int col ,int row , char playerSigh) {
    this->board[col - 1][row - 1] = playerSigh;
}



void Board::upside(char playerSigh , const int row , const int col) {
    char otherPlayer;
    int counter = 0;
    if (playerSigh == 'X')  {
        otherPlayer = 'O';
    } else {
        otherPlayer = 'X';
    }
// adds up
    for (int i = row ; i < this->size ; i++) {
        if (this->board[col - 1][i] == ' ') {
            break;

        } else if(this->board[col - 1][i] == otherPlayer) {
            counter++;
        } else if (this->board[col - 1][i] == playerSigh) {
            while (counter != 0) {
                this->addToBoard(col  ,   i - counter + 1 , playerSigh);
                counter--;
            }
            break;

        }
    }
    counter = 0;
    // adds down
    for (int i = row - 2 ; i >= 0 ; i--) {
        if (this->board[col - 1][i] == ' ') {
            break;

        } else if(this->board[col - 1][i] == otherPlayer) {
            counter++;
        } else if (this->board[col - 1][i] == playerSigh) {
            while (counter != 0) {
                this->addToBoard(col  ,   i + counter + 1 , playerSigh);
                counter--;
            }
            break;

        }
    }
    counter = 0;
    // adds left
    for (int i = col - 2 ; i >= 0 ; i--) {
        if (this->board[i][row - 1] == ' ') {
            break;
        } else if(this->board[i][row - 1] == otherPlayer) {
            counter++;
        } else if (this->board[i][row - 1] == playerSigh) {
            while (counter != 0) {
                this->addToBoard(i + counter + 1  ,   row , playerSigh);
                counter--;
            }
            break;

        }
    }

    counter = 0;
    // adds right
    for (int i = col ; i < this->size ; i++) {
        if (this->board[i][row - 1] == ' ') {
            break;

        } else if(this->board[i][row - 1] == otherPlayer) {
            counter++;
        } else if (this->board[i][row - 1] == playerSigh) {
            while (counter != 0) {
                this->addToBoard(i   ,   row , playerSigh);
                i--;
                counter--;
            }
            break;

        }
    }

    counter = 0;
    // diagnol up left
    int j = col;
        for (int i = row ; i < this->size ; i++) {
            if ( j < this->size) {
            if (this->board[j][i] == ' ') {
                break;
            } else if(this->board[j][i] == otherPlayer) {
                counter++;
                j++;
            } else if (this->board[j][i] == playerSigh) {
                while (counter != 0) {
                    this->addToBoard(j   ,   i , playerSigh);
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
                if (this->board[j][i] == ' ') {
                    break;

                } else if(this->board[j][i] == otherPlayer) {
                counter++;
                j--;
            } else if (this->board[j][i] == playerSigh) {
                while (counter != 0) {
                    this->addToBoard(j + 2  ,   i + 2 , playerSigh);
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
        for (int i = row ; i < this->size ; i++) {
            if ( j >= 0) {
            if (this->board[j][i] == ' ') {
                break;
            } else if(this->board[j][i] == otherPlayer) {
                counter++;
                j--;
            } else if (this->board[j][i] == playerSigh) {
                while (counter != 0) {
                    this->addToBoard(j + 2  ,   i  , playerSigh);
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
            if (j < this->size) {

                if (this->board[j][i] == ' ') {
                    break;

                } else if(this->board[j][i] == otherPlayer) {
                    counter++;
                    j++;
                } else if (this->board[j][i] == playerSigh) {
                    while (counter != 0) {
                        this->addToBoard(j ,   i + 2  , playerSigh);
                        j--;
                        i++;
                        counter--;
                    }
                    break;
                }
            }

        }
    }



