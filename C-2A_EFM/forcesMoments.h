#pragma once
#include "Vec3.h"
// This struct is my custom struct allowing for forces and moments to be added up
struct ForcesMoments {
    Vec3 force;   // body axis
    Vec3 moment;  // body axis

	// Addition operator for ForcesMoments
    ForcesMoments operator+(const ForcesMoments& other) const {
        ForcesMoments result;
		result.force = this->force + other.force;
		result.moment = this->moment + other.moment;
        return result;
    }

	// Addition assignment operator for ForcesMoments
    ForcesMoments& operator+=(const ForcesMoments& other) {
		force += other.force;
		moment += other.moment;
        return *this;
    }
	// Default constructor initializes forces and moments to zero
    ForcesMoments() : force{ 0.0, 0.0, 0.0 }, moment{ 0.0, 0.0, 0.0 } {}
	// Constructor to initialize forces and moments with given values
    ForcesMoments(const Vec3 force_s, const Vec3 moment_s) {
		force = force_s;
		moment = moment_s;
    }
};
// Function to sum all forces and moments
ForcesMoments sumAllForcesMoments(ForcesMoments lift, ForcesMoments drag, ForcesMoments thrust)
{
    return (lift + drag + thrust);
}