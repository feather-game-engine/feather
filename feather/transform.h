#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "core.h"
#include "vector.h"

class Transform{
	public:
		Vector position;
		Vector scale;
		double angle;
	
	int Translate(int x, int y);
	int Translate(Vector direction);

	int Scale(int x, int y);
	int Scale(Vector magnitude);
};
#endif
