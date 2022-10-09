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

	//Collision
	for (auto element : entityTracker) {
		if (dynamic_cast<RigidEntity*>(element.second)) {
			RigidEntity* rigidEntity = dynamic_cast<RigidEntity*>(element.second);
			SDL_Rect dst1 = { transform.position.x, transform.position.y, transform.scale.x, transform.scale.y };
			SDL_Rect dst2 = { rigidEntity->transform.position.x, rigidEntity->transform.position.y, rigidEntity->transform.scale.x, rigidEntity->transform.scale.y };
			if (SDL_HasIntersection(&dst1, &dst2)) {
				Vector move(dst1.x - dst2.x, dst1.y - dst2.y);
				transform.position += move * 0.2;
			}
		}
	}

	return 0;
}

RigidEntity* RigidEntity::Clone() {
	Transform t = transform;
	return RigidEntity::Clone(t);
}

RigidEntity* RigidEntity::Clone(Transform t) {
	RigidEntity *cloneEntity = new RigidEntity;
	cloneEntity->Create(this->getSprite(), t);
	cloneEntity->setClone();
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
