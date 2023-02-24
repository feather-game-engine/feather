#include "feather/systems/entitymanager.h"

namespace fl {

EntityManager::~EntityManager() {
	m_entities.clear();
	m_newEntities.clear();
}

void EntityManager::add(std::vector<std::shared_ptr<fl::Entity>>& newEntities) {
	m_newEntities.insert(m_newEntities.end(), newEntities.begin(), newEntities.end());
}

void EntityManager::add(std::shared_ptr<fl::Entity> entity) {
	m_newEntities.push_back(entity);
}

void EntityManager::update(float deltaTime) {
	processNewObjects();
	for (auto& system : m_componentSystems) {
		system->update(deltaTime);
	}
}

void EntityManager::postUpdate(float deltaTime) {
	for (auto& system : m_componentSystems) {
		system->postUpdate(deltaTime);
	}
	processRemovals();
}

void EntityManager::draw(fl::Window& window) {
	// TEMPORARY until a dedicated RenderSystem is created.
	for (unsigned eID : m_drawables) {
		auto drawable = m_entities[eID]->getDrawable();
		drawable->draw(window);
	}
}

void EntityManager::processNewObjects() {
	if (m_newEntities.size() <= 0) {
		// No new objects. terminate function.
		return;
	}

	for (auto& e: m_newEntities) {
		e->awake();

		const unsigned ID = e->ID;
		m_entities.insert_or_assign(ID, e);

		if (e->getDrawable() != nullptr) {
			m_drawables.insert(ID);
		}

		for (auto& system: m_componentSystems) {
			system->addEntity(e);
		}
	}

	m_newEntities.clear();
}

void EntityManager::processRemovals() {
	// TODO
}

std::shared_ptr<fl::Entity>& EntityManager::operator[](unsigned entityID) {
	auto e = m_entities.find(entityID);

	// This should return a pointer to nullptr/m_entities.end if no entityID does not exist as a key.
	return e->second;
}

} // namespace fl