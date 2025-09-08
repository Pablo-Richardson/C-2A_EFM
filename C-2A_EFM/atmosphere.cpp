#include "atmosphere.h"

Atmosphere::Atmosphere()
    : wind{ 0, 0, 0 }, density(1.225), temperature(288.15), pressure(101325), altitude(0) {
}

Atmosphere::Atmosphere(const Vec3& wind_s, double density_s, double temperature_s, double pressure_s, double altitude_s)
    : wind(wind_s), density(density_s), temperature(temperature_s), pressure(pressure_s), altitude(altitude_s) {
}

void Atmosphere::update(const Vec3& wind_s, double density_s, double temperature_s, double pressure_s, double altitude_s) {
    wind = wind_s;
    density = density_s;
    temperature = temperature_s;
    pressure = pressure_s;
    altitude = altitude_s;
}

Vec3 Atmosphere::getWind() const { return wind; }
double Atmosphere::getDensity() const { return density; }
double Atmosphere::getTemperature() const { return temperature; }
double Atmosphere::getPressure() const { return pressure; }
double Atmosphere::getAltitude() const { return altitude; }
double Atmosphere::getWindX() const { return wind.x; }
double Atmosphere::getWindY() const { return wind.y; }
double Atmosphere::getWindZ() const { return wind.z; }
