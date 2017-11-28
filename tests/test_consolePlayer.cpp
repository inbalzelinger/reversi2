//
// Created by inbal on 28/11/17.
//


#include <googletest/include/gtest/gtest.h>

#include "../ConsolePlayer.h"
#include "../ConsoleLogic.h"


TEST(CosolePlayer, noMoves) {

    ConsoleLogic logic;
    ConsolePlayer player1(X);
    ConsolePlayer player2(O);
    Board b(6);
    b.addToBoard(3 , 3 , empty);
    b.addToBoard(4 , 3 , empty);
    b.addToBoard(4 ,4 , empty);
    b.addToBoard(3 ,4 , empty);
    b.addToBoard(1 ,1 , O);
    b.addToBoard(1 ,2 , X);
    b.addToBoard(2 ,1 , X);
    EXPECT_EQ(logic.PossibleMoves(player1.getSigh(), b) , NULL);

    Board b2(6);
    b2.addToBoard(3 , 3 , empty);
    b2.addToBoard(4 , 3 , empty);
    b2.addToBoard(4 ,4 , empty);
    b2.addToBoard(3 ,4 , empty);
    b2.addToBoard(1 ,1 , X);
    b2.addToBoard(1 ,2 , O);
    b2.addToBoard(2 ,1 , O);
    EXPECT_EQ(logic.PossibleMoves(player2.getSigh(), b2) , NULL);





}



