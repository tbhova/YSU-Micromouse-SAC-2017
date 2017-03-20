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
#include "../../src/src/hardwaremanager.cpp"
#include "../../src/src/infraredsensorarray.cpp"
#include "../../src/src/infraredsensor.cpp"


using namespace testing;
using namespace std;

class DriverTest : public ::testing::Test {
protected:
    StopGoDriver driver = StopGoDriver();

};

TEST_F(DriverTest, locationTest) {
    EXPECT_EQ(driver.getCurrentLocation(), Coordinate(0,0));
}
TEST_F(DriverTest, getVarTest) {
    driver.drive(North);
    EXPECT_EQ(driver.getX(), 0);
    EXPECT_EQ(driver.getY(), 1);

}



#endif // DRIVER_TEST_H
