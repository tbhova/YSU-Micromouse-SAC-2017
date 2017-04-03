#ifndef IR_INTERPOLATE_TEST_H
#define IR_INTERPOLATE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <vector>
#include <algorithm>

#include "interpolateir.h"

TEST(InterpolateIr, TestInterpolationLowerBoundaries) {
    InterpolateIR interpolate;
    ASSERT_EQ(interpolate.getDistance(624), 79);
    ASSERT_EQ(interpolate.getDistance(625), 79);
//    ASSERT_EQ(interpolate.getDistance(624), 30);
//    ASSERT_EQ(interpolate.getDistance(625), 30);
}

TEST(InterpolateIr, TestInterpolationBeyondBoundaries) {
    InterpolateIR interpolate;
    ASSERT_EQ(interpolate.getDistance(647), 76);
    ASSERT_EQ(interpolate.getDistance(42), 400);
}

TEST(InterpolateIr, TestInterpolationUpperBoundary) {
    InterpolateIR interpolate;
//    ASSERT_EQ(interpolate.getDistance(65), 400);
    ASSERT_EQ(interpolate.getDistance(65), 387);
    ASSERT_EQ(interpolate.getDistance(64), 389);
}

TEST(InterpolateIr, TestInterpolationExactValues) {
    InterpolateIR interpolate;

    //Middle Values - No Interpolation
//    ASSERT_EQ(interpolate.getDistance(214), 120);
//    ASSERT_EQ(interpolate.getDistance(188), 140);
    ASSERT_EQ(interpolate.getDistance(214), 219);
    ASSERT_EQ(interpolate.getDistance(188), 236);
}

TEST(InterpolateIr, TestInterpolationCenterInterpolate) {
    InterpolateIR interpolate;

    //Middle Values - Middle Interpolate, even split
//    ASSERT_EQ(interpolate.getDistance(201), 130);
    ASSERT_EQ(interpolate.getDistance(201), 227);
}

TEST(InterpolateIr, TestInterpolationHighLowInterpolate) {
    InterpolateIR interpolate;

    //Middle Values - Lower Distance Interpolate
//    ASSERT_EQ(interpolate.getDistance(208), 124);
    ASSERT_EQ(interpolate.getDistance(208), 223);

    //Middle Values - Upper Distance Interpolate
    EXPECT_EQ(interpolate.getDistance(201), 227);
    EXPECT_EQ(interpolate.getDistance(200), 228);
    EXPECT_EQ(interpolate.getDistance(199), 228);
    EXPECT_EQ(interpolate.getDistance(198), 229);
    EXPECT_EQ(interpolate.getDistance(197), 230);
    EXPECT_EQ(interpolate.getDistance(196), 230);
    EXPECT_EQ(interpolate.getDistance(195), 231);
}

#endif // IR_INTERPOLATE_TEST_H
