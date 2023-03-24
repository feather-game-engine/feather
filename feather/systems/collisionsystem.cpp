#include <feather/systems/collisionsystem.h>
#include <feather/systems/entitymanager.h>

namespace fl {

CollisionSystem::CollisionSystem(EntityManager* entityManager) :
	ComponentSystem(entityManager)
{

}

void CollisionSystem::update(float deltaTime) {
	for(const unsigned& ID : m_entityIDs) {
		auto e = m_entities->at(ID);
		auto c = e->getComponent<Collider>();
        for(const unsigned& ID2 : m_entityIDs) {
            if(ID2 == e->ID) continue;
            auto e2 = m_entities->at(ID2);
            auto c2 = e2->getComponent<Collider>();
            if(SDL_HasIntersection(&c->getHitbox(), &c2->getHitbox())) {
                c->setColliding(true);
                c2->setColliding(true);
                c->addCollision(e2.get());
                c2->addCollision(e.get());
            }
        }
	}
}

void CollisionSystem::postUpdate(float deltaTime) {
	for(const unsigned& ID : m_entityIDs) {
		auto c = m_entities->at(ID)->getComponent<Collider>();
        if(c->isColliding()) {
            for(const unsigned& ID2 : m_entityIDs) {
                if(ID2 == ID) continue;
                auto e2 = m_entities->at(ID2);
                auto c2 = e2->getComponent<Collider>();
                if(SDL_HasIntersection(&c->getHitbox(), &c2->getHitbox())) {
                    continue;
                }
                else {
                    c->setColliding(false);
                    c->clearCollisions();
                }
            }
        }
	}

}

void CollisionSystem::addEntity(std::shared_ptr<Entity>& entity) {
	auto collider = entity->getComponent<Collider>();
	if(collider != nullptr) {
		this->m_entityIDs.insert(entity->ID);
	}
}

}
