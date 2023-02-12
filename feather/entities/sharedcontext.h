#pragma once

#include "feather/systems/entitymanager.h"
#include "feather/resourcemanager.h"
#include "feather/window.h"

namespace fl {

struct SharedContext {
	fl::EntityManager* 		entities;
	fl::ResourceManager*	resources;
	fl::Window*				window;

	SharedContext(fl::EntityManager* entityManager, fl::Window* gameWindow);
}; // struct SharedContext

SharedContext::SharedContext(fl::EntityManager* entityManager, fl::ResourceManager* resourceManager, fl::Window* gameWindow) {
	this->entities = entityManager;
	this->resources = ResourceManager;
	this->window = gameWindow;
}


} // namespace fl