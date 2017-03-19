#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/src/breadthfirstgps.h"
#include "../../src/src/breadthfirstgps.cpp"

using namespace testing;
using namespace std;

class BreadthFirstGPSTest : public ::testing::Test {
protected:
    Maze *maze = new Maze(16, 16);
    BreadthFirstGPS breadthFirst = BreadthFirstGPS(maze);

public:
    void setMaze(const int x, const int y) {
        *maze =  Maze(x, y);
    }
};

TEST_F(BreadthFirstGPSTest, TestConstructor) {
    setMaze(4,4);
    maze->placeWall(0, 0, North);
}

TEST_F(BreadthFirstGPSTest, TestNextDirection){
    setMaze(2, 2);
    Coordinate start = Coordinate(0,0);
    Coordinate destination = Coordinate(1,1);

    maze->placeWall(0, 0, North);

    ASSERT_EQ(breadthFirst.nextDirection(start, destination), East);
}

TEST_F(BreadthFirstGPSTest, TestNextDirectionBig){
    setMaze(3, 4);
    Coordinate start = Coordinate(0,0);
    Coordinate destination = Coordinate(1,2);

    maze->placeWall(0, 0, North);
    maze->placeWall(1, 0, North);

    ASSERT_EQ(breadthFirst.nextDirection(start, destination), East);
}
