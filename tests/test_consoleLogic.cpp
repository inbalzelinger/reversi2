//
// Created by inbal on 28/11/17.
//

#include <gtest/gtest.h>
#include "../Board.h"
#include "../ConsoleLogic.h"

TEST(consoleLogic, upside) {


    ConsoleLogic logic;
    Board b(8);
    b.addToBoard(4 , 3 , X);
    logic.upside(X , 4 , 3 , b);
    cout<<b;
    //check upside right
    EXPECT_EQ(b.getValueAt(3 , 3), 0);
    b.addToBoard(3 , 3 , O);
    b.addToBoard(5 , 3 , O);
    logic.upside(O , 5 , 3 , b);
    cout<<b;
    // two flips in one turn.
    EXPECT_EQ(b.getValueAt(4 , 3), 1);
    EXPECT_EQ(b.getValueAt(3 , 2), 1);








}