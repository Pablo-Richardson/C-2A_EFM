#pragma once
#include "forcesMoments.h"
#include <vector>
// Store state of aicraft 
// Done

class State {
public:
    
private:
    //State Data

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
