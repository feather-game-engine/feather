#include "transform.h"

int Transform::Translate(int x, int y){
	position.x += x;
	position.y += y;
	return 0;
}

int Transform::Translate(Vector direction){
	position += direction;
	return 0;
}

int Transform::Scale(int x, int y){
	scale.x *= x;
	scale.y *= y;
	return 0;
}

int Transform::Scale(Vector magnitude){
	scale *= magnitude;
	return 0;
}
