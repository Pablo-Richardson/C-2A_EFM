#pragma once
#include "constants.h"
#include <vector>
// Keeps track of atmospheric conditions and provides them to the flight model - Recieves data from DCS
// Done
struct AtmosphereData {
	double dens, alt, temp, press, wind[3];
};

class Atmosphere
{
public:
	void update(const AtmosphereData& data) { this->data = data; }
	const AtmosphereData& get() const { return data; }
	// Default constructor
	Atmosphere() : data{} {}
private:
	AtmosphereData data;
};