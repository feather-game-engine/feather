#pragma once

#include <feather/resourcemanager.h>
#include <feather/windows/window.h>

namespace fl {

class EntityManager;

struct SharedContext {
	fl::EntityManager* 		entities;
	fl::ResourceManager*	resources;
	fl::Window*				window;

}; // struct SharedContext

} // namespace fl