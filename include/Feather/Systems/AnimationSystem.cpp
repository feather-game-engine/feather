#include <Feather/Systems/AnimationSystem.h>
#include <Feather/Entities/Entity.h>
#include <Feather/Systems/EntityManager.h>

namespace fl {

AnimationSystem::AnimationSystem(EntityManager* entityManager) :
	ComponentSystem(entityManager)
{

}

void AnimationSystem::postUpdate(float deltaTime) {
	for(IDtype ID : m_entityIDs) {
		auto ac = m_entities->at(ID)->getComponent<AnimationComponent>();

		ac->updateFrame(deltaTime);

	}
}

void AnimationSystem::addEntity(std::shared_ptr<Entity>& entity) {
	auto a = entity->getComponent<AnimationComponent>();

	if (a != nullptr) {
		m_entityIDs.insert(entity->ID);
	}
}

} // namespace fl