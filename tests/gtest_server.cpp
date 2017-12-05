//
// Created by inbal on 05/12/17.
//
#include <gtest/gtest.h>
#include "../src/server/Server.h"

#include "iostream"
using namespace std;


TEST(serverTest, start) {
    int expect = 0;
    Server s(5036);
    try {
        s.start();
    } catch (const char* msg) {
        cout<< "cannot start server. Reason: "<< msg << endl;
        expect = -1;
    }
        EXPECT_EQ(expect , 0);
}



