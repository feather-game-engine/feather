#include "entity.h"

bool Entity::isActive(){
	return active;
}

int Entity::Enable(){
	active = true;
	return 0;
}

int Entity::Disable(){
	active = false;
	return 0;
}

int Entity::swapSprite(const char *spritePath){
	SDL_Surface *image = IMG_Load(spritePath);
	if(image == NULL){
		std::cout << "Image with path " << spritePath << " has not been loaded." << std::endl;
		return -1;
	}
	SDL_DestroyTexture(sprite);
	sprite = SDL_CreateTextureFromSurface(rend, image);
	SDL_FreeSurface(image);
	return 0;
}

int Entity::Draw(){
	if(active){
		SDL_Rect dst = { transform.position.x, transform.position.y, transform.scale.x, transform.scale.y };
		SDL_RenderCopyEx(rend, sprite, NULL, &dst, transform.angle, NULL, SDL_FLIP_NONE);
	}
	return 0;
}

int Entity::Destroy(){
	if(active){
		SDL_DestroyTexture(sprite);
		active = false;
		entityTracker.erase(id);
	}
	return 0;
}

int Entity::Create(const char *spritePath, int x, int y, int width, int height, double newAngle = 0.0){
	SDL_Surface *image = IMG_Load(spritePath);
	if(image == NULL){
		std::cout << "Image with path " << spritePath << " has not been loaded." << std::endl;
		return -1;
	}
	sprite = SDL_CreateTextureFromSurface(rend, image);
	SDL_FreeSurface(image);
	transform.position.x = x;
	transform.position.y = y;
	transform.scale.x = width;
	transform.scale.y = height;
	transform.angle = newAngle;
	active = true;
	id = currentID;
	entityTracker[id] = this;
	currentID += 1;
	return 0;
}

int Entity::Create(const char *spritePath, Vector position, Vector scale, double newAngle = 0.0){
	SDL_Surface *image = IMG_Load(spritePath);
	if(image == NULL){
		std::cout << "Image with path " << spritePath << " has not been loaded." << std::endl;
		return -1;
	}
	sprite = SDL_CreateTextureFromSurface(rend, image);
	SDL_FreeSurface(image);
	transform.position.x = position.x;
	transform.position.y = position.y;
	transform.scale.x = scale.x;
	transform.scale.y = scale.y;
	transform.angle = newAngle;
	active = true;
	id = currentID;
	entityTracker[id] = this;
	currentID += 1;
	return 0;
}

bool Entity::Collided(Entity e){
	if(active == false){
		return false;
	}
	else if(!e.isActive()){
		return false;
	}

	SDL_Rect dst1 = { transform.position.x, transform.position.y, transform.scale.x, transform.scale.y };
	SDL_Rect dst2 = { e.transform.position.x, e.transform.position.y, e.transform.scale.x, e.transform.scale.y };
	return SDL_HasIntersection(&dst1, &dst2);
}

int Entity::changeTransparency(Uint8 translucensy){
	SDL_SetTextureAlphaMod(sprite, translucensy);
	return 0;
}
