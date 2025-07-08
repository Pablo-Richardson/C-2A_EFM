#include <iostream>
#include <cmath>
#include "ForcesMoments.h"

// Quaternion struct
struct Quaternion {
    double w, x, y, z;

	Quaternion(double w, double x, double y, double z) : w(w), x(x), y(y), z(z) {}

    // Conjugate
    Quaternion conjugate() const {
        return { w, -x, -y, -z };
    }

    // Quaternion multiplication
    Quaternion operator*(const Quaternion& q) const {
        return {
            w * q.w - x * q.x - y * q.y - z * q.z,
            w * q.x + x * q.w + y * q.z - z * q.y,
            w * q.y - x * q.z + y * q.w + z * q.x,
            w * q.z + x * q.y - y * q.x + z * q.w
        };
    }

    // Normalize using external function
    void normalize() {
        double norm = std::sqrt(x * x + y * y + z * z + w * w);
        if (norm > 0.0) {
            x /= norm;
            y /= norm;
            z /= norm;
            w /= norm;
        }
        else {
            x = 0.0;
            y = 0.0;
            z = 0.0;
            w = 1.0; // Identity quaternion
        }
    }
};

// Rotate a 3D vector using a quaternion
void rotateVectorByQuaternion(const Quaternion& q, double vec[3]) {
    Quaternion qNorm = q;
    qNorm.normalize();
    Quaternion qConj = qNorm.conjugate();

    Quaternion qVec = { 0, vec[0], vec[1], vec[2] };
    Quaternion result = qNorm * qVec * qConj;

    vec[0] = result.x;
    vec[1] = result.y;
    vec[2] = result.z;
}

// Rotate force vector of ForcesMoments using a quaternion
ForcesMoments rotateForcesByQuaternion(const ForcesMoments& fm, const Quaternion& q) {
    ForcesMoments rotated = fm;
    rotateVectorByQuaternion(q, rotated.force);
    // To also rotate the moment:
    // rotateVectorByQuaternion(q, rotated.moment);
    return rotated;
}
