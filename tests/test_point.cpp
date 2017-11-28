
#include <gtest/gtest.h>
#include "../Point.h"

TEST(PointTest, compareOperator) {
    Point p1(3 , 4);
    Point p2(3 , 4);
    Point p3(5, 6);
    EXPECT_EQ(p1==p2 , 1);
    EXPECT_EQ(p1==p3 , 0);
}

