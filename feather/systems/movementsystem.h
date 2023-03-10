#pragma once

#include <feather/components/velocity.h>
#include <feather/systems/componentsystem.h>

namespace fl {

class MovementSystem : public ComponentSystem {
public:
	MovementSystem(EntityManager* entityManager);

	virtual void update(float deltaTime);
	virtual void postUpdate(float deltaTime);

	virtual void addEntity(std::shared_ptr<Entity>& entity);

}; // class MovementSystem

} // namespace fl