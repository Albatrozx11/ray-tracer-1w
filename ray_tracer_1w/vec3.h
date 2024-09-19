#pragma once

#include <iostream>
#include <cmath>

class vec3 {	
public:
	double e[3];

	vec3() : e{ 0.0,0.0,0.0 } {};

	vec3(double x, double y, double z) : e{ x,y,z } {}
	
	double x() const { return e[0]; }
	double y() const { return e[1]; }
	double z() const { return e[2]; }

	vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
	double operator[](int i) const { return e[i]; }
	double& operator[](int i) { return e[i]; }
	
	vec3 operator+=(const vec3 & v) {
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];
		return *this;
	}

	vec3 operator*=(double t) {
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;
		return *this;
	}

	vec3 operator/=(double t) {
		return *this *= 1/t;
	}

	double length() const {
		return std::sqrt(length_squared());
	}

	double length_squared() const {
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

};

//alias for a point in 3D space

using point3 = vec3;


//vector utility functions

inline std::ostream& operator<<(std::ostream stream, const vec3& other) {
	return std::cout << other.e[0] << "," << other.e[1] << "," << other.e[2] << "\n";
}

inline vec3 operator+(const vec3& v, const vec3& u) {
	return vec3(v.e[0] + u.e[0], v.e[1] + u.e[1], v.e[2] + u.e[2]);
}

inline vec3 operator-(const vec3& v, const vec3& u) {
	return vec3(v.e[0] - u.e[0], v.e[1] - u.e[1], v.e[2] - u.e[2]);
}

inline vec3 operator*(const vec3& v, const vec3& u) {
	return vec3(v.e[0] * u.e[0], v.e[1] * u.e[1], v.e[2] * u.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
	return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}

inline vec3 operator*(double t, const vec3& v) {
	return v * t;
}

inline vec3 operator/(const vec3& v, double t) {
	return v * (1/t);
}

inline double dot(const vec3& v, const vec3& u) {
	return (v.e[0] * u.e[0] + v.e[1] * u.e[1] + v.e[2] * u.e[2]);
}

inline vec3 cross(const vec3& v, const vec3& u) {
	return vec3(v.e[1] * u.e[2] - v.e[2] * u.e[1] ,
				v.e[2] * u.e[0] - v.e[0] * u.e[2] ,
				v.e[0] * u.e[1] - v.e[1] * u.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
	return v/v.length();
}