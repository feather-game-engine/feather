#ifndef RIGIDENTITY_H
#define RIGIDENTITY_H
#include "core.h"
#include "transform.h"
#include "entity.h"
#include <unordered_map>

class RigidEntity : public Entity {
	private:
		SDL_Texture *sprite;
	public:
		bool rigid = true;

		RigidEntity* Clone();
		RigidEntity* Clone(Transform t);
		int Draw();

		Vector velocity;
		Vector acceleration;

		SDL_Rect hitbox;
		int setHitbox(int x = 0, int y = 0, int w = 1, int h = 1);

		float gravity = -9.8;
		float mass = 1;
		Vector force = Vector(0, 0);

		int addForce(Vector force);
		int addForceX(float x);
		int addForceY(float Y);

		int testMove(Vector delta);

		int Update(float deltaTime);
};

extern std::unordered_map<int, Entity*> entityTracker;

#endif
