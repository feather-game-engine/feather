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
		SDL_Rect dst = { transform.x, transform.y, transform.width, transform.height };
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
	transform.x = x;
	transform.y = y;
	transform.width = width;
	transform.height = height;
	active = true;
	return 0;
}

bool Entity::Collided(Entity e){
	SDL_Rect dst1 = { transform.x, transform.y, transform.width, transform.height };
	SDL_Rect dst2 = { e.transform.x, e.transform.y, e.transform.width, e.transform.height };
	return SDL_HasIntersection(&dst1, &dst2);
}
