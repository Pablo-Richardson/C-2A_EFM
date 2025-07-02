#pragma once
// File for quaternion normalisation and converting force magnitudes into a vector 
#include <cmath>
#include "constants.h"
#include "forcesMoments.h"

// Normalise a quaternion
void normalizeQuaternion(double& x, double& y, double& z, double& w) {
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
		w = 1.0; // Default to identity quaternion
	}
}

//Convert a force magnitude into a vector based on the quaternion orientation
ForcesMoments forceMagnitudeToVector(double forceMagnitude, double qx, double qy, double qz, double qw) {
	// Normalize the quaternion first
	ForcesMoments splitUpForce;
	normalizeQuaternion(qx, qy, qz, qw);
	// Calculate the force vector components
	
	return splitUpForce; 
}