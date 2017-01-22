#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/src/maze.h"
#include "../../src/src/maze.cpp"

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

TEST_F(MazeTest, TestInsertWallAndAdjacentCell) {
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

//    ASSERT_TRUE(maze.isWall(x, y, oppositeDirection(randomDirection)));
}

TEST_F(MazeTest, TestInsertDuplicateWall) {
}

TEST_F(MazeTest, TestWallsFullCell) {
}

TEST_F(MazeTest, TestRemoveWallsEmpty) {
}

TEST_F(MazeTest, TestRemovePerimeterWalls) {
}

TEST_F(MazeTest, TestRemoveWallAndAdjacentCell) {
}
