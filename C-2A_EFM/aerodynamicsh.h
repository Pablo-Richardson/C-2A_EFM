#pragma once
#include "atmosphere.h"
#include "state.h"
#include "massProperties.h"
#include "controls.h"
#include "forcesMoments.h"
#include "engine.h"
#include "constants.h"
#include <vector>

class FlightModel
{
private:
	ControlInputs controls;
	Atmosphere atmosphere;
	State state;
	MassProperties massProperties;
	ForcesMoments forcesMoments;
};