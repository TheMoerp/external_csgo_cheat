#pragma once
#define _USE_MATH_DEFINES
#include <math.h>


// 2D Vector
class Vec2 {
public:
    float x, y;

    Vec2 operator+(Vec2 d);
    Vec2 operator-(Vec2 d);
    Vec2 operator*(float d);

    void Normalize();
};

// 3DVector
class Vec3 {
public:
    float x, y, z;

    Vec3 operator+(Vec3 d);
    Vec3 operator-(Vec3 d);
    Vec3 operator*(float d);

    void Normalize();
    Vec2 CalculateAngles();
};


// Item class (for weapons)
class Item {
public:
    int skinID;
    int seed; // Currently not in use

    // Recovery Time
    int rstTime;
};
