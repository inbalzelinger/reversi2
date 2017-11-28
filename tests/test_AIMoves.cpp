//
// Created by inbal on 28/11/17.
//

#include <gtest/gtest.h>
#include "../AIPlayer.h"
#include "../ConsoleLogic.h"


TEST(AITest, makeMove) {
    Board b(6);
    b.addToBoard(3 , 3 , empty);
    b.addToBoard(4 , 3 , empty);
    b.addToBoard(3 , 4 , O);
    b.addToBoard(3 , 5 , O);
    b.addToBoard(3 , 6 , X);
    b.addToBoard(4 , 4 , X);
    b.addToBoard(4 , 5 , O);
    b.addToBoard(4 , 6 , O);
    ConsoleLogic logic;
    AIPlayer player(O);
    Point move = player.makeMove(logic.PossibleMoves(O , b) , b);
    b.addToBoard(move.getRow() ,move.getCol() , O);
    EXPECT_EQ(b.getValueAt(1 , 5) , 1);


    Board b2(6);


}