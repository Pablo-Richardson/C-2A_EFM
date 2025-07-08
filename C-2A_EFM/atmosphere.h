#pragma once
#include "constants.h"
#include <vector>
// Keeps track of atmospheric conditions and provides them to the flight model - Recieves data from DCS
// Replace array with vector!
struct AtmosphereData {
	double dens, alt, temp, press, wind[3];
};

class Atmosphere
{
public:
	void update(const AtmosphereData& data) { this->data = data; }
	const AtmosphereData& get() const { return data; }
	// Getters for individual atmospheric properties
	double getDensity() const { return data.dens; }
	double getAltitude() const { return data.alt; }
	double getTemperature() const { return data.temp; }
	double getPressure() const { return data.press; }
	double getWindX() const { return data.wind[0]; }
	double getWindY() const { return data.wind[1]; }
	double getWindZ() const { return data.wind[2]; }
	// Default constructor
	Atmosphere() : data{} {}
private:
	AtmosphereData data;
};