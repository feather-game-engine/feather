#ifndef ENTITY_H
#define ENTITY_H
#include "core.h"
#include "transform.h"
#include <unordered_map>

class Entity {
	private:
		bool active;
		bool isClone = false;
	protected:
		SDL_Texture *sprite;
	public:
		Transform transform;
		int id;

		bool isActive();
		bool getIsClone();

		int setClone();
		int Enable();
		int Disable();

		int swapSprite(const char *spritePath);
		SDL_Texture* getSprite();

		int Draw();
		int Destroy();
		virtual int Create(const char *spritePath, int x, int y, int width, int height, double newAngle = 0.0);
		virtual int Create(const char *spritePath, Vector position, Vector scale, double newAngle = 0.0);
		virtual int Create(SDL_Texture* sprite, Transform t);
		virtual Entity* Clone();
		virtual Entity* Clone(Transform t);

		bool Collided(Entity e);

		int changeTransparency(Uint8 translucensy);
};

extern std::unordered_map<int, Entity*> entityTracker;

#endif
