#ifndef IR_INTERPOLATE_TEST_H
#define IR_INTERPOLATE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/src/interpolateir.h"
#include "../../src/src/interpolateir.cpp"

#include <vector>
#include <algorithm>

TEST(InterpolateIr, TestInterpolationBoundaries) {
    InterpolateIR interpolate;

    //Lower Boundary
    ASSERT_EQ(interpolate.getDistance(624), 3000);
    ASSERT_EQ(interpolate.getDistance(625), 3000);

    //Below Lower Boundary
    ASSERT_EQ(interpolate.getDistance(647), -2);

    //Upper Boundary
    ASSERT_EQ(interpolate.getDistance(65), 40000);
    ASSERT_EQ(interpolate.getDistance(64), 40000);

    //Above upper boundary
    ASSERT_EQ(interpolate.getDistance(42), -1);
}

TEST(InterpolateIr, TestInterpolationExactValues) {
    InterpolateIR interpolate;

    //Middle Values - No Interpolation
    ASSERT_EQ(interpolate.getDistance(214), 12000);
    ASSERT_EQ(interpolate.getDistance(188), 14000);
}

TEST(InterpolateIr, TestInterpolationCenterInterpolate) {
    InterpolateIR interpolate;

    //Middle Values - Middle Interpolate, even split
    ASSERT_EQ(interpolate.getDistance(201), 13000);
}

TEST(InterpolateIr, TestInterpolationHighLowInterpolate) {
    InterpolateIR interpolate;

    //Middle Values - Lower Distance Interpolate
    ASSERT_EQ(interpolate.getDistance(208), 13538);

    //Middle Values - Upper Distance Interpolate
    EXPECT_EQ(interpolate.getDistance(201), 13308);
    EXPECT_EQ(interpolate.getDistance(200), 13308);
    EXPECT_EQ(interpolate.getDistance(199), 13308);
    EXPECT_EQ(interpolate.getDistance(198), 13308);
    EXPECT_EQ(interpolate.getDistance(197), 13308);
    EXPECT_EQ(interpolate.getDistance(196), 13308);
    EXPECT_EQ(interpolate.getDistance(195), 13308);

}

#endif // IR_INTERPOLATE_TEST_H
