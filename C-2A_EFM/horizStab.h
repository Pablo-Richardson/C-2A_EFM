#pragma once
#include "part.h"
#include <vector>
class VertStab : Part
{
public:

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

/*
	What do we need to do here????

	Function - Get Cy and Cx by AoA in radians (round to value which coresponds to position in array)
	Calculate lift and drag (take functions from wing.h and wing.cpp)
	Calculate moment - find force and see how that effects - should round out to a neutral roll with nothing on
	Anything else?? I dont really think so /: - Maybe later I can add buffetting due to reaching stall (airflow seperation) but not now
*/