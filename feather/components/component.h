#pragma once

namespace fl {

// Forward Declaration
class Entity;

class Component {
public: // METHODS & CONSTRUCTORS
	Component(fl::Entity* owner);
	virtual ~Component();

	virtual void awake();
	virtual void update(float deltaTime);
	virtual void postUpdate(float deltaTime);

	fl::Entity* getOwner();
protected: // ATTRIBUTES
	fl::Entity* m_owner;

}; // class Component

} // namespace fl