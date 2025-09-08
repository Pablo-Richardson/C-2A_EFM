#include "engine.h"

Engine::Engine() : rpm(0.0), thrust(0.0), fuelFlow(0.0), isRunning(true) {}

double Engine::getThrust() const { return thrust; }
double Engine::getRPM() const { return rpm; }
double Engine::getFuelFlow() const { return fuelFlow; }
bool Engine::getIsRunning() const { return isRunning; }

void Engine::update(double throttlePos)
{
    if (getIsRunning() == true)
    {
        rpm = maxRPM * throttlePos;
        thrust = (rpm / maxRPM) * 44540; // Thrust in Newtons
        fuelFlow = (rpm / maxRPM) * 10; // Fuel flow in kg/s
    }
}

ForcesMoments Engine::getThrust(const State& state)
{
    static Engine engine; // Static engine instance
    engine.update(1.0); 

    // Create force vector (thrust in X direction, no Y or Z forces)
    Vec3 force(engine.getThrust(), 0.0, 0.0);
    Vec3 moment(0.0, 0.0, 0.0); // No engine moments for now

    return ForcesMoments(force, moment);
}
