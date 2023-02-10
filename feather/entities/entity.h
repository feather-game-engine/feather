#pragma once

#include <vector>
#include <memory>
#include "feather/components/component.h"

namespace fl {

class Entity {
public: // ATTRIBUTES
	static unsigned count;
	const unsigned ID;

public: // METHODS & CONSTRUCTORS
	Entity();

	/**
	 * awake()
	 * Use to ensure that all components are present and all attributes are initialized.
	*/
	virtual void awake();

	virtual void update(float deltaTime);
	virtual void postUpdate(float deltaTime);
	virtual void draw();

	bool isStatic() const;
	void setStatic(bool isStatic);

	bool isQueuedForRemoval() const;
	void queueForRemoval(bool remove = true);


	/**
	 * addComponent()
	 * - Creates a Component of Type T and stores it into this entity's Component array. T must be a subclass of fl::Component. Returns a shared_ptr of the created Component.
	*/
	template<typename T>
	std::shared_ptr<T> addComponent();


	/**
	 * getComponent()
	 * - Searches the Component array for an object of type T and return a smart_ptr to it. Returns nullptr if none exist.
	*/
	template<typename T>
	std::shared_ptr<T> getComponent();

private: // ATTRIBUTES
	
	/* Boolean attribute to signal the systems if this entity is subject for destruction.	*/
	bool m_queuedForRemoval = false;
	bool m_static = false;
	// TODO: Pointer to Game Context here.

	std::vector<std::shared_ptr<fl::Component>> m_components;

}; // class Entity

template<typename T>
std::shared_ptr<T> Entity::addComponent() {
	// Prevents this method from continuing if T is not a derivation of fl::Component
	static_assert(std::is_base_of<fl::Component, T>::value, "Error. T must be a derived type of fl::Component. Assertion returned false");

	// Checks m_components for any type T object stored. Returns it if it does.
	std::shared_ptr<T> existingComponent = this->getComponent<T>();
	if(existingComponent != nullptr)
		return existingComponent;

	// T does not exist. Create one and store it into memory.
	std::shared_ptr<T> newComponent = std::make_shared<T>(this);
	m_components.push_back(newComponent);

	return newComponent;
}

template <typename T>
std::shared_ptr<T> Entity::getComponent() {
	for (auto& existingComponent : m_components)
	{
		if (std::dynamic_pointer_cast<T>(existingComponent))
		{
			return std::dynamic_pointer_cast<T>(existingComponent);
		}
	}

	return nullptr;
}


} // namespace fl