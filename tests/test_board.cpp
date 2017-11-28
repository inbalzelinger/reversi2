//
// Created by inbal on 28/11/17.
//

#include <gtest/gtest.h>
#include "../Board.h"

TEST(boardTest, addToBoard) {
    Board b(8);
    b.addToBoard(6 , 7 , X);
    Symbol symbol = b.getValueAt(6 , 7);
    EXPECT_EQ(symbol, X);

}
