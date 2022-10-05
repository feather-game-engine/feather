#ifndef ENTITY_H
#define ENTITY_H
#include "core.h"
#include "transform.h"
#include <unordered_map>

class Entity {
	private:
		bool active;
		SDL_Texture *sprite;
	public:
		Transform transform;
		int id;
		double angle;

		bool isActive();

		int Enable();
		int Disable();

		int swapSprite(const char *spritePath);

		int Draw();
		int Destroy();
		virtual int Create(const char *spritePath, int x, int y, int width, int height);
		virtual int Create(const char *spritePath, Vector position, Vector scale);

		bool Collided(Entity e);

		int changeTransparency(Uint8 translucensy);
};

extern std::unordered_map<int, Entity*> entityTracker;

#endif
