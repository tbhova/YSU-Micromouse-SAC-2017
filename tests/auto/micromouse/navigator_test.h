#ifndef NAVIGATOR_TEST_H
#define NAVIGATOR_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/src/maze.h"
#include "../../src/src/maze.cpp"
#include "../../src/src/coordinate.h"
#include "../../src/src/navigator.h"
#include "../../src/src/navigator.cpp"

#include <vector>

using namespace testing;
using namespace std;

class NavigatorTest : public ::testing::Test {
    
};

TEST_F(NavigatorTest, testMapping) {
    //Write actual test code
}

#endif // NAVIGATOR_TEST_H
