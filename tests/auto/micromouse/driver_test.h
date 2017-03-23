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
<<<<<<< HEAD
#include "hardwaremanager.h"
=======

>>>>>>> driver-edits

using namespace testing;
using namespace std;

<<<<<<< HEAD
//class MockHardwareManager : public HardwareManager {
//public:
//    MockHardwareManager() {}
//    MOCK_CONST_METHOD0(isLeftWall, bool());
//    MOCK_CONST_METHOD0(isCenterWall, bool());
//    MOCK_CONST_METHOD0(isRightWall, bool());
//};

//class DriverTest : public ::testing::Test {
//protected:
//    StopGoDriver driver = StopGoDriver(new MockHardwareManager());

//};

//TEST_F(DriverTest, locationTest) {
//    EXPECT_EQ(driver.getCurrentLocation(), Coordinate(0,0));
//}
//TEST_F(DriverTest, getVarTest) {
//    driver.drive(North);
//    driver.drive(East);
//    driver.drive(East);
//    // cppcheck-suppress compareBoolExpressionWithInt
//    EXPECT_EQ(driver.getX(), static_cast<unsigned int>(2));
//    EXPECT_EQ(driver.getY(), static_cast<unsigned int>(1));
//}
=======
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


>>>>>>> driver-edits

#endif // DRIVER_TEST_H
