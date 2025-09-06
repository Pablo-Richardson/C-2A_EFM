#pragma once
#include "Vec3.h"
#include "forcesMoments.h"
#include "state.h"
#include "constants.h"
#include <cmath>

class FlightModel {
public:
    static ForcesMoments calculateAerodynamics(const State& state, double airDensity) {
        double CL = 1 + std::sin(state.getAlpha());
        double CD = 1;

        // CRITICAL: Get speed - use TAS if available, otherwise use velocity magnitude
        double speed = state.getTAS();
        if (speed == 0.0) {
            speed = state.getVel().magnitude();
        }

        double q = 0.5 * airDensity * std::pow(speed, 2);

        double lift = q * wingArea * CL;
        double drag = q * frontalArea * CD;

        Vec3 force(-drag, lift, 0.0);
        Vec3 moment(0.0, 0.0, 0.0);

        return ForcesMoments(force, moment);
    }
};
