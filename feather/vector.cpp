#include "vector.h"
#include <math.h>

Vector::Vector(float xVec, float yVec) {
	x = xVec;
	y = yVec;
}

float Vector::Magnitude(){
	return sqrt(pow(x, 2) + pow(y, 2));
}

Vector Vector::Normalize(){
	float magnitude = Magnitude();
	Vector vectorNorm;
	if(magnitude > 0){
		vectorNorm.x = pow(x / magnitude, 2);
		vectorNorm.y = pow(y / magnitude, 2);
	} 
	else{
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
	return Vector(x + vec.x, y + vec.y);
}

Vector Vector::operator +(const float val){
	return Vector(x + val, y + val);
}



Vector Vector::operator -(const Vector vec){
	return Vector(x - vec.x, y - vec.y);
}

Vector Vector::operator -(const float val){
	return Vector(x - val, y - val);
}



Vector Vector::operator *(const Vector vec){
	return Vector(x * vec.x, y * vec.y);
}

Vector Vector::operator *(const float val){
	return Vector(x * val, y * val);
}



Vector Vector::operator /(const Vector vec){
	return Vector(x / vec.x, y / vec.y);
}

Vector Vector::operator /(const float val){
	return Vector(x / val, y / val);
}



int Vector::operator +=(const Vector vec){
	x += vec.x;
	y += vec.y;
	return 0;
}

int Vector::operator +=(const float val){
	x += val;
	y += val;
	return 0;
}


int Vector::operator -=(const Vector vec){
	x -= vec.x;
	y -= vec.y;
	return 0;
}

int Vector::operator -=(const float val){
	x -= val;
	y -= val;
	return 0;
}



int Vector::operator *=(const Vector vec){
	x *= vec.x;
	y *= vec.y;
	return 0;
}

int Vector::operator *=(const float val){
	x *= val;
	y *= val;
	return 0;
}


int Vector::operator /=(const Vector vec){
	x /= vec.x;
	y /= vec.y;
	return 0;
}

int Vector::operator /=(const float val){
	x /= val;
	y /= val;
	return 0;
}
