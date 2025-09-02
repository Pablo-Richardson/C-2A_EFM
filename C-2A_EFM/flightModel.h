#pragma once
#include "Vec3.h"
#include "forcesMoments.h"
#include "state.h"
#include "constants.h"

class FlightModel {
public:
    static ForcesMoments calculateAerodynamics(const State& state, double airDensity) {
        double CL = 1 + std::sin(state.getAlpha()); // Filler for now
        double CD = 1; // Filler for now

        double q = 0.5 * airDensity * std::pow(state.getTAS(), 2); 

        double lift = q * wingArea * CL;
        double drag = q * frontalArea * CD;

        // Assume lift is in +Y, drag is in -X (body axes)
        Vec3 force(-drag, lift, 0.0);
        Vec3 moment(0.0, 0.0, 0.0); // Empty for now, moments will be done only with control surfaces

        return ForcesMoments(force, moment);
    }
};