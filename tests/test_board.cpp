//
// Created by inbal on 28/11/17.
//

#include <gtest/gtest.h>
#include "../Board.h"

TEST(boardTest, addToBoard) {
    Board b(8);
    b.addToBoard(2 , 2 , O);
    Symbol symbol = b.getValueAt(1 , 1);
    EXPECT_EQ(symbol, 1);


}
