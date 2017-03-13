#ifndef NAVIGATOR_TEST_H
#define NAVIGATOR_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>

#include "../../src/src/maze.h"
#include "../../src/src/coordinate.h"
#include "../../src/src/cardinal8.h"
#include "../../src/src/navigator.h"
#include "../../src/src/navigator.cpp"
#include "../../src/src/abstractdriver.h"
#include "../../src/src/gps.h"

#include <vector>

using namespace testing;
using namespace std;

class MockDriver : public AbstractDriver {
public:
    MockDriver() {};
    MOCK_METHOD1(drive, void(const GPS &directions));
    MOCK_METHOD2(drive, void(const Cardinal8 dir, const int cells));
    MOCK_METHOD1(drive, void(const Cardinal8 dir));
    MOCK_METHOD0(getCurrentLocation, Coordinate());
    MOCK_METHOD0(getWalls, std::vector<Cardinal8>());
};

class NavigatorTest : public ::testing::Test {
    MockDriver driver;
    Navigator navigator = Navigator();
};


TEST_F(NavigatorTest, testMapping) {
    //Write actual test code
}

#endif // NAVIGATOR_TEST_H
