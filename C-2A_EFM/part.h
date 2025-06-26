#pragma once
class  Part
{
public:
	// Getters
	double const getHealth();
	double const getCx0();
	double const getCy0();
	double const getCxa();
	double const getCya();
	double const getCymax();
	double const getID();

	// Setters
	void removeHealth(double damage);
	void setHealth(double health);
private:
	double health;
	double static constexpr id = 0; //We set this to be whatever it needs to be per part, use enum for this
	double Cx0;
	double Cy0;
	double Cya;
	double Cxa;
	double Cymax;
};
/*
	Cx = Drag coefficient
	Cy = Lift coefficient
	Cya & Cxa = Lift & Drag coefficients by AoA (store as array)
*/