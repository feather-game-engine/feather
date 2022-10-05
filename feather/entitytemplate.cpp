#include "entitytemplate.h"

EntityTemplate::EntityTemplate(const char *spritePath){
	SDL_Surface *image = IMG_Load(spritePath);
	if(image == NULL){
		std::cout << "Image with path " << spritePath << " has not been loaded." << std::endl;
	}
	sprite = SDL_CreateTextureFromSurface(rend, image);
	SDL_FreeSurface(image);
	//Do more things.
}
