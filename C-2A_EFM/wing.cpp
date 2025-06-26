#include "wing.h"
#include "cod.h"
#include "part.h"

// void setCya based on radians (depends on how many data points I get in the array)
// void setCxa based on radians (depends on how many data points I get in the array)

double Wing::getAreaDrag()
{
	return this->areaDrag;
}

double Wing::getAreaLift()
{
	return this->areaLift;
}

void Wing::setLift(double lift)
{
	this->lift = lift;
}

void Wing::setDrag(double drag)
{
	this->drag = drag;
}

// Find drag per wing
double Wing::getDrag(double dens, double inAirSpeed)
{
	return (Part::getCxa() * 0.5 * dens * inAirSpeed * inAirSpeed * Wing::getAreaDrag());
}

// Find lift per wing
double Wing::getLift(double dens, double inAirSpeed)
{
	return (Part::getCya() * 0.5 * dens * inAirSpeed * inAirSpeed * Wing::getAreaLift());
}


/*
	Maybe we should account for health when looking at lift and drag
	Does area change when pulling AoA or is that already accounted for in Cya and Cxa im not really sure to be honest -- Find out ASAP
*/