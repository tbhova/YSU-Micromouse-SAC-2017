#ifndef DIFFERENTIALDRIVEVELOCITY_H
#define DIFFERENTIALDRIVEVELOCITY_H

struct DifferentialDriveVelcity {
    int left, right;

    DifferentialDriveVelcity(const int leftVelocity, const int rightVelocity) : left(leftVelocity), right(rightVelocity) {}
};

#endif // DIFFERENTIALDRIVEVELOCITY_H
