#pragma once

#include <feather/resourcemanager.h>
#include <feather/systems/inputmanager.h>
#include <feather/windows/window.h>

namespace fl {

class EntityManager;

struct SharedContext {
	fl::EntityManager* 		entities;
	fl::ResourceManager*	resources;
	fl::Window*				window;
	fl::InputManager*		inputs;
}; // struct SharedContext

} // namespace fl