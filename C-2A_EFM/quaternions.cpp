#include "quaternions.h"

Quaternion::Quaternion(double w_s, double x_s, double y_s, double z_s)
    : w(w_s), x(x_s), y(y_s), z(z_s) {
}

Quaternion Quaternion::conjugate() const {
    return { w, -x, -y, -z };
}

Quaternion Quaternion::operator*(const Quaternion& q) const {
    return {
        w * q.w - x * q.x - y * q.y - z * q.z,
        w * q.x + x * q.w + y * q.z - z * q.y,
        w * q.y - x * q.z + y * q.w + z * q.x,
        w * q.z + x * q.y - y * q.x + z * q.w
    };
}

void Quaternion::normalize() {
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
        w = 1.0;
    }
}

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

ForcesMoments rotateForcesByQuaternion(const ForcesMoments& fm, const Quaternion& q) {
    ForcesMoments rotated = fm;
    rotateVectorByQuaternion(q, rotated.force);
    return rotated;
}

ForcesMoments rotateMomentsByQuaternion(const ForcesMoments& fm, const Quaternion& q) {
    ForcesMoments rotated = fm;
    rotateVectorByQuaternion(q, rotated.moment);
    return rotated;
}
