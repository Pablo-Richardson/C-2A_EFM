#pragma once
#include "constants.h"
#include "Vec3.h"
// Keeps track of atmospheric conditions and provides them to the flight model - Recieves data from DCS
// Replace array with vector!

class Atmosphere
{
public:
	// Empty Constructor
	Atmosphere() : wind{0, 0, 0}, density(1.225), temperature(288.15), pressure(101325), altitude(0) {}
	// Full Constructor
	Atmosphere(const Vec3& wind_s, double density_s, double temperature_s, double pressure_s, double altitude_s)
		: wind(wind_s), density(density_s), temperature(temperature_s), pressure(pressure_s), altitude(altitude_s) {}
	// Update atmospheric conditions - DCS

private:
	Vec3 wind; // Wind vector in m/s
	double density; // Density in kg/m^3
	double temperature; // Temperature in Kelvin
	double pressure; // Pressure in Pascals
	double altitude; // Altitude in meters

};



/*
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
*/