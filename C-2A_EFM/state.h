#pragma once
#include "forcesMoments.h"
#include "quaternions.h"
#include <vector>
// Store state of aicraft

class State {
public:
    // Empty Constructor
	State() : pos{ 0, 0, 0 }, vel{ 0, 0, 0 }, forceMoment{}, quat{ 1, 0, 0, 0 }, alpha(0), beta(0), TAS(0), GS(0) {}
	// Copy Constructor
	State(Vec3 pos_s, Vec3 vel_s, ForcesMoments forceMoment_s, Quaternion quat_s, double alpha_s, double beta_s, double TAS_s, double GS_s)
		: pos(pos_s), vel(vel_s), forceMoment(forceMoment_s), quat(quat_s), alpha(alpha_s), beta(beta_s), TAS(TAS_s), GS(GS_s) {}
    // Getters
	Vec3 getPos() const { return pos; }
	Vec3 getVel() const { return vel; }
	ForcesMoments getForceMoment() const { return forceMoment; }
	Quaternion getQuat() const { return quat; }
	double getAlpha() const { return alpha; }
	double getBeta() const { return beta; }
	double getTAS() const { return TAS; }
	double getGS() const { return GS; }
    //Individual setters
	void setPos(const Vec3& pos_s) { pos = pos_s; }
	void setVel(const Vec3& vel_s) { vel = vel_s; }
	void setForceMoment(const ForcesMoments& forceMoment_s) { forceMoment = forceMoment_s; }
	void setQuat(const Quaternion& quat_s) { quat = quat_s; }
	void setAlpha(double alpha_s) { alpha = alpha_s; }
	void setBeta(double beta_s) { beta = beta_s; }
	void setTAS(double TAS_s) { TAS = TAS_s; }
	void setGS(double GS_s) { GS = GS_s; }
	// Update state
	void updateState(const Vec3& pos_s, const Vec3& vel_s, const ForcesMoments& forceMoment_s, const Quaternion& quat_s, double alpha_s, double beta_s, double TAS_s, double GS_s)
	{
		pos = pos_s;
		vel = vel_s;
		forceMoment = forceMoment_s;
		quat = quat_s;
		alpha = alpha_s;
		beta = beta_s;
		TAS = TAS_s;
		GS = GS_s;
	}

private:
    Vec3 pos, vel;
    ForcesMoments forceMoment;
    Quaternion quat;
    double alpha, beta, TAS, GS;
};