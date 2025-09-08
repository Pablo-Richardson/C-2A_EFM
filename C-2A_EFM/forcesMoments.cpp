#include "forcesMoments.h"

ForcesMoments::ForcesMoments() : force{ 0.0, 0.0, 0.0 }, moment{ 0.0, 0.0, 0.0 } {}

ForcesMoments::ForcesMoments(const Vec3 force_s, const Vec3 moment_s) {
    force = force_s;
    moment = moment_s;
}

ForcesMoments ForcesMoments::operator+(const ForcesMoments& other) const {
    ForcesMoments result;
    result.force = this->force + other.force;
    result.moment = this->moment + other.moment;
    return result;
}

ForcesMoments& ForcesMoments::operator+=(const ForcesMoments& other) {
    force += other.force;
    moment += other.moment;
    return *this;
}

ForcesMoments sumAllForcesMoments(ForcesMoments lift, ForcesMoments drag, ForcesMoments thrust) {
    return (lift + drag + thrust);
}
