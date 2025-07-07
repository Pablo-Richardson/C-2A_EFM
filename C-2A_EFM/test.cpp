#include "iostream"
#include "cmath"
#include "forcesMoments.h"
#include "quaternions.h"

int main(int argc, char* argv[])
{
    double liftForce[3] = { 0, 10000, 0.0 };
    double dragForce[3] = { -5000, 0.0, 0.0 };
    double emptyMoment[3] = { 0.0, 0.0, 0.0 };
    ForcesMoments fmLift(liftForce, emptyMoment);
    ForcesMoments fmDrag(dragForce, emptyMoment);

    Quaternion q = { 0.51, 0.9, 0.71421, 0.0 };

    fmLift = rotateForcesByQuaternion(fmLift, q);
    fmDrag = rotateForcesByQuaternion(fmDrag, q);

    std::cout << "Rotated Lift Force: ("
        << fmLift.force[0] << ", "
        << fmLift.force[1] << ", "
        << fmLift.force[2] << ")\n";
}