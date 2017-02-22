#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/src/breadthfirstgps.h"
#include "../../src/src/breadthfirstgps.cpp"


using namespace testing;
using namespace std;

class BreadthFirstGPSTest : public ::testing::Test {
protected:
    BreadthFirstGPS breadthFirst = BreadthFirstGPS();

public:



};

TEST_F(BreadthFirstGPSTest, TestConstructor) {
    Maze maze(4, 4);
    breadthFirst.setMaze(&maze);
}

TEST_F(BreadthFirstGPSTest, TestNextDirection){
    Maze maze(4, 4);
    breadthFirst.setMaze(&maze);
    ASSERT_EQ(breadthFirst.nextDirection(), North);
}
