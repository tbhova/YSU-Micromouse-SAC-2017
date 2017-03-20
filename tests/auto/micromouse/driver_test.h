#ifndef DRIVER_TEST_H
#define DRIVER_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>

#include "../../src/src/coordinate.h"
#include "../../src/src/cardinal8.h"
#include "../../src/src/abstractdriver.h"
#include "../../src/src/driver.h"
#include "../../src/src/driver.cpp"
#include "../../src/src/stopgodriver.h"
#include "../../src/src/stopgodriver.cpp"

#include <vector>

using namespace testing;
using namespace std;

class DriverTest : public ::testing::Test {


};

TEST_F(DriverTest, locationTest) {
//    EXPECT_EQ(getCurrentLocation(),0);
   // EXPECT_EQ(,East);
}
TEST_F(DriverTest, driveTest) {
    StopGoDriver driver;
    driver.drive(North);
}
TEST_F(DriverTest, getVarTest) {
//    EXPECT_EQ(getX(), 0);
//    EXPECT_EQ(getY(), 1);

}



#endif // DRIVER_TEST_H
