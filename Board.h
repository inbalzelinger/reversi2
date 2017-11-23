//
// Name: Inbal Zelinger
// ID: 311247340
//

#ifndef UNTITLED2_BOARD_H
#define UNTITLED2_BOARD_H


#include <iostream>
#include <vector>
#include "Point.h"


using namespace std;


class Board {

private:
    char** board;
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
* function name: upside
* changes the points on the board between the new point of the current player to his next point
     * on the line (strait back right left and diagnols.
* @param - currentPlayer - the player whos just played. row - the row where he put his point
     * col- the column where he fut his point
* @return -  void.
*
**/

    void upside(char playerSigh , const int row , const int col);



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

    char** getBoard() const ;


};




#endif //UNTITLED2_BOARD_H
