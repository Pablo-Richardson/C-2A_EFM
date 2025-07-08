#pragma once
#include <cmath>
//Custom 3D Vector Struct

struct Vec3 {
    double x, y, z;

    Vec3() : x(0), y(0), z(0) {}
    Vec3(double val) : x(val), y(val), z(val) {}
	Vec3(double x, double y, double z) : x(x), y(y), z(z) {}
	
	// Set
	Vec3& operator=(const Vec3& other)
	{
		x = other.x; y = other.y; z = other.z; return *this;
	}
    // Addition
	Vec3 operator+(const Vec3& other) const {
		return Vec3(x + other.x, y + other.y, z + other.z);
	}
	Vec3& operator+=(const Vec3& other) {
		x += other.x; y += other.y; z += other.z; return *this;
	}
    // Subtraction
	Vec3 operator-(const Vec3& other) const {
		return Vec3(x - other.x, y - other.y, z - other.z);
	}
	Vec3& operator-=(const Vec3& other) {
		x -= other.x; y -= other.y; z -= other.z; return *this;
	}
	// Negative 
	Vec3 operator-() const {
		return Vec3(-x, -y, -z);
	}
    // Scalar Multiplication
	Vec3 operator*(double scalar) const {
		return Vec3(x * scalar, y * scalar, z * scalar);
	}
	Vec3& operator*=(double scalar) {
		x *= scalar; y *= scalar; z *= scalar; return *this;
	}
	// Scalar Division
	Vec3 operator/(double scalar) const {
		if (scalar != 0) {
			return Vec3(x / scalar, y / scalar, z / scalar);
		}
		return Vec3(0, 0, 0);
	}
	Vec3& operator/=(double scalar) {
		if (scalar != 0) {
			x /= scalar; y /= scalar; z /= scalar; return *this;
		}
		else
		{
			return *this;
		}
	}
	// Square root 
	Vec3 sqrtVec() const {
		if (x < 0 || y < 0 || z < 0) {
			return Vec3(0, 0, 0); 
		}
		return Vec3(std::sqrt(x), std::sqrt(y), std::sqrt(z));
	}
	// Magnitude
	double magnitude() const {
		return std::sqrt(x * x + y * y + z * z);
	}
	// Normalize
	Vec3 normalize() const {
		double mag = magnitude();
		if (mag > 0.0) {
			return Vec3(x / mag, y / mag, z / mag);
		}
		return Vec3(0.0, 0.0, 0.0); 
	}
	// Dot product
	double dot(const Vec3& other) const {
		return x * other.x + y * other.y + z * other.z;
	}
	//Check if equal
	bool operator==(const Vec3& other) const {
		return (x == other.x && y == other.y && z == other.z);
	}
	// Check if not equal
	bool operator!=(const Vec3& other) const {
		return !(*this == other);
	}
};