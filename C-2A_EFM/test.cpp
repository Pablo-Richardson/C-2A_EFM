#include "iostream"
#include <cmath>
#include "forcesMoments.h"
#include "quaternions.h"

int main(int argc, char* argv[])
{
    double liftForce[3] = { 0, 25000, 0.0 };
    double dragForce[3] = { -5000, 0.0, 0.0 };
    double emptyMoment[3] = { 0.0, 0.0, 0.0 };
    ForcesMoments fmLift(liftForce, emptyMoment);
    ForcesMoments fmDrag(dragForce, emptyMoment);

    Quaternion q = { 12, 18, 40, 25 };

    fmLift = rotateForcesByQuaternion(fmLift, q);
    fmDrag = rotateForcesByQuaternion(fmDrag, q);

    std::cout << "Rotated Lift Force: ("
        << fmLift.force[0] << ", "
        << fmLift.force[1] << ", "
        << fmLift.force[2] << ")\n";

	float totalMagnitude = std::sqrt(
		fmLift.force[0] * fmLift.force[0] +
		fmLift.force[1] * fmLift.force[1] +
		fmLift.force[2] * fmLift.force[2]
	);

	std::cout << "Rotated Drag Force: ("
		<< fmDrag.force[0] << ", "
		<< fmDrag.force[1] << ", "
		<< fmDrag.force[2] << ")\n";

	std::cout << "Total Magnitude of Lift Force: "
		<< totalMagnitude << "\n";
}