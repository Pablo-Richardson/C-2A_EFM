#pragma once
#include "constants.h"
#include "Vec3.h"
// Keeps track of atmospheric conditions and provides them to the flight model - Recieves data from DCS
// Done! :D

class Atmosphere
{
public:
	// Empty Constructor
	Atmosphere() : wind{0, 0, 0}, density(1.225), temperature(288.15), pressure(101325), altitude(0) {}
	// Full Constructor
	Atmosphere(const Vec3& wind_s, double density_s, double temperature_s, double pressure_s, double altitude_s)
		: wind(wind_s), density(density_s), temperature(temperature_s), pressure(pressure_s), altitude(altitude_s) {}
	// Update atmospheric conditions - DCS
	void update(const Vec3& wind_s, double density_s, double temperature_s, double pressure_s, double altitude_s) {
		wind = wind_s;
		density = density_s;
		temperature = temperature_s;
		pressure = pressure_s;
		altitude = altitude_s;
	}
	// Getters for individual atmospheric properties
	Vec3 getWind() const { return wind; }
	double getDensity() const { return density; }
	double getTemperature() const { return temperature; }
	double getPressure() const { return pressure; }
	double getAltitude() const { return altitude; }
	// Get wind componenets
	double getWindX() const { return wind.x; }
	double getWindY() const { return wind.y; }
	double getWindZ() const { return wind.z; }
private:
	Vec3 wind; // Wind vector in m/s
	double density; // Density in kg/m^3
	double temperature; // Temperature in Kelvin
	double pressure; // Pressure in Pascals
	double altitude; // Altitude in meters
};