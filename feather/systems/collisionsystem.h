#pragma once

#include <feather/components/collider.h>
#include <feather/systems/componentsystem.h>

namespace fl {

class CollisionSystem : public ComponentSystem {
public:
	CollisionSystem(EntityManager* entityManager);

	virtual void update(float deltaTime);
	virtual void postUpdate(float deltaTime);

	virtual void addEntity(std::shared_ptr<Entity>& entity);

}; 

} 
