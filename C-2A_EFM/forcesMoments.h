#pragma once
#include "Vec3.h"

#ifdef BUILDING_MY_DLL
#define MY_API __declspec(dllexport)
#else
#define MY_API __declspec(dllimport)
#endif

// This struct is my custom struct allowing for forces and moments to be added up
MY_API struct ForcesMoments {
    Vec3 force;   // body axis
    Vec3 moment;  // body axis

    // Addition operator for ForcesMoments
    ForcesMoments operator+(const ForcesMoments& other) const;
    // Addition assignment operator for ForcesMoments
    ForcesMoments& operator+=(const ForcesMoments& other);
    // Default constructor initializes forces and moments to zero
    ForcesMoments();
    // Constructor to initialize forces and moments with given values
    ForcesMoments(const Vec3 force_s, const Vec3 moment_s);
};

// Declaration only!
MY_API ForcesMoments sumAllForcesMoments(ForcesMoments lift, ForcesMoments drag, ForcesMoments thrust);
