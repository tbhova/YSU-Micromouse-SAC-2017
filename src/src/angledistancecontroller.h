#ifndef ANGLEDISTANCECONTROLLER_H
#define ANGLEDISTANCECONTROLLER_H


class AngleDistanceController {
public:
    AngleDistanceController();
    static double getNewOmega(const double angleTraveled, const double angleSet);
    int getNewVelocity(const double distTraveled, const double distSet);
private:
    int lastVelocity = 0, lastVelocityTime = 0;
};

#endif // ANGLEDISTANCECONTROLLER_H
