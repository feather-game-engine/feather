#include "rigidentity.h"
#include <math.h>

using namespace std;

int RigidEntity::Update(float deltaTime) {
	float time = deltaTime;

	acceleration.x = (force.x / mass);
	acceleration.y = ((force.y - gravity * mass) / mass);
	force.x = 0;
	force.y = 0;

	velocity += acceleration * time * 200;	
	transform.position += velocity * time;
	return 0;
}

RigidEntity RigidEntity::clone() {
	Transform t = transform;
	return RigidEntity::clone(t);
}

RigidEntity RigidEntity::clone(Transform t) {
	RigidEntity cloneEntity;
	cloneEntity.transform = t;
	cloneEntity.Entity::sprite = getSprite();
	cloneEntity.Enable();
	entityTracker[currentID++] = &(Entity)cloneEntity;
	return cloneEntity;
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
