#ifndef RIGIDENTITY_H
#define RIGIDENTITY_H
#include "core.h"
#include "transform.h"
#include "entity.h"

class RigidEntity : public Entity {
	private:
		bool active;
		SDL_Texture *sprite;
	public:
		bool rigid = true;

		Vector velocity;
		Vector acceleration;

		float gravity = -9.8;
		float mass = 1;
		Vector force = Vector(0, 0);

		int addForce(Vector force);
		int addForceX(float x);
		int addForceY(float Y);

		int Update(float deltaTime);
};

extern Entity *entityTracker[2056];

#endif
