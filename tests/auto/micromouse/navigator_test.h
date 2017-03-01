#ifndef NAVIGATOR_TEST_H
#define NAVIGATOR_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>

#include "../../src/src/maze.h"
#include "../../src/src/coordinate.h"
#include "../../src/src/navigator.h"
#include "../../src/src/navigator.cpp"
#include "../../src/src/driver.h"

#include <vector>

using namespace testing;
using namespace std;

/*class MockDriver : public Driver {
    MOCK_METHOD0(drive, void(const GPS &directions));
    MOCK_METHOD1(drive, void(const Cardinal8 dir, const int cells));
    MOCK_METHOD2(drive, void(const Cardinal8 dir));
};*/

class NavigatorTest : public ::testing::Test {
    //MockDriver driver = MockDriver();
    Navigator navigator = Navigator();
};


TEST_F(NavigatorTest, testMapping) {
    //Write actual test code
}

#endif // NAVIGATOR_TEST_H
