#ifndef IR_INTERPOLATE_TEST_H
#define IR_INTERPOLATE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/src/interpolateir.h"
#include "../../src/src/interpolateir.cpp"

#include <vector>
#include <algorithm>

TEST(InterpolateIr, TestInterpolationLowerBoundaries) {
    InterpolateIR interpolate;
    ASSERT_EQ(interpolate.getDistance(624), 3000);
    ASSERT_EQ(interpolate.getDistance(625), 3000);
}

TEST(InterpolateIr, TestInterpolationBeyondBoundaries) {
    InterpolateIR interpolate;
    ASSERT_EQ(interpolate.getDistance(647), 3000);
    ASSERT_EQ(interpolate.getDistance(42), 40000);
}

TEST(InterpolateIr, TestInterpolationUpperBoundary) {
    InterpolateIR interpolate;
    ASSERT_EQ(interpolate.getDistance(65), 40000);
    ASSERT_EQ(interpolate.getDistance(64), 40000);
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
    ASSERT_EQ(interpolate.getDistance(208), 12461);

    //Middle Values - Upper Distance Interpolate
    EXPECT_EQ(interpolate.getDistance(201), 13000);
    EXPECT_EQ(interpolate.getDistance(200), 13076);
    EXPECT_EQ(interpolate.getDistance(199), 13153);
    EXPECT_EQ(interpolate.getDistance(198), 13230);
    EXPECT_EQ(interpolate.getDistance(197), 13307);
    EXPECT_EQ(interpolate.getDistance(196), 13384);
    EXPECT_EQ(interpolate.getDistance(195), 13461);
}

#endif // IR_INTERPOLATE_TEST_H
