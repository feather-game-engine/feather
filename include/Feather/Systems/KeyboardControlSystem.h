#pragma once

#include <Feather/Components/KeyboardControl.h>
#include <Feather/Systems/ComponentSystem.h>

namespace fl {

class KeyboardControlSystem : public ComponentSystem {
public:
	KeyboardControlSystem(EntityManager* entityManager);

	virtual void update(float deltaTime);

	virtual void addEntity(std::shared_ptr<Entity>& entity);

}; // class KeyboardControlSystem

} // namespace fl
