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

	vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); 
	double operator[](int i) const { return e[i]; }
	double& operator[](int i) { return e[i]; }

	vec3 operator+=(const vec3& v) {
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
		return *this *= t;
	}

	double length(const vec3& v) {
		return std::sqrt(length_squared());
	}

	double length_squared() const {
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}

};

	std::ostream& operator<<(std::ostream stream, const vec3& other) {

	}