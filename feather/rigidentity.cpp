#include "rigidentity.h"
#include <math.h>


int RigidEntity::Update(float deltaTime) {
	float time = deltaTime;

	acceleration.x += (force.x / mass) * time ;
	acceleration.y += ((force.y - gravity) / mass) * time;
	force.x = 0;
	force.y = 0;

	velocity += acceleration * time;	
	transform.position += velocity * time;
	return 0;
}


int RigidEntity::addForce(Vector forceVec) {
	force.x += forceVec.x;
	force.y += forceVec.y;
	return 0;
}

int RigidEntity::addForceX(float xForce) {
	force.x += xForce;
	return 0;
}

int RigidEntity::addForceY(float yForce) {
	force.y += yForce;
	return 0;
}
