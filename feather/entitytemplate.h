//This is the beggining of the instancing system, which will allow you to dynamically make entities from "entity templates"
//It is still a WIP

#ifndef ENTITYTEMPLATE_H
#define ENTITYTEMPLATE_H
#include "core.h"

class EntityTemplate{
	private:
		SDL_Texture *sprite;
	
	EntityTemplate(const char *spritePath);
};

#endif
