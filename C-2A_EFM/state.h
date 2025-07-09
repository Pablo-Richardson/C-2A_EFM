#pragma once
#include "forcesMoments.h"
#include "quaternions.h"
#include <vector>
// Store state of aicraft

class State {
public:
    // Empty Constructor
	State() : pos{ 0, 0, 0 }, vel{ 0, 0, 0 }, forceMoment{}, quat{ 1, 0, 0, 0 }, alpha(0), beta(0), TAS(0), GS(0) {}
	// Copy Constructor
	State(Vec3 pos_s, Vec3 vel_s, ForcesMoments forceMoment_s, Quaternion quat_s, double alpha_s, double beta_s, double TAS_s, double GS_s)
		: pos(pos_s), vel(vel_s), forceMoment(forceMoment_s), quat(quat_s), alpha(alpha_s), beta(beta_s), TAS(TAS_s), GS(GS_s) {}
private:
    Vec3 pos, vel;
    ForcesMoments forceMoment;
    Quaternion quat;
    double alpha, beta, TAS, GS;
};


/*

struct StateData {
    double pos[3], vel[3], force[3], quat[4], alpha, beta; // Pos is world pos
};


class State {
public:
    // Updates state
    void update(const StateData& newState) { data = newState; }

    // Returns reference to state
    const StateData& getState() const { return data; }

    // Empty constructor
    State() : data{} {}

    // Full constructor
    State(const double pos[3], const double vel[3], const double force[3], const double quat[4],
        double alpha, double beta)
    {
        for (int i = 0; i < 3; ++i) {
            data.pos[i] = pos[i];
            data.vel[i] = vel[i];
            data.force[i] = force[i];
        }
        for (int i = 0; i < 4; ++i) {
            data.quat[i] = quat[i];
        }
        data.alpha = alpha;
        data.beta = beta;
    }
private:
    StateData data;
};

*/
