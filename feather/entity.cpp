#include "entity.h"

bool Entity::isActive(){
	return active;
}

bool Entity::getIsClone() {
	return isClone;
}

int Entity::Enable(){
	active = true;
	return 0;
}

int Entity::Disable(){
	active = false;
	return 0;
}

int Entity::setClone() {
	isClone = true;
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

SDL_Texture* Entity::getSprite() {
	return sprite;
}


int Entity::Draw(){
	if(active){
		SDL_Rect dst = { (int)transform.position.x, (int)transform.position.y, (int)transform.scale.x, (int)transform.scale.y };
		SDL_RenderCopyEx(rend, sprite, NULL, &dst, transform.angle, NULL, SDL_FLIP_NONE);
	}
	return 0;
}

int Entity::Destroy(){
	if(active){
		active = false;
		entityTracker.erase(id);
		if (!isClone)
			SDL_DestroyTexture(sprite);
		else
			free(this);
	}
	return 0;
}

int Entity::Create(const char *spritePath, int x, int y, int width, int height, double newAngle){
	Entity::Create(spritePath, Vector(x, y), Vector(width, height), newAngle);
	return 0;
}

int Entity::Create(const char *spritePath, Vector position, Vector scale, double newAngle){
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

int Entity::Create(SDL_Texture* sprite, Transform t) {
	this->sprite = sprite;
	transform = t;
	id = currentID;
	entityTracker[currentID++] = this;
	active = true;
	return 0;
}

Entity* Entity::Clone() {
	return this->Clone(transform);
}

Entity* Entity::Clone(Transform t) {
	Entity* newEntity = new Entity;
	newEntity->Create(this->sprite, t);
	newEntity->setClone();
	return newEntity;
}

bool Entity::Collided(Entity e){
	if(active == false){
		return false;
	}
	else if(!e.isActive()){
		return false;
	}

	SDL_Rect dst1 = { (int)transform.position.x, (int)transform.position.y, (int)transform.scale.x, (int)transform.scale.y };
	SDL_Rect dst2 = { (int)e.transform.position.x, (int)e.transform.position.y, (int)e.transform.scale.x, (int)e.transform.scale.y };
	return SDL_HasIntersection(&dst1, &dst2);
}

int Entity::changeTransparency(Uint8 translucensy){
	SDL_SetTextureAlphaMod(sprite, translucensy);
	return 0;
}
