//
// Name: Inbal Zelinger
// ID: 311247340
//

#ifndef UNTITLED2_BOARD_H
#define UNTITLED2_BOARD_H


#include <iostream>
#include <vector>
#include "Point.h"
#include "Symbol.h"

using namespace std;


class Board {

private:
    Symbol ** board;
    int size;




    /**
* function name: operator <<
* prints the board it gets.
* @param - const Board

**/


    friend ostream &operator <<(ostream &out , const Board &point);



public:

    /**
 * function name: Board
 * constuctor, construct a new game board.
 * @param - .

**/

    explicit Board(int size);


    /**
* function name: Board
* copy constuctor.
* @param - .

**/

    Board(const Board &boardToCopy);


    /**
* function name:  ~Board
* frees the game board alocated memmory.
**/

     ~Board();



    /**
* function name:  operator =
* foperator =.
**/


    Board& operator = (const Board& b);





    /**
 * function name: addToBoard
 * adds point to the board.
 * @param - col - the column , row - the row , player - the char to write in the point
 * @return - void.
 *
**/

    void addToBoard (int col ,int row, char playerSigh);




    /**
* function name: getSize
*return the size of the bpard
* @return -  int.
*
**/

    int getSize() const;


    /**
* function name: getBoard
*return the board
* @return -  char**
*
**/

    //char** getBoard() const ;

    int count(char symbol);
/**
 * return the value of cell in index[row][col]
 * @param row
 * @param col
 * @return  char board[row][col]
 */
    char getValueAt(int row, int col) const;


};




#endif //UNTITLED2_BOARD_H
