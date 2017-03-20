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

#include <vector>
#include <stack>

using namespace testing;
using namespace std;

class MockDriver : public AbstractDriver {
public:
    MockDriver() {}
    MOCK_METHOD1(drive, void(std::stack<Cardinal8> &directions));
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
    Maze* maze = new Maze(4,4);
    GPS* gps = new BreadthFirstGPS(maze);
    Navigator navigator = Navigator(&driver, maze, gps);
public:
    NavigatorTest() {}
    ~NavigatorTest() { delete maze; delete gps; }
};

TEST_F(MockedNavigatorTest, testMapping) {
    maze->placeWall(0, 0, East);

    EXPECT_CALL(driver, drive(North)).Times(Exactly(1));
    EXPECT_CALL(driver, drive(South)).Times(Exactly(1));
    EXPECT_CALL(driver, drive(East)).Times(Exactly(1));
    EXPECT_CALL(driver, getCurrentLocation()).Times(Exactly(4))
            .WillOnce(Return(Coordinate(0,0)))
            .WillOnce(Return(Coordinate(0,1)))
            .WillOnce(Return(Coordinate(1,1)))
            .WillOnce(Return(Coordinate(1,0)));

    EXPECT_CALL(driver, getWalls())
            .WillRepeatedly(Return(std::vector<Cardinal8>()));

    EXPECT_CALL(*gps, getDirectionTo(Coordinate(0,0), Coordinate(0,1)))
            .Times(Exactly(1))
            .WillOnce(Return(North));
    EXPECT_CALL(*gps, getDirectionTo(Coordinate(0,1), Coordinate(1,0)))
            .Times(Exactly(1))
            .WillOnce(Return(East));
    EXPECT_CALL(*gps, getDirectionTo(Coordinate(1,1), Coordinate(1,0)))
            .Times(Exactly(1))
            .WillOnce(Return(South));

    navigator.map();
}

TEST_F(NavigatorTest, testMappingActual) {
    maze->placeWall(0, 0, East);
    maze->placeWall(0, 1, North);
    maze->placeWall(1, 0, North);
    maze->placeWall(0, 2, East);
    maze->placeWall(1, 2, East);
    maze->placeWall(1, 2, South);
    maze->placeWall(2, 2, East);
    maze->placeWall(2, 1, East);
    maze->placeWall(3, 1, North);
    EXPECT_CALL(driver, drive(North)).Times(Exactly(12));
    EXPECT_CALL(driver, drive(South)).Times(Exactly(10));
    EXPECT_CALL(driver, drive(West)).Times(Exactly(5));
    EXPECT_CALL(driver, drive(East)).Times(Exactly(8));
    EXPECT_CALL(driver, getCurrentLocation()).Times(Exactly(36))
            .WillOnce(Return(Coordinate(0,0)))
            .WillOnce(Return(Coordinate(0,1)))
            .WillOnce(Return(Coordinate(1,1)))
            .WillOnce(Return(Coordinate(2,1)))
            .WillOnce(Return(Coordinate(2,2)))
            .WillOnce(Return(Coordinate(2,3)))
            .WillOnce(Return(Coordinate(1,3)))
            .WillOnce(Return(Coordinate(0,3)))
            .WillOnce(Return(Coordinate(0,2)))
            .WillOnce(Return(Coordinate(0,3)))
            .WillOnce(Return(Coordinate(1,3)))
            .WillOnce(Return(Coordinate(2,3)))
            .WillOnce(Return(Coordinate(2,2)))
            .WillOnce(Return(Coordinate(2,1)))
            .WillOnce(Return(Coordinate(2,0)))
            .WillOnce(Return(Coordinate(1,0)))
            .WillOnce(Return(Coordinate(2,0)))
            .WillOnce(Return(Coordinate(2,1)))
            .WillOnce(Return(Coordinate(2,2)))
            .WillOnce(Return(Coordinate(2,3)))
            .WillOnce(Return(Coordinate(1,3)))
            .WillOnce(Return(Coordinate(1,2)))
            .WillOnce(Return(Coordinate(1,3)))
            .WillOnce(Return(Coordinate(2,3)))
            .WillOnce(Return(Coordinate(2,2)))
            .WillOnce(Return(Coordinate(2,1)))
            .WillOnce(Return(Coordinate(2,0)))
            .WillOnce(Return(Coordinate(3,0)))
            .WillOnce(Return(Coordinate(3,1)))
            .WillOnce(Return(Coordinate(3,0)))
            .WillOnce(Return(Coordinate(2,0)))
            .WillOnce(Return(Coordinate(2,1)))
            .WillOnce(Return(Coordinate(2,2)))
            .WillOnce(Return(Coordinate(2,3)))
            .WillOnce(Return(Coordinate(3,3)))
            .WillOnce(Return(Coordinate(3,2)));

    navigator.map();
}

#endif // NAVIGATOR_TEST_H
