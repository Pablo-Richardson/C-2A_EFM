#pragma once
#include <vector>
// I wont update these, and just assume a centered COM, but you can use a file like this to update the COM for moment calculations
// You can also use it to update the mass of the aircraft based on fuel - realism (make sure to account for fuel mass when the aircraft is initialised!)
struct massState {
	double mass, COM[3];
};

class MassProperties {
public:
	void update(const massState& mass) { data = mass; }
	const massState& get() const { return data; }
	void updateMass(const double mass) { data.mass = mass; }
	const double& getMass() const { return data.mass; }
private:
	massState data = { 25000, {0.0, 0.0, 0.0} }; // Default mass and COM
};