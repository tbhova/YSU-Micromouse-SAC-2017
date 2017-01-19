#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/src/maze.h"
#include "../../src/src/maze.cpp"

using namespace testing;

TEST(MicromouseMaze, TestConstructor) {
	Maze m = Maze(16,16);
	EXPECT_EQ(m.getSizeX(), 16);
	ASSERT_EQ(m.getSizeY(), 16);
	m = Maze(12, 4);
	EXPECT_EQ(m.getSizeX(), 12);
	ASSERT_EQ(m.getSizeY(), 4);
}

TEST(MicromouseMaze, TestPerimeterWalls) {
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

TEST(MicromouseMaze, TestWallsEmptyCell) {
	Maze m = Maze(16,16);
}

TEST(MicromouseMaze, TestInsertWallAndAdjacentCell) {
	Maze m = Maze(16,16);
}

TEST(MicromouseMaze, TestInsertDuplicateWall) {
	Maze m = Maze(16,16);
}

TEST(MicromouseMaze, TestWallsFullCell) {
	Maze m = Maze(16,16);
}

TEST(MicromouseMaze, TestRemoveWallsEmpty) {
	Maze m = Maze(16,16);
}

TEST(MicromouseMaze, TestRemovePerimeterWalls) {
	Maze m = Maze(16,16);
}

TEST(MicromouseMaze, TestRemoveWallAndAdjacentCell) {
	Maze m = Maze(16,16);
}
