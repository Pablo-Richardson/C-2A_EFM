#pragma once
// I wont update these, and just assume a centered COM, but you can use a file like this to update the COM for moment calculations

struct massState {
	double mass, COM[3];
};

class MassProperties {
public:
	void update(const massState& mass) { data = mass; }
	const massState& get() const { return data; }
private:
	massState data = { 25000, {0.0, 0.0, 0.0} }; // Default mass and COM
};