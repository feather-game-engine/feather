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

std::shared_ptr<fl::Drawable> Entity::getDrawable() const {
	return m_drawable;
}

std::string Entity::addLabel(std::string label) {
    m_labels.push_back(label);
    return label;
}

bool Entity::hasLabel(std::string label) {
    for(auto l : m_labels) {
        if(l == label) {
            return true;
        }
    }
    return false;
}

} // namespace fl
