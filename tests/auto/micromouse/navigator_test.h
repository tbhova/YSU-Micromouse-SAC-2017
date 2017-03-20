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
#include "../../src/src/breadthfirstgps.h"
#include "../../src/src/breadthfirstgps.cpp"

#include <vector>
#include <stack>

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
    explicit MockGPS(Maze* maze) : GPS(maze) {}
    MOCK_METHOD2(getDirectionTo, Cardinal8(const Coordinate start, const Coordinate destination));
    MOCK_METHOD2(fullPath, std::stack<Cardinal8>(const Coordinate start, const Coordinate destination));
};

class MockedNavigatorTest : public ::testing::Test {
protected:
    MockDriver driver;
    Maze* maze = new Maze(2,2);
    MockGPS* gps = new MockGPS(maze);
    Navigator navigator = Navigator(&driver, maze, gps);
public:
    MockedNavigatorTest() {}
    ~MockedNavigatorTest() { delete maze; delete gps; }
};

class NavigatorTest : public ::testing::Test {
protected:
    MockDriver driver;
    Maze* maze = new Maze(2,2);
    MockGPS* gps = new BreadthFirstGPS(maze);
    Navigator navigator = Navigator(&driver, maze, gps);
public:
    NavigatorTest() {}
    ~NavigatorTest() { delete maze; delete gps; }
};

TEST_F(MockedNavigatorTest, testMapping) {
    maze->placeWall(0, 0, East);

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

    EXPECT_CALL(*gps, getDirectionTo(Coordinate(0,0), Coordinate(0,1)))
            .Times(Exactly(1))
            .WillOnce(Return(North));
    EXPECT_CALL(*gps, getDirectionTo(Coordinate(0,1), Coordinate(1,0)))
            .Times(Exactly(1))
            .WillOnce(Return(East));
    EXPECT_CALL(*gps, getDirectionTo(Coordinate(1,1), Coordinate(1,0)))
            .Times(Exactly(1))
            .WillOnce(Return(South));
    EXPECT_CALL(*gps, getDirectionTo(Coordinate(1,0), Coordinate(0,0)))
            .Times(Exactly(1))
            .WillOnce(Return(North));
    EXPECT_CALL(*gps, getDirectionTo(Coordinate(1,1), Coordinate(0,0)))
            .Times(Exactly(1))
            .WillOnce(Return(West));
    EXPECT_CALL(*gps, getDirectionTo(Coordinate(0,1), Coordinate(0,0)))
            .Times(Exactly(1))
            .WillOnce(Return(South));

    navigator.map();
}

#endif // NAVIGATOR_TEST_H
