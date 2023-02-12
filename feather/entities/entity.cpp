#include "feather/entities/entity.h"

unsigned fl::Entity::count = 0u;

namespace fl {

Entity::Entity(fl::SharedContext* context)
	: ID(fl::Entity::count++),
	CONTEXT(context)
{

}

void Entity::awake() {
	for (const auto& component: m_components) {
		component->awake();
	}
}

void Entity::draw() {
	
}

bool Entity::isStatic() const {
	return m_static;
}

void Entity::setStatic(bool isStatic) {
	m_static = isStatic;
}

bool Entity::isQueuedForRemoval() const {
	return m_queuedForRemoval;
}

void Entity::queueForRemoval(bool remove) {
	m_queuedForRemoval = remove;
}

} // namespace fl