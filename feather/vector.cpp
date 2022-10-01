#include "vector.h"
#include <math.h>

float Vector::Magnitude(){
	return sqrt(pow(x, 2) + pow(y, 2));
}

Vector Vector::Normalize(){
	float magnitude = Magnitude();
	Vector vectorNorm;
	if(magnitude > 0) {
		vectorNorm.x = pow(x / magnitude, 2);
		vectorNorm.y = pow(y / magnitude, 2);
	} else {
		vectorNorm.x = 0;
		vectorNorm.y = 0;
	}

	return vectorNorm;
}

int Vector::Reset(){
	x = 0;
	y = 0;
	return 0;
}

Vector Vector::operator +(const Vector vec){
	Vector res;
	res.x = x + vec.x;
	res.y = y + vec.y;
	return res;
}

Vector Vector::operator -(const Vector vec){
	Vector res;
	res.x = x - vec.x;
	res.y = y - vec.y;
	return res;
}

int Vector::operator +=(const Vector vec){
	x += vec.x;
	y += vec.y;
	return 0;
}

int Vector::operator -=(const Vector vec){
	x -= vec.x;
	y -= vec.y;
	return 0;
}
