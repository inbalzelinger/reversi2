

#include <gtest/gtest.h>
#include "../AIPlayer.h"
#include "../ConsoleLogic.h"


TEST(AITest, makeMove) {
    ConsoleLogic logic;
    AIPlayer player(O);


    Board b(6);
    b.addToBoard(3 , 3 , empty);
    b.addToBoard(4 , 3 , empty);
    b.addToBoard(3 , 4 , O);
    b.addToBoard(3 , 5 , O);
    b.addToBoard(3 , 6 , X);
    b.addToBoard(4 , 4 , X);
    b.addToBoard(4 , 5 , O);
    b.addToBoard(4 , 6 , O);
    Point move = player.makeMove(logic.PossibleMoves(O , b) , b);
    b.addToBoard(move.getRow() ,move.getCol() , O);
    EXPECT_EQ(b.getValueAt(1 , 5) , 1);


    Board b2(6);
    b2.addToBoard(2 , 2 , X);
    b2.addToBoard(2 , 3 , O);
    b2.addToBoard(2 , 4 , O);
    b2.addToBoard(3 , 3 , X);
    b2.addToBoard(3 , 4 , empty);
    b2.addToBoard(4 , 4 , empty);
    b2.addToBoard(4 , 3 , empty);
    Point move2 = player.makeMove(logic.PossibleMoves(O , b2) , b2);
    b2.addToBoard(move2.getRow() ,move2.getCol() , O);
    EXPECT_EQ(b2.getValueAt(1 , 0) , 1);


    Board b3(6);
    b3.addToBoard(2 , 2 , X);
    b3.addToBoard(3 , 2 , O);
    b3.addToBoard(4 , 2 , O);
    b3.addToBoard(5 , 2 , O);
    b3.addToBoard(5 , 3 , X);
    b3.addToBoard(3 , 3 , O);
    b3.addToBoard(3 , 4 , empty);
    b3.addToBoard(4 , 4 , empty);
    b3.addToBoard(4 , 3 , empty);
    Point move3 = player.makeMove(logic.PossibleMoves(O , b3) , b3);
    b3.addToBoard(move3.getRow() ,move3.getCol() , O);
    if (b3.getValueAt(0 , 0) == 2) {
        EXPECT_EQ (b3.getValueAt(0 , 1) , 1);
    } else {
        EXPECT_EQ(b3.getValueAt(0 , 0) , 1 );
    }






}