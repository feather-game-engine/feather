#include "feather/systems/componentsystem.h"

namespace fl {

ComponentSystem::ComponentSystem(fl::EntityManager* entityManager)
	: m_entities(entityManager)
{
	
}

void ComponentSystem::update(float deltaTime) {

}

void ComponentSystem::postUpdate(float deltaTime) {
	
}

} // namespace fl