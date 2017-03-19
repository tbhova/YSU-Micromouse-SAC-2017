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
    MockDriver() {}
    MOCK_METHOD1(drive, void(const GPS &directions));
    MOCK_METHOD2(drive, void(const Cardinal8 dir, const int cells));
    MOCK_METHOD1(drive, void(const Cardinal8 dir));
    MOCK_METHOD0(getCurrentLocation, Coordinate());
    MOCK_METHOD0(getWalls, std::vector<Cardinal8>());
};

class MockGPS : public GPS {
public:
    MockGPS() {}
    MOCK_METHOD0(nextDirection, Cardinal8());
    MOCK_METHOD2(askForDirectionToXY, Cardinal8(const Coordinate cell, const Coordinate destination));
    MOCK_METHOD2(fullPath, std::stack<Cardinal8>(const Coordinate cell, const Coordinate destination));
};

class MockedNavigatorTest : public ::testing::Test {
protected:
    MockDriver driver;
    Maze maze = Maze(2,2);
    MockGPS gps;
    Navigator navigator = Navigator(&driver, &maze, &gps);
public:
    MockedNavigatorTest() {}
};

class NavigatorTest : public ::testing::Test {
protected:
    Navigator *navigator;
public:
};

TEST_F(MockedNavigatorTest, testMapping) {
    //Write actual test code
    maze.placeWall(0, 0, East);

    EXPECT_CALL(driver, drive(North)).Times(Exactly(2));
    EXPECT_CALL(driver, drive(South)).Times(Exactly(2));
    EXPECT_CALL(driver, drive(West)).Times(Exactly(1));
    EXPECT_CALL(driver, drive(East)).Times(Exactly(1));
    EXPECT_CALL(driver, getCurrentLocation()).Times(Exactly(7))
            .WillOnce(Return(Coordinate(0,0)))
            .WillOnce(Return(Coordinate(0,1)))
            .WillOnce(Return(Coordinate(1,1)))
            .WillOnce(Return(Coordinate(1,0)))
            .WillOnce(Return(Coordinate(1,1)))
            .WillOnce(Return(Coordinate(0,1)))
            .WillOnce(Return(Coordinate(0,0)));

    EXPECT_CALL(gps, askForDirectionToXY(Coordinate(0,0), Coordinate(0,1)))
            .Times(Exactly(1))
            .WillOnce(Return(North));
    EXPECT_CALL(gps, askForDirectionToXY(Coordinate(0,1), Coordinate(1,0)))
            .Times(Exactly(1))
            .WillOnce(Return(East));
    EXPECT_CALL(gps, askForDirectionToXY(Coordinate(1,1), Coordinate(1,0)))
            .Times(Exactly(1))
            .WillOnce(Return(South));
    EXPECT_CALL(gps, askForDirectionToXY(Coordinate(1,0), Coordinate(0,0)))
            .Times(Exactly(1))
            .WillOnce(Return(North));
    EXPECT_CALL(gps, askForDirectionToXY(Coordinate(1,1), Coordinate(0,0)))
            .Times(Exactly(1))
            .WillOnce(Return(West));
    EXPECT_CALL(gps, askForDirectionToXY(Coordinate(0,1), Coordinate(0,0)))
            .Times(Exactly(1))
            .WillOnce(Return(South));

    navigator.map();
}

#endif // NAVIGATOR_TEST_H
