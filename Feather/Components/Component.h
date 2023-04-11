#pragma once

namespace fl {

/* Forward Declaration. Every non-virtual subclass of fl::Component should be declared in a file that imports "feather/entities/entity.h"*/
class Entity;

class Component {
public: // METHODS & CONSTRUCTORS
	Component(fl::Entity* owner);
	virtual ~Component();

	virtual void awake();

	fl::Entity* getOwner();
protected: // ATTRIBUTES
	fl::Entity* m_owner;

}; // class Component

} // namespace fl