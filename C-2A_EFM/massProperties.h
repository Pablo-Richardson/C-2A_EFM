#pragma once
#include "Vec3.h"
/*
I wont update these, and just assume a centered COM, but you can use a file like this to update the COM for moment calculations
You can also use it to update the mass of the aircraft based on fuel - realism 
(make sure to account for fuel mass when the aircraft is initialised!)
*/

class massProperties {
public:
	// Default constructor with default COM and mass
	massProperties() : com{ 0.0, 0.0, 0.0 }, mass(25000.0) {}
	// Constructor to initialize with specific COM and mass
	massProperties(const Vec3& centerOfMass, double massValue) : com(centerOfMass), mass(massValue) {}
	// Update the mass and COM
	void update(const Vec3& centerOfMass, double massValue) { com = centerOfMass; mass = massValue; }
	// Set COM
	void setCOM(const Vec3& centerOfMass) { com = centerOfMass; }
	// Set mass
	void setMass(double massValue) { mass = massValue; }
	// Get COM
	const Vec3& getCOM() const { return com; }
	// Get mass
	const double& getMass() const { return mass; }
private:
	Vec3 com; // Center of Mass in local coordinates
	double mass; // Mass in kg
};












/*
struct massState {
	double mass; // Mass in kg
	Vec3 com; // Center of Mass in local coordinates
};

class MassProperties {
public:
	MassProperties() = default;
	MassProperties(const massState& mass) : data(mass) {}
	void update(const massState& mass) { data = mass; }
	const massState& get() const { return data; }
	void updateMass(const double mass) { data.mass = mass; }
	const double& getMass() const { return data.mass; }
private:
	massState data = { 25000, {0.0, 0.0, 0.0} }; // Default mass and COM
};
*/