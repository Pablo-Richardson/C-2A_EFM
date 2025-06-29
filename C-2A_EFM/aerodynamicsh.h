#pragma once
#include "atmosphere.h"
#include "constants.h"
#include "controls.h"
#include "engine.h"
#include "forcesMoments.h"
#include "massProperties.h"
#include "state.h"

double calculateLift(double dens, double cl, double velocity)
{
	return (wingArea * dens * velocity * velocity * cl) / 2.0; // Lift = 0.5 * rho * V^2 * S * CL
}
double calculateDrag(double dens, double cd, double velocity)
{
	return (frontalArea * dens * velocity * velocity * cd) / 2.0; // Drag = 0.5 * rho * V^2 * S * CD
}
double calculateMoments(double dens, double lift)
{

}