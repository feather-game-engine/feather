#pragma once

#include <memory>
#include <set>

namespace fl {

// Forward Declaration
class EntityManager;
class Entity;

class ComponentSystem {
public:
	ComponentSystem(fl::EntityManager* entityManager);

	virtual void update(float deltaTime);
	virtual void postUpdate(float deltaTime);

	virtual void addEntity(std::shared_ptr<fl::Entity>& entity) = 0;

protected:
	std::set<unsigned> m_entityIDs;

	// Where the actual entities are stored.
	fl::EntityManager* m_entities;

}; // class ComponentSystem

} // namespace fl