#pragma once

#include <feather/components/keyboardcontrol.h>
#include <feather/systems/componentsystem.h>

namespace fl {

class KeyboardControlSystem : public ComponentSystem {
public:
	KeyboardControlSystem(EntityManager* entityManager);

	virtual void update(float deltaTime);

	virtual void addEntity(std::shared_ptr<Entity>& entity);

}; // class KeyboardControlSystem

} // namespace fl
