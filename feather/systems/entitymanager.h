#pragma once

#include <map>
#include <vector>
#include <memory>
#include "feather/entities/entity.h"
#include "feather/systems/componentsystem.h"

namespace fl {

class EntityManager {
public: // METHODS
	~EntityManager();

	void add(std::vector<std::shared_ptr<fl::Entity>> &otherEntities);
	void add(std::shared_ptr<fl::Entity> entity);

	template <typename T>
	void includeSystem<T>();

	void update(float deltaTime);
	void postUpdate(float deltaTime);

	// TODO: draw() method after a render system is implemented

	void processNewObjects();

	void processRemovals();

	std::shared_ptr<fl::Entity>& operator[](unsigned entityID);

private:
	std::map<unsigned, std::shared_ptr<fl::Entity>> m_entities;
	std::vector<std::shared_ptr<fl::Entity>> m_newEntities;

	std::vector<std::shared_ptr<fl::ComponentSystem>> m_componentSystems;
}; // class EntityManager


template <typename T>
void EntityManager::includeSystem<T>() {
	static_assert(std::is_base_of<fl::ComponentSystem, T>::value, "Error. EntityManager::includeSystem<T>(). T must be a derived type of fl::ComponentSystem. Assertion returned false.");

	for (auto& existingSystem : m_componentSystems) {
		if (std::dynamic_pointer_cast<T>(existingSystem)) {
			return;
		}
	}

	std::shared_ptr<T> newComponentSystem = std::make_shared<T>(this);
	m_componentSystem.push_back(newComponentSystem);
}


} // namespace fl