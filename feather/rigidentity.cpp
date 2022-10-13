#include "rigidentity.h"
#include <math.h>

//using namespace std;

int RigidEntity::Update(float deltaTime) {
	float time = deltaTime;

	acceleration.x = (force.x / mass);
	acceleration.y = ((force.y - gravity * mass) / mass);
	force.x = 0;
	force.y = 0;

	velocity += acceleration * time * 200;	
	Vector delta = velocity * time;

	testMove(delta);

	return 0;
}

RigidEntity* RigidEntity::Clone() {
	Transform t = transform;
	return RigidEntity::Clone(t);
}

RigidEntity* RigidEntity::Clone(Transform t) {
	RigidEntity *cloneEntity = new RigidEntity;
	cloneEntity->Create(this->getSprite(), t);
	cloneEntity->setHitbox(this->hitbox.x, this->hitbox.y, this->hitbox.w, this->hitbox.h);
	cloneEntity->setClone();
	return cloneEntity;
}

int RigidEntity::setHitbox(int x, int y, int w, int h) {
	hitbox.x = x;
	hitbox.y = y;
	hitbox.w = w;
	hitbox.h = h;
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

int RigidEntity::testMove(Vector delta) {
	for (auto element : entityTracker) {
		if (element.first == Entity::id) continue;
		if (dynamic_cast<RigidEntity*>(element.second)) {
			RigidEntity* rigidEntity = dynamic_cast<RigidEntity*>(element.second);
			SDL_Rect dst1 = { (int)(transform.position.x + hitbox.x + delta.x), (int)(transform.position.y + hitbox.y + delta.y), hitbox.w, hitbox.h };
			SDL_Rect dst2 = { (int)rigidEntity->transform.position.x + rigidEntity->hitbox.x, (int)rigidEntity->transform.position.y + rigidEntity->hitbox.y, rigidEntity->hitbox.w, rigidEntity->hitbox.h };
			if (SDL_HasIntersection(&dst1, &dst2)) {
				velocity = (0, 0);
				return 1;
			}
		}
	}
	transform.position += delta;
	return 0;
}