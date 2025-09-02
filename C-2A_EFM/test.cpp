#include <iostream>
#include <cmath>
#include "Vec3.h"
#include "quaternions.h"
#include "forcesMoments.h"

void testVec3() {
    std::cout << "\n--- Vec3 Tests ---\n";
    Vec3 a(1.0, 2.0, 3.0);
    Vec3 b(4.0, 5.0, 6.0);

    // Assignment
    Vec3 assign = a;
    assign = b;
    std::cout << "Assignment:      (" << assign.x << ", " << assign.y << ", " << assign.z << ") | Expected: (4, 5, 6)\n";

    // Addition
    Vec3 add = a + b;
    std::cout << "Addition:        (" << add.x << ", " << add.y << ", " << add.z << ") | Expected: (5, 7, 9)\n";

    // Addition assignment
    Vec3 addAssign = a;
    addAssign += b;
    std::cout << "Add Assignment:  (" << addAssign.x << ", " << addAssign.y << ", " << addAssign.z << ") | Expected: (5, 7, 9)\n";

    // Subtraction
    Vec3 sub = b - a;
    std::cout << "Subtraction:     (" << sub.x << ", " << sub.y << ", " << sub.z << ") | Expected: (3, 3, 3)\n";

    // Subtraction assignment
    Vec3 subAssign = b;
    subAssign -= a;
    std::cout << "Sub Assignment:  (" << subAssign.x << ", " << subAssign.y << ", " << subAssign.z << ") | Expected: (3, 3, 3)\n";

    // Negative
    Vec3 neg = -a;
    std::cout << "Negative:        (" << neg.x << ", " << neg.y << ", " << neg.z << ") | Expected: (-1, -2, -3)\n";

    // Scalar multiplication
    Vec3 mul = a * 2.0;
    std::cout << "Scalar Mult:     (" << mul.x << ", " << mul.y << ", " << mul.z << ") | Expected: (2, 4, 6)\n";

    // Scalar multiplication assignment
    Vec3 mulAssign = a;
    mulAssign *= 2.0;
    std::cout << "Mult Assignment: (" << mulAssign.x << ", " << mulAssign.y << ", " << mulAssign.z << ") | Expected: (2, 4, 6)\n";

    // Scalar division
    Vec3 div = b / 2.0;
    std::cout << "Scalar Div:      (" << div.x << ", " << div.y << ", " << div.z << ") | Expected: (2, 2.5, 3)\n";

    // Scalar division assignment
    Vec3 divAssign = b;
    divAssign /= 2.0;
    std::cout << "Div Assignment:  (" << divAssign.x << ", " << divAssign.y << ", " << divAssign.z << ") | Expected: (2, 2.5, 3)\n";

    // Square root
    Vec3 sqrtVec = Vec3(4.0, 9.0, 16.0).sqrtVec();
    std::cout << "Sqrt:            (" << sqrtVec.x << ", " << sqrtVec.y << ", " << sqrtVec.z << ") | Expected: (2, 3, 4)\n";

    // Magnitude
    double mag = a.magnitude();
    std::cout << "Magnitude:        " << mag << " | Expected: " << std::sqrt(1 * 1 + 2 * 2 + 3 * 3) << "\n";

    // Normalize
    Vec3 norm = a.normalize();
    double expectedMag = std::sqrt(1 * 1 + 2 * 2 + 3 * 3);
    std::cout << "Normalize:        (" << norm.x << ", " << norm.y << ", " << norm.z << ") | Expected: ("
        << 1.0 / expectedMag << ", " << 2.0 / expectedMag << ", " << 3.0 / expectedMag << ")\n";

    // Dot product
    double dot = a.dot(b);
    std::cout << "Dot Product:      " << dot << " | Expected: 32\n";

    // Equality
    bool eq = (a == Vec3(1.0, 2.0, 3.0));
    std::cout << "Equality:         " << (eq ? "true" : "false") << " | Expected: true\n";

    // Inequality
    bool neq = (a != b);
    std::cout << "Inequality:       " << (neq ? "true" : "false") << " | Expected: true\n";
}

void testQuaternion() {
    std::cout << "\n--- Quaternion Tests ---\n";
    Quaternion q1(1, 0, 0, 0); // Identity
    Quaternion q2(0, 1, 0, 0); // 180 deg about X

    // Conjugate
    Quaternion conj = q2.conjugate();
    std::cout << "Conjugate:        (" << conj.w << ", " << conj.x << ", " << conj.y << ", " << conj.z << ") | Expected: (0, -1, 0, 0)\n";

    // Multiplication
    Quaternion mult = q1 * q2;
    std::cout << "Multiplication:   (" << mult.w << ", " << mult.x << ", " << mult.y << ", " << mult.z << ") | Expected: (0, 1, 0, 0)\n";

    // Normalization
    Quaternion q3(2, 0, 0, 0);
    q3.normalize();
    std::cout << "Normalize:        (" << q3.w << ", " << q3.x << ", " << q3.y << ", " << q3.z << ") | Expected: (1, 0, 0, 0)\n";

    // Rotate vector
    Vec3 v(0, 1, 0);
    Quaternion qRot(std::sqrt(0.5), 0, std::sqrt(0.5), 0); // 90 deg about Y
    Vec3 vRot = v;
    rotateVectorByQuaternion(qRot, vRot);
    std::cout << "Rotate Vec:       (" << vRot.x << ", " << vRot.y << ", " << vRot.z << ") | Expected: (0, 1, 0)\n";
}

void testForcesMoments() {
    std::cout << "\n--- ForcesMoments Tests ---\n";
    Vec3 f1(1, 2, 3), m1(4, 5, 6);
    Vec3 f2(10, 20, 30), m2(40, 50, 60);

    ForcesMoments fm1(f1, m1);
    ForcesMoments fm2(f2, m2);

    // Addition
    ForcesMoments fmAdd = fm1 + fm2;
    std::cout << "Add Forces:       (" << fmAdd.force.x << ", " << fmAdd.force.y << ", " << fmAdd.force.z << ") | Expected: (11, 22, 33)\n";
    std::cout << "Add Moments:      (" << fmAdd.moment.x << ", " << fmAdd.moment.y << ", " << fmAdd.moment.z << ") | Expected: (44, 55, 66)\n";

    // Addition assignment
    ForcesMoments fmAssign = fm1;
    fmAssign += fm2;
    std::cout << "AddAssign Forces: (" << fmAssign.force.x << ", " << fmAssign.force.y << ", " << fmAssign.force.z << ") | Expected: (11, 22, 33)\n";
    std::cout << "AddAssign Moments:(" << fmAssign.moment.x << ", " << fmAssign.moment.y << ", " << fmAssign.moment.z << ") | Expected: (44, 55, 66)\n";

    // Default constructor
    ForcesMoments fmDefault;
    std::cout << "Default Forces:   (" << fmDefault.force.x << ", " << fmDefault.force.y << ", " << fmDefault.force.z << ") | Expected: (0, 0, 0)\n";
    std::cout << "Default Moments:  (" << fmDefault.moment.x << ", " << fmDefault.moment.y << ", " << fmDefault.moment.z << ") | Expected: (0, 0, 0)\n";
}

int main() {
    testVec3();
    testQuaternion();
    testForcesMoments();
    return 0;
}
