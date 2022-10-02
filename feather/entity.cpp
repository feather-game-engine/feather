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
		SDL_RenderCopy(rend, sprite, NULL, &dst);
	}
	return 0;
}

int Entity::Destroy(){
	if(active){
		SDL_DestroyTexture(sprite);
		active = false;
	}
	return 0;
}

int Entity::Create(const char *spritePath, int x, int y, int width, int height){
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
	active = true;
	id = currentID;
	entityTracker[id] = this;
	currentID += 1;
	return 0;
}

bool Entity::Collided(Entity e){
	SDL_Rect dst1 = { transform.position.x, transform.position.y, transform.scale.x, transform.scale.y };
	SDL_Rect dst2 = { e.transform.position.x, e.transform.position.y, e.transform.scale.x, e.transform.scale.y };
	return SDL_HasIntersection(&dst1, &dst2);
}

int Entity::changeTransparency(Uint8 translucensy){
	SDL_SetTextureAlphaMod(sprite, translucensy);
	return 0;
}
