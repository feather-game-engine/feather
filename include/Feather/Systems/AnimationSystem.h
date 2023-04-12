#pragma once

#include <Feather/Components/AnimationComponent.h>
#include <Feather/Systems/CollisionSystem.h>

namespace fl {

class AnimationSystem : public ComponentSystem {
public:
	AnimationSystem(EntityManager* entityManager);

	virtual void postUpdate(float deltaTime) override;

	virtual void addEntity(std::shared_ptr<Entity>& entity) override;
private:

}; // class AnimationSystem

} // namespace fl