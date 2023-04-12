#include <Feather/Systems/MovementSystem.h>
#include <Feather/Systems/EntityManager.h>

namespace fl {

MovementSystem::MovementSystem(EntityManager* entityManager) :
	ComponentSystem(entityManager)
{

}

void MovementSystem::update(float deltaTime) {
	for(const unsigned& ID : m_entityIDs) {
		auto e = m_entities->at(ID);
		auto v = e->getComponent<Velocity>();
		auto t = e->getComponent<Transform>();

		Vector2f displacement = v->get() * deltaTime;
		t->translate(displacement);
	}
}

void MovementSystem::postUpdate(float deltaTime) {
	for(const unsigned& ID : m_entityIDs) {
		m_entities->at(ID)->getComponent<Velocity>()->set(0.f, 0.f);
	}

}

void MovementSystem::addEntity(std::shared_ptr<Entity>& entity) {
	auto velocity = entity->getComponent<Velocity>();
	if(velocity != nullptr) {
		this->m_entityIDs.insert(entity->ID);
	}
}

} // namespace fl
