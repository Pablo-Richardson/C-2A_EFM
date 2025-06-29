#pragma once
// Done
#include "constants.h"
#include <iostream>
class Engine
{
public:
	// Getters
	double getThrust() const { return thrust; }
	double getRPM() const { return rpm; }
	double getFuelFlow() const { return fuelFlow; }
	Engine() : rpm(0.0), thrust(0.0), fuelFlow(0.0) {}
	// Update RPM based on throttle
	void update(double throttlePos)
	{
		rpm = maxRPM * throttlePos; // Scale RPM based on throttle position
		thrust = (rpm / maxRPM) * 44540; // Thrust in Newtons (assuming max thrust is 44540 N at max RPM)
		double fuelFlow = (rpm / maxRPM) * 10; // Fuel flow in kg/s
	}
private:
	double rpm;
	double thrust;
	double fuelFlow;
};