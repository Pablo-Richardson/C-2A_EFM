#pragma once
#include "constants.h"
#include "forcesMoments.h"
#include "state.h"
#include <iostream>

class Engine
{
public:
    // Getters
    double getThrust() const { return thrust; }
    double getRPM() const { return rpm; }
    double getFuelFlow() const { return fuelFlow; }
    bool getIsRunning() const { return isRunning; }

    Engine() : rpm(0.0), thrust(0.0), fuelFlow(0.0), isRunning(true) {}

    void update(double throttlePos)
    {
        if (getIsRunning() == true)
        {
            rpm = maxRPM * throttlePos;
            thrust = (rpm / maxRPM) * 44540; // Thrust in Newtons
            fuelFlow = (rpm / maxRPM) * 10; // Fuel flow in kg/s
        }
    }

    // Static method for bus.cpp to use
    static ForcesMoments getThrust(const State& state)
    {
        static Engine engine; // Static engine instance
        engine.update(1.0); // For now, assume full throttle - replace with actual throttle input

        // Create force vector (thrust in X direction, no Y or Z forces)
        Vec3 force(engine.getThrust(), 0.0, 0.0);
        Vec3 moment(0.0, 0.0, 0.0); // No engine moments for now

        return ForcesMoments(force, moment);
    }

private:
    double rpm;
    double thrust;
    double fuelFlow;
    bool isRunning;
};
