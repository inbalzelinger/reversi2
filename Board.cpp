
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



Board::Board(const Board &boardToCopy): size(boardToCopy.getSize()) {
    size = boardToCopy.size;
    board = new char* [size];
    for(int i = 0; i < size; i++) {
        board[i] = new char[size];
    }
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size ; j++) {
            board[i][j] = boardToCopy.getValueAt(i,j);
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

    for (int i = 0;  i < board1.size ; i = i + 1) {
        for (int j = 0;  j < board1.size ; j = j + 1) {
            if (j == 0) {
                out <<i + 1 <<"|";
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


int Board::count(char symbol) {
    int numSymbol = 0;
    for (int i = 0; i < this->size ; i++) {

        for (int j = 0; j < this->size ; j++) {

            if (this->board[i][j] == symbol) {
               numSymbol;
            }
        }
    }
}


char Board::getValueAt(int row, int col) const {
    return this->board[row][col];
}

Board& Board::operator = (const Board& b) {
    if (this != &b) {
        for(int i = 0; i < this->size; i++){
            delete [] board[i];
        }
        delete [] board;
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

/*
char** Board::getBoard() const {
    return this->board;
}*/

void Board::addToBoard(int row ,int col , char playerSigh) {
    this->board[row - 1][col - 1] = playerSigh;
}








