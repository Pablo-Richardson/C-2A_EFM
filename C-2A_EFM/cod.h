#pragma once
//Build upon this
//Need objects to make up aircraft - Gear, wings (flaps integrated), elevators, ailerons, rudders, engines, body
class Cod
{
public:

private:
	double						wingSpan;
	double						wingArea;
	double						meanChord;
	double						cogPct = 0.3; // Center of Gravity as a percentage of the mean chord
	double static constexpr		pi = 3.14159;
	double static constexpr		radToDeg = 180 / pi;
	double						alt = 0.0; // Altitude in meters
	double						alpha = 0.0; // Angle of attack in degrees
	double						beta = 0.0; // Sideslip angle in degrees
	double						mach = 0.0; // Mach number
	double						airDensity = 1.225; // air density in kg/m^3;
	double						temp = 288.15; // Temperature in Kelvin
	double						press = 101325.0; // Pressure in Pascals
	double						windVel_x = 0.0; // Wind velocity in x direction
	double						windVel_y = 0.0; // Wind velocity in y direction
	double						windVel_z = 0.0; // Wind velocity in z direction
	double						velIAS_x = 0.0; // Indicated Airspeed in x direction
	double						velIAS_y = 0.0; // Indicated Airspeed in y direction
	double						velIAS_z = 0.0; // Indicated Airspeed in z direction
	double						acc_x = 0.0; // Acceleration in x direction
	double						acc_y = 0.0; // Acceleration in y direction
	double						acc_z = 0.0; // Acceleration in z direction
	double						vel_x = 0.0; // Velocity in x direction
	double						vel_y = 0.0; // Velocity in y direction
	double						vel_z = 0.0; // Velocity in z direction
	double						pos_x = 0.0; // Position in x direction
	double						pos_y = 0.0; // Position in y direction
	double						pos_z = 0.0; // Position in z direction
	double						momInertia_x = 15000.0; // Moment of inertia around the x-axis in kg*m^2
	double						momInertia_y = 80000.0; // Moment of inertia around the x-axis in kg*m^2
	double						momInertia_z = 90000.0; // Moment of inertia around the z-axis in kg*m^2
	double						totalMoment_x = 0.0; // Total moment around x-axis
	double						totalMoment_y = 0.0; // Total moment around y-axis
	double						totalMoment_z = 0.0; // Total moment around z-axis
	double						angAcc_x = 0.0; // Angular acceleration in x direction
	double						angAcc_y = 0.0; // Angular acceleration in y direction
	double						angAcc_z = 0.0; // Angular acceleration in z direction
	double						angVel_x = 0.0; // Angular velocity in x direction
	double						angVel_y = 0.0; // Angular velocity in y direction
	double						angVel_z = 0.0; // Angular velocity in z direction
	double						quaternion_x = 0.0; // Quaternion x component
	double						quaternion_y = 0.0; // Quaternion y component
	double						quaternion_z = 0.0; // Quaternion z component
	double						quaternion_w = 1.0; // Quaternion w component (no rotation)
};