

#include <gtest/gtest.h>
#include "../Board.h"

TEST(boardTest, addToBoard) {
    Board b(8);

    b.addToBoard(2 , 2 , O);
    Symbol symbol = b.getValueAt(1 , 1);
    EXPECT_EQ(symbol, 1);

    b.addToBoard(6 , 7 , X);
    Symbol symbol2 = b.getValueAt(5 , 6);
    EXPECT_EQ(symbol2, 0);

    b.addToBoard(3 , 2 , X);
    Symbol symbol3 = b.getValueAt(2 , 1);
    EXPECT_EQ(symbol3, 0);



}
