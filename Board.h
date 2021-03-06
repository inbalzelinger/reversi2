
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

    void addToBoard (int col ,int row, Symbol playerSigh);




    /**
* function name: getSize
*return the size of the bpard
* @return -  int.
*
**/

    int getSize() const;



    /**
* function name: count
*return how many times the sybbol it gest is apper on bpard.
* @param symbol.
* @return -  int.
*
**/


    int count(Symbol symbol);
/**
 * return the value of cell in index[row][col]
 * @param row
 * @param col
 * @return  char board[row][col]
 */
    Symbol getValueAt(int row, int col) const;


};




#endif //UNTITLED2_BOARD_H
