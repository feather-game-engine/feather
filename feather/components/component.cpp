#include "feather/components/component.h"

namespace fl {

Component::Component(fl::Entity* owner)
	: m_owner(owner) 
{

}

Component::~Component() {

}

void Component::awake() {

}

void Component::update(float deltaTime) {

}

void Component::postUpdate(float deltaTime) {

}

fl::Entity* Component::getOwner() {
	return m_owner;
}

} // namespace fl