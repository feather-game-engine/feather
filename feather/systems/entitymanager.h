#pragma once

#include <map>
#include <memory>
#include <vector>
#include <set>
#include <stdexcept>
#include <feather/entities/entity.h>
#include <feather/systems/componentsystem.h>
#include <feather/systems/rendersystem.h>

namespace fl {

class EntityManager {
public: // METHODS
	EntityManager();
	~EntityManager();

	void add(std::vector<std::shared_ptr<fl::Entity>> &otherEntities);
	void add(std::shared_ptr<fl::Entity> entity);

	template <typename T>
	void includeSystem();

	void update(float deltaTime);
	void postUpdate(float deltaTime);

	void draw(fl::Window& window);

	void processNewObjects();

	void processRemovals();

	std::shared_ptr<fl::Entity>& operator[](unsigned entityID);
	std::shared_ptr<fl::Entity>& at(unsigned entityID);

private:
	std::map<unsigned, std::shared_ptr<fl::Entity>> m_entities;
	std::vector<std::shared_ptr<fl::Entity>> m_newEntities;

	RenderSystem m_drawables;

	std::vector<std::shared_ptr<fl::ComponentSystem>> m_componentSystems;
}; // class EntityManager


template <typename T>
void EntityManager::includeSystem() {
	static_assert(std::is_base_of<fl::ComponentSystem, T>::value, "Error. EntityManager::includeSystem<T>(). T must be a derived type of fl::ComponentSystem. Assertion returned false.");

	for (auto& existingSystem : m_componentSystems) {
		if (std::dynamic_pointer_cast<T>(existingSystem)) {
			return;
		}
	}

	std::shared_ptr<T> newComponentSystem = std::make_shared<T>(this);
	m_componentSystems.push_back(newComponentSystem);
}


} // namespace fl