#pragma once
// This struct is my custom struct allowing for forces and moments to be added up
struct ForcesMoments {
    double force[3];   // body axis
    double moment[3];  // body axis

	// Addition operator for ForcesMoments
    ForcesMoments operator+(const ForcesMoments& other) const {
        ForcesMoments result;
        for (int i = 0; i < 3; ++i) {
            result.force[i] = this->force[i] + other.force[i];
            result.moment[i] = this->moment[i] + other.moment[i];
        }
        return result;
    }

	// Addition assignment operator for ForcesMoments
    ForcesMoments& operator+=(const ForcesMoments& other) {
        for (int i = 0; i < 3; ++i) {
            force[i] += other.force[i];
            moment[i] += other.moment[i];
        }
        return *this;
    }
	// Default constructor initializes forces and moments to zero
    ForcesMoments() : force{ 0.0, 0.0, 0.0 }, moment{ 0.0, 0.0, 0.0 } {}
	// Constructor to initialize forces and moments with given values
    ForcesMoments(const double f[3], const double m[3]) {
        for (int i = 0; i < 3; ++i) {
            force[i] = f[i];
            moment[i] = m[i];
        }
    }
};
// Function to sum all forces and moments
ForcesMoments sumAllForcesMoments(ForcesMoments lift, ForcesMoments drag, ForcesMoments thrust)
{
    return (lift + drag + thrust);
}