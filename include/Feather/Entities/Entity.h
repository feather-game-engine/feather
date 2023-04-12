#pragma once

#include <vector>
#include <memory>
#include <Feather/Components/Component.h>
#include <Feather/Components/Drawable.h>
#include <Feather/Entities/SharedContext.h>
#include <Feather/Utilities/Types.h>

namespace fl {

class Entity {
public: // ATTRIBUTES
	static IDtype count;
	const IDtype ID;

	const fl::SharedContext* CONTEXT;
public: // METHODS & CONSTRUCTORS
	Entity(fl::SharedContext* context);

	/**
	 * awake()
	 * Use to ensure that all components are present and all attributes are initialized.
	*/
	virtual void awake();

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

	std::shared_ptr<fl::Drawable> getDrawable() const;

    /* Labelling an entity */
    std::string addLabel(std::string label);

    bool hasLabel(std::string label);


private: // ATTRIBUTES
	
	/* Boolean attribute to signal the systems if this entity is subject for destruction.	*/
	bool m_queuedForRemoval = false;
	bool m_static = false;
	// TODO: Pointer to Game Context here.

	std::vector<std::shared_ptr<fl::Component>> m_components;

	std::shared_ptr<fl::Drawable> m_drawable = nullptr;

    std::vector<std::string> m_labels;

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

	// Checks if the object is also a drawable.
	if(std::dynamic_pointer_cast<fl::Drawable>(newComponent)) {
		m_drawable = std::dynamic_pointer_cast<fl::Drawable>(newComponent);
	}

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
