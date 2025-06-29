#pragma once
struct ForcesMoments {
    double force[3];   // body axis
    double moment[3];  // body axis

    ForcesMoments operator+(const ForcesMoments& other) const {
        ForcesMoments result;
        for (int i = 0; i < 3; ++i) {
            result.force[i] = this->force[i] + other.force[i];
            result.moment[i] = this->moment[i] + other.moment[i];
        }
        return result;
    }

    ForcesMoments& operator+=(const ForcesMoments& other) {
        for (int i = 0; i < 3; ++i) {
            force[i] += other.force[i];
            moment[i] += other.moment[i];
        }
        return *this;
    }
};