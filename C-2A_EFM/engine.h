#pragma once
#include "constants.h"
#include "forcesMoments.h"
#include "state.h"
#include <iostream>

class Engine
{
public:
    Engine();

    // Getters
    double getThrust() const;
    double getRPM() const;
    double getFuelFlow() const;
    bool getIsRunning() const;

    void update(double throttlePos);

    // Static method for bus.cpp to use
    static ForcesMoments getThrust(const State& state);

private:
    double rpm;
    double thrust;
    double fuelFlow;
    bool isRunning;
};
