#pragma once

#include <map>
#include <vector>
#include <memory>
#include "feather/entities/entity.h"

namespace fl {

class EntityManager {
public: // METHODS
	~EntityManager();

	void add(std::vector<std::shared_ptr<fl::Entity>> &otherEntities);
	void add(std::shared_ptr<fl::Entity> entity);

	void update(float deltaTime);
	void postUpdate(float deltaTime);

	void processNewObjects();

	void processRemovals();

private:
	std::map<unsigned, std::shared_ptr<fl::Entity>> m_entities;
	std::vector<std::shared_ptr<fl::Entity>> m_newEntities;
}; // class EntityManager

} // namespace fl