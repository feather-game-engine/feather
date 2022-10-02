#ifndef VECTOR_H
#define VECTOR_H
#include "core.h"

class Vector{
	public:
		float x;
		float y;
	
		Vector(float x = 0, float y = 0);

		float Magnitude();
		Vector Normalize();

		int Reset();

		Vector operator +(const Vector vec);
		Vector operator +(const float val);

		Vector operator -(const Vector vec);
		Vector operator -(const float val);

		Vector operator *(const Vector vec);
		Vector operator *(const float val);

		Vector operator /(const Vector vec);
		Vector operator /(const float val);

		int operator +=(const Vector vec);
		int operator +=(const float val);

		int operator -=(const Vector vec);
		int operator -=(const float val);

		int operator *=(const Vector vec);
		int operator *=(const float val);

		int operator /=(const Vector vec);
		int operator /=(const float val);
};

#endif
