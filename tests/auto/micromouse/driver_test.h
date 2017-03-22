#ifndef DRIVER_TEST_H
#define DRIVER_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <gmock/gmock.h>

#include "coordinate.h"
#include "cardinal8.h"
#include "abstractdriver.h"
#include "driver.h"
#include "stopgodriver.h"


using namespace testing;
using namespace std;

class MockHwManager: public HardwareManager {
public:
    MockDriver() {}
    MOCK_METHOD1(drive, void(std::stack<Cardinal8> &directions));
    MOCK_METHOD2(drive, void(const Cardinal8 dir, const int cells));
    MOCK_METHOD1(drive, void(const Cardinal8 dir));
    MOCK_METHOD0(getCurrentLocation, Coordinate());
    MOCK_METHOD0(getWalls, std::vector<Cardinal8>());
};

class DriverTest : public ::testing::Test {
protected:
    StopGoDriver driver = StopGoDriver();

};

TEST_F(DriverTest, locationTest) {
    EXPECT_EQ(driver.getCurrentLocation(), Coordinate(0,0));
}
TEST_F(DriverTest, getVarTest) {
    driver.drive(North);
    driver.drive(East);
    driver.drive(East);
    EXPECT_EQ(driver.getX(), 2);
    EXPECT_EQ(driver.getY(), 1);
    EXPECT_EQ(driver.getDirection(), East);
}



#endif // DRIVER_TEST_H
