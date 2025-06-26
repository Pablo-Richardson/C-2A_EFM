#pragma once
#include "part.h"

class Engine : Part
{
public:

private:
	int currentRPM;
	double propFeatherAngle;
	double thrust;
	double static constexpr idleRPM = 1000; // This needs to be set correctly - it wont produce crazy ammounts of thrust (HOW DOES THRUST VARY BY RPM WTF????)
};

/*
	One thing to mention is that at slower speeds this can increase lift (bruh) - so that might need to be something to account for later on
	For now we keep it easy and simple -- Nothing crazy yet
*/