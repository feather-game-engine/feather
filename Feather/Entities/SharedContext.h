#pragma once

#include <Feather/ResourceManager.h>
#include <Feather/Systems/InputManager.h>
#include <Feather/Windows/Window.h>

namespace fl {

class EntityManager;

struct SharedContext {
	fl::EntityManager* 		entities;
	fl::ResourceManager*	resources;
	fl::Window*				window;
	fl::InputManager*		inputs;
}; // struct SharedContext

} // namespace fl