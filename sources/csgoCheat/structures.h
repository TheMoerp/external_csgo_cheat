#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

class Vec2 {
public:
	float x, y;

	Vec2 operator+(Vec2 d);
	Vec2 operator-(Vec2 d);
	Vec2 operator*(float d);

	void Normalize();
};


class Vec3 {
public:
	float x, y, z;

	Vec3 operator+(Vec3 d);
	Vec3 operator-(Vec3 d);
	Vec3 operator*(float d);

	void Normalize();
	Vec2 CalculateAngles();
};


class Item {
public:
	//Item() :skinID(0),seed(0),rstTime(r) {}
	int skinID;
	int seed;
	
	int rstTime;
};