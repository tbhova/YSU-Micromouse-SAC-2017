#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/src/maze.h"
#include "../../src/src/maze.cpp"

using namespace testing;
using namespace std;

class MazeTest : public ::testing::Test {
private:
    int sizeX, sizeY;
    Maze* maze;

public:
    MazeTest() {
        srand(time(NULL));
        sizeX = 16;
        sizeY = 16;
        maze = new Maze(sizeX, sizeY);
    };

    int getSizeX() const { return sizeX; }
    int getSizeY() const { return sizeY; }
    int getLastX() const { return sizeX - 1; }
    int getLastY() const { return sizeY - 1; }
    int getMiddleX() const { return rand() % (sizeX - 2) + 1; }
    int getMiddleY() const { return rand() % (sizeY - 2) + 1; }

    Maze getMaze() const { return *maze; }
};

TEST_F(MazeTest, TestConstructor) {
	Maze m = Maze(16,16);
	EXPECT_EQ(m.getSizeX(), 16);
	ASSERT_EQ(m.getSizeY(), 16);
	m = Maze(12, 4);
	EXPECT_EQ(m.getSizeX(), 12);
	ASSERT_EQ(m.getSizeY(), 4);
}

TEST_F(MazeTest, TestPerimeterWalls) {
	Maze m = Maze(16,16);

	for (int x = 0; x < m.getSizeX(); x++) {
		ASSERT_TRUE(m.isWall(x, 0, South));
		ASSERT_TRUE(m.isWall(x, m.getSizeY() - 1, North));
	}
	for (int y = 0; y < m.getSizeX(); y++) {
		ASSERT_TRUE(m.isWall(0, y, West));
		ASSERT_TRUE(m.isWall(m.getSizeX() - 1, y, East));
	}

}

TEST_F(MazeTest, TestWallsEmptyCell) {
    const int size_x = 16, size_y = 16;
    Maze m = Maze(size_x, size_y);
    srand(time(NULL));

    //generate random number between 1 and size_x - 1 (a middle box)
    const int x = rand() % (size_x - 2) + 1;
    const int y = rand() % (size_y - 2) + 1;

    for (vector<Cardinal8>::const_iterator it = primaryCardinalList.begin(); it != primaryCardinalList.end(); ++it) {
        EXPECT_FALSE(m.isWall(x, y, *it));
    }
}

TEST_F(MazeTest, TestInsertWallAndAdjacentCell) {
    const int size_x = 16, size_y = 16;
    Maze m = Maze(size_x, size_y);
    srand(time(NULL));

    //generate random number between 1 and size_x - 1 (a middle box)
    const int x = rand() % (size_x - 2) + 1;
    const int y = rand() % (size_y - 2) + 1;
    const int directionIndex = rand() % 4;

    m.placeWall(x, y, primaryCardinalList.at(directionIndex));
}

TEST_F(MazeTest, TestInsertDuplicateWall) {
	Maze m = Maze(16,16);
}

TEST_F(MazeTest, TestWallsFullCell) {
	Maze m = Maze(16,16);
}

TEST_F(MazeTest, TestRemoveWallsEmpty) {
	Maze m = Maze(16,16);
}

TEST_F(MazeTest, TestRemovePerimeterWalls) {
	Maze m = Maze(16,16);
}

TEST_F(MazeTest, TestRemoveWallAndAdjacentCell) {
	Maze m = Maze(16,16);
}
