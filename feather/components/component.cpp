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

fl::Entity* Component::getOwner() {
	return m_owner;
}

} // namespace fl