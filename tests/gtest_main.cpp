


#include <gtest/gtest.h>
GTEST_API_ int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}


TEST(sdas, sdsd) {
    int x = 1;
    EXPECT_EQ(1, x);
}