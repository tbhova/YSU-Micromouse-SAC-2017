#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/src/maze.h"
#include "../../src/src/maze.cpp"
#include "../../src/src/coordinate.h"

#include <vector>
#include <algorithm>

using namespace testing;
using namespace std;

class MazeTest : public ::testing::Test {
protected:
    const int sizeX = 16, sizeY = 16;
    int middleX, middleY;
    Maze maze = Maze(sizeX, sizeY);

public:
    MazeTest() {
        srand(time(NULL));

        //chose a box in the middle between 1 and size - 2
        middleX = rand() % (sizeX - 2) + 1;
        middleY = rand() % (sizeY - 2) + 1;
    };
};

TEST_F(MazeTest, TestConstructor) {
    Maze m = Maze(16,16);
    EXPECT_EQ(m.getSizeX(), 16);
    ASSERT_EQ(m.getSizeY(), 16);
    m = Maze(12, 4);
    EXPECT_EQ(m.getSizeX(), 12);
    ASSERT_EQ(m.getSizeY(), 4);
}

/**
 * @brief TestPerimeterWalls
 * Test that there are perimeter walls and no walls in the middle
 */
TEST_F(MazeTest, TestPerimeterWalls) {
    for (int x = 0; x < maze.getSizeX(); x++) {
        for (int y = 0; y < maze.getSizeY(); y++) {

            const bool southWall = maze.isWall(x, y, South),
                       northWall = maze.isWall(x, y, North),
                       westWall  = maze.isWall(x, y, West),
                       eastWall  = maze.isWall(x, y, East);

            if (y == 0) { ASSERT_TRUE(southWall); }
            else { ASSERT_FALSE(southWall); }

            if (y == maze.getSizeY() - 1) { ASSERT_TRUE(northWall); }
            else { ASSERT_FALSE(northWall); }

            if (x == 0) { ASSERT_TRUE(westWall); }
            else { ASSERT_FALSE(westWall); }

            if (x == maze.getSizeX() - 1) { ASSERT_TRUE(eastWall); }
            else { ASSERT_FALSE(eastWall); }
        }
    }
}

TEST_F(MazeTest, TestWallsEmptyCell) {
    for (vector<Cardinal8>::const_iterator it = primaryCardinalList.begin(); it != primaryCardinalList.end(); ++it) {
        EXPECT_FALSE(maze.isWall(middleX, middleY, *it));
    }
}

TEST_F(MazeTest, TestInsertAdjacentBoundaryWalls) {
    for (vector<Cardinal8>::const_iterator it = primaryCardinalList.begin(); it != primaryCardinalList.end(); ++it) {
        maze.placeWall(0,0, *it);
        ASSERT_TRUE(maze.isWall(0, 0, *it));
    }
    ASSERT_TRUE(maze.isWall(0, 1, West));
    ASSERT_TRUE(maze.isWall(1, 0, South));
}

TEST_F(MazeTest, TestInsertAndRemoveWallAdjacency) {
    //insert a wall
    const int directionIndex = rand() % 4;
    const Cardinal8 randomDirection = primaryCardinalList.at(directionIndex);

    maze.placeWall(middleX, middleY, randomDirection);

    ASSERT_TRUE(maze.isWall(middleX, middleY, randomDirection));

    int x = middleX, y = middleY;
    switch (randomDirection) {
    case North:
        y++;
        break;
    case South:
        y--;
        break;
    case West:
        x--;
        break;
    case East:
        x++;
        break;
    default:
        break;
    }

    ASSERT_TRUE(maze.isWall(x, y, oppositeDirection(randomDirection)));

    //remove the wall
    maze.removeWall(middleX, middleY, randomDirection);
    ASSERT_FALSE(maze.isWall(middleX, middleY, randomDirection));
    ASSERT_FALSE(maze.isWall(x, y, oppositeDirection(randomDirection)));
}

TEST_F(MazeTest, TestRemoveBoundaryWall) {
    maze.placeWall(0,0, North);
    maze.removeWall(0,1, South);
    ASSERT_FALSE(maze.isWall(0, 0, North));
}

TEST_F(MazeTest, TestInsertAndRemoveAllWalls) {
    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            for (vector<Cardinal8>::const_iterator it = primaryCardinalList.begin(); it != primaryCardinalList.end(); ++it) {
                maze.placeWall(x, y, *it);
                ASSERT_TRUE(maze.isWall(x, y, *it));

                maze.removeWall(x, y, *it);
                ASSERT_FALSE(maze.isWall(x, y, *it));
            }
        }
    }
}

bool containsCoordinate(const vector<Coordinate>& vec, const int x, const int y) {
    return any_of(vec.begin(), vec.end(), [x, y](Coordinate c) {return Coordinate(x,y) == c; });
}

TEST_F(MazeTest, TestAdjacentNeighborsEdgeCell) {
    //Expect cell 0,0 to have neighbors of 0,1 and 1,0
    vector<Coordinate> neighbors = maze.getNeighboringCells(0,0);

    EXPECT_EQ(neighbors.size(), 2);

    EXPECT_TRUE(containsCoordinate(neighbors, 0, 1));
    ASSERT_TRUE(containsCoordinate(neighbors, 1, 0));
}

TEST_F(MazeTest, TestAdjacentNeighborsMiddleCellEmpty) {
    vector<Coordinate> neighbors = maze.getNeighboringCells(middleX, middleY);

    EXPECT_EQ(neighbors.size(), 4);

    ASSERT_TRUE(containsCoordinate(neighbors, middleX + 1, middleY));
    ASSERT_TRUE(containsCoordinate(neighbors, middleX - 1, middleY));
    ASSERT_TRUE(containsCoordinate(neighbors, middleX, middleY + 1));
    ASSERT_TRUE(containsCoordinate(neighbors, middleX, middleY - 1));
}

TEST_F(MazeTest, TestAdjacentNeighborsMiddleCellFull) {
    for (vector<Cardinal8>::const_iterator it = primaryCardinalList.begin(); it != primaryCardinalList.end(); ++it) {
        maze.placeWall(middleX, middleY, *it);
    }

    vector<Coordinate> neighbors = maze.getNeighboringCells(middleX, middleY);
    EXPECT_EQ(neighbors.size(), 0);
}

TEST_F(MazeTest, TestMouseVisited) {
    maze.setMouseVisited(middleX, middleY);

    for (int x = 0; x < maze.getSizeX(); x++) {
        for (int y = 0; y < maze.getSizeY(); y++) {
            bool isVisited = false;
            if (x == middleX && y == middleY) {
                isVisited = true;
            }
            ASSERT_EQ(maze.hasMouseVisited(x, y), isVisited);
        }
    }
}

TEST_F(MazeTest, TestTraversalVisted) {
    maze.setTraversalVisited(middleX, middleY);

    for (int x = 0; x < maze.getSizeX(); x++) {
        for (int y = 0; y < maze.getSizeY(); y++) {
            bool isVisited = false;
            if (x == middleX && y == middleY) {
                isVisited = true;
            }
            ASSERT_EQ(maze.hasTraversalVisited(x, y), isVisited);
        }
    }

    maze.resetTraversalVisited();

    for (int x = 0; x < maze.getSizeX(); x++) {
        for (int y = 0; y < maze.getSizeY(); y++) {
            ASSERT_FALSE(maze.hasTraversalVisited(x, y));
        }
    }
}
