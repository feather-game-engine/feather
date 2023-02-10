#include "feather/entities/entity.h"

unsigned fl::Entity::count = 0u;

namespace fl {

Entity::Entity()
	: ID(fl::Entity::count++)
{

}

void Entity::awake() {
	for (const auto& component: m_components) {
		component->awake();
	}
}

void Entity::update(float deltaTime) {
	for (const auto& component: m_components) {
		component->update(deltaTime);
	}
}

void Entity::postUpdate(float deltaTime) {
	for (const auto& component: m_components) {
		component->postUpdate(deltaTime);
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