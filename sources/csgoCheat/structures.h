#pragma once

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
	float x, y, z ;

	Vec3 operator+(Vec3 d);
	Vec3 operator-(Vec3 d);
	Vec3 operator*(float d);

	void Normalize();
	Vec2 CalculateAngles();
};


class Item {
public:
	int skinID;
	int seed;
	
	float rstTime;
};