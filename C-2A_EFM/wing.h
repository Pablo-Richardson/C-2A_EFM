#pragma once
#include "part.h"
#include <vector>
class Wing: Part {
public:
	// Setters (set CyA by AOA)
	void setCya();
	void setCxa();
	void setLift(double lift);
	void setDrag(double drag);

	double getLift(double dens, double inAirSpeed);
	double getDrag(double dens, double inAirSpeed);
	double getAreaLift();
	double getAreaDrag();
private:
	std::vector<double> CyByAoA = {}; // Give Cy by AoA (in radians)
	std::vector<double> CxByAoA = {}; //Give Cx by AoA ();
	double static constexpr areaLift = 100; // Set this to something in m^2
	double static constexpr areaDrag = 1; // Set this to something in m^2
	double static constexpr pos_z = 1; // COL position relative to the COM (Used for moment calculations) in m^2
	double static constexpr pos_x = 1;
	double lift;
	double drag;
	double momentRoll; // Total moment caused by this wing to the right
	double momentPitch; // Total moment caused by this wing to pitch up
};