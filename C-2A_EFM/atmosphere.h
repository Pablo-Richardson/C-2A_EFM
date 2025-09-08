#pragma once
#include "constants.h"
#include "Vec3.h"

// Keeps track of atmospheric conditions and provides them to the flight model - Receives data from DCS
class Atmosphere
{
public:
    Atmosphere();
    Atmosphere(const Vec3& wind_s, double density_s, double temperature_s, double pressure_s, double altitude_s);

    void update(const Vec3& wind_s, double density_s, double temperature_s, double pressure_s, double altitude_s);

    Vec3 getWind() const;
    double getDensity() const;
    double getTemperature() const;
    double getPressure() const;
    double getAltitude() const;

    double getWindX() const;
    double getWindY() const;
    double getWindZ() const;

private:
    Vec3 wind; // Wind vector in m/s
    double density; // Density in kg/m^3
    double temperature; // Temperature in Kelvin
    double pressure; // Pressure in Pascals
    double altitude; // Altitude in meters
};
