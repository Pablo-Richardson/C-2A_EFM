#pragma once
#include <cmath>
#include "Vec3.h"
#include "forcesMoments.h"

#ifdef BUILDING_MY_DLL
#define MY_API __declspec(dllexport)
#else
#define MY_API __declspec(dllimport)
#endif

struct MY_API Quaternion {
    double w, x, y, z;

    Quaternion(double w_s, double x_s, double y_s, double z_s);

    Quaternion conjugate() const;
    Quaternion operator*(const Quaternion& q) const;
    void normalize();
};

MY_API void rotateVectorByQuaternion(const Quaternion& q, Vec3& vec);
MY_API ForcesMoments rotateForcesByQuaternion(const ForcesMoments& fm, const Quaternion& q);
MY_API ForcesMoments rotateMomentsByQuaternion(const ForcesMoments& fm, const Quaternion& q);
