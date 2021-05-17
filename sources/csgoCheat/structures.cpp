#include "structures.h"

// Vec2 class
Vec2 Vec2::operator+(Vec2 d) {
	float tmpX = x + d.x;
	float tmpY = y + d.y;
	return { tmpX , tmpY };
}

Vec2 Vec2::operator-(Vec2 d) {
	float tmpX = x - d.x;
	float tmpY = y - d.y;
	return { tmpX , tmpY };
}

Vec2 Vec2::operator*(float d) {
	float tmpX = x * d;
	float tmpY = y * d;
	return { tmpX , tmpY };
}

void Vec2::Normalize() {
	if (x > 89.0) {
		x -= 360.0;
	}
	if (x < -89.0) {
		x += 360.0;
	}
	if (y > 180.0) {
		y -= 360.0;
	}
	if (y < -180.0) {
		y += 360.0;
	}
}


// Vec3 class
Vec3 Vec3::operator+(Vec3 d) {
	Vec3 rslt;
	float tmpX = x + d.x;
	float tmpY = y + d.y;
	float tmpZ = z + d.z;
	return { tmpX , tmpY , tmpZ };
}

Vec3 Vec3::operator-(Vec3 d) {
	float tmpX = x - d.x;
	float tmpY = y - d.y;
	float tmpZ = z - d.z;
	return { tmpX , tmpY , tmpZ };
}

Vec3 Vec3::operator*(float d) {
	float tmpX = x * d;
	float tmpY = y * d;
	float tmpZ = z * d;
	return { tmpX , tmpY , tmpZ };
}

void Vec3::Normalize() {
	while (y > 180) {
		y -= 360;
	}
	while (y < -180) {
		y += 360;
	}
	if (x > 89) {
		x = 89;
	}
	if (x < -89) {
		x = -89;
	}
}

Vec2 Vec3::CalculateAngles() {
	float pitch, yaw;
	float hypotenuse = sqrt(x * x + y * y + z * z);
	pitch = ((double)atan(z / hypotenuse) * 180.0) / M_PI;
	yaw = ((double)atan(y / x) * 180.0) / M_PI;
	if (x >= 0.0) {
		yaw += 180.0;
	}

	return { pitch, yaw };
}

Item::skinID = 661;