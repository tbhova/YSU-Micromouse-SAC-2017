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
#include "abstracthardwaremanager.h"

using namespace testing;
using namespace std;

class MockHardwareManager : public AbstractHardwareManager {
public:
//    MockHardwareManager() {}
    MOCK_CONST_METHOD0(isLeftWall, bool());
    MOCK_CONST_METHOD0(isCenterWall, bool());
    MOCK_CONST_METHOD0(isRightWall, bool());
};

class DriverTest : public ::testing::Test {
protected:
    StopGoDriver driver = StopGoDriver(new MockHardwareManager());

};

TEST_F(DriverTest, locationTest) {
    EXPECT_EQ(driver.getCurrentLocation(), Coordinate(0,0));
}

TEST_F(DriverTest, getVarTest) {
    driver.drive(North);
    driver.drive(East);
    driver.drive(East);
    // cppcheck-suppress compareBoolExpressionWithInt
    EXPECT_EQ(driver.getX(), static_cast<unsigned int>(2));
    // cppcheck-suppress compareBoolExpressionWithInt
    EXPECT_EQ(driver.getY(), static_cast<unsigned int>(1));
}

#endif // DRIVER_TEST_H
