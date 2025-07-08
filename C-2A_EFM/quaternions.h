#include <iostream>
#include <cmath>
#include "Vec3.h"
#include "ForcesMoments.h"

// Quaternion struct
struct Quaternion {
    double w, x, y, z;

    // Constructor to initialize a quaternion with given values
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
void rotateVectorByQuaternion(const Quaternion& q, Vec3& vec) {
    Quaternion qNorm = q;
    qNorm.normalize();
    Quaternion qConj = qNorm.conjugate();

    Quaternion qVec = { 0, vec.x, vec.y, vec.z };
    Quaternion result = qNorm * qVec * qConj;

    vec.x = result.x;
    vec.y = result.y;
    vec.z = result.z;
}

// Rotate force vector of ForcesMoments using a quaternion
ForcesMoments rotateForcesByQuaternion(const ForcesMoments& fm, const Quaternion& q) {
    ForcesMoments rotated = fm;
    rotateVectorByQuaternion(q, rotated.force);
    // To also rotate the moment:
    // rotateVectorByQuaternion(q, rotated.moment);
    return rotated;
}
