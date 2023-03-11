#include "feather/systems/componentsystem.h"

namespace fl {

ComponentSystem::ComponentSystem(fl::EntityManager* entityManager)
	: m_entities(entityManager)
{
	
}

void ComponentSystem::update(float) {

}

void ComponentSystem::postUpdate(float) {
	
}

void ComponentSystem::remove(unsigned entityID) {
	m_entityIDs.extract(entityID);
}

} // namespace fl