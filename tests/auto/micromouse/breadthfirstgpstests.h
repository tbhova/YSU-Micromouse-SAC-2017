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



};

TEST_F(BreadthFirstGPSTest, TestConstructor) {
    *maze =  Maze(4, 4);
    maze->placeWall(0, 0, North);
}

TEST_F(BreadthFirstGPSTest, TestNextDirection){
    //breadthFirst.setMaze(&maze);
    *maze = Maze(2, 2);
    Coordinate start = Coordinate(0,0);
    Coordinate destination = Coordinate(1,1);

    maze->placeWall(0, 0, North);
    maze->placeWall(0, 1, South);

    ASSERT_EQ(breadthFirst.nextDirection(start, destination), East);
}

TEST_F(BreadthFirstGPSTest, TestNextDirectionBig){
    //breadthFirst.setMaze(&maze);
    *maze = Maze(3, 4);
    Coordinate start = Coordinate(0,0);
    Coordinate destination = Coordinate(1,2);

    maze->placeWall(0, 0, North);
    maze->placeWall(0, 1, South);
    maze->placeWall(1, 0, North);
    maze->placeWall(1, 1, South);

    ASSERT_EQ(breadthFirst.nextDirection(start, destination), East);
}



