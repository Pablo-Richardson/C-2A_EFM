#pragma once
#include <cmath>
#include "Vec3.h"
#include "forcesMoments.h"


struct Quaternion {
    double w, x, y, z;

    Quaternion(double w_s, double x_s, double y_s, double z_s);

    Quaternion conjugate() const;
    Quaternion operator*(const Quaternion& q) const;
    void normalize();
};

void rotateVectorByQuaternion(const Quaternion& q, Vec3& vec);
ForcesMoments rotateForcesByQuaternion(const ForcesMoments& fm, const Quaternion& q);
ForcesMoments rotateMomentsByQuaternion(const ForcesMoments& fm, const Quaternion& q);
