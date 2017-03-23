#include "maze.cpp"
#include "navigator.cpp"
#include "interpolateir.cpp"
#include "driver.cpp"
#include "stopgodriver.cpp"
#include "breadthfirstgps.cpp"

#include "mazetest.h"
#include "breadthfirstgpstests.h"
#include "navigator_test.h"
#include "ir_interpolate_test.h"
#include "driver_test.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
