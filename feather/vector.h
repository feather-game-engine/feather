#ifndef VECTOR_H
#define VECTOR_H
#include "core.h"

class Vector{
	public:
		float x;
		float y;
	
	float Magnitude();
	Vector Normalize();

	int Reset();

	Vector operator +(const Vector vec);
	Vector operator -(const Vector vec);
	int operator +=(const Vector vec);
	int operator -=(const Vector vec);
};

#endif
