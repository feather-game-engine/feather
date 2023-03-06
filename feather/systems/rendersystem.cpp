#include <feather/systems/rendersystem.h>
#include <feather/systems/entitymanager.h>

namespace fl {

RenderSystem::RenderSystem(EntityManager* entities) :
	m_entities(entities)
{

}

void RenderSystem::add(std::vector<std::shared_ptr<Entity>> entities) {
	for(auto& e : entities) {
		this->add(e);
	}
}

void RenderSystem::add(std::shared_ptr<Entity> entity) {
	auto drawable = entity->getDrawable();
	if (drawable == nullptr)
		return;
	DrawLayer layer = drawable->getDrawLayer();
	if(m_drawables.contains(layer)) {
		m_drawables.at(layer).push_back(entity->ID);
	}
	else {
		m_drawables.insert_or_assign(layer, std::vector<IDtype>{entity->ID});
	}

}

void RenderSystem::remove(IDtype entityID) {
	for(auto& v: m_drawables) {
		std::erase(v.second, entityID);
	}
}

void RenderSystem::update(float) {
	sort();
}

void RenderSystem::draw(Window& window) {
	FloatRect viewSpace = window.getViewSpace();

	for(auto& v : m_drawables) {
		for(auto& id : v.second) {
			auto drawable = m_entities->at(id)->getDrawable();
			if(viewSpace.intersects(drawable->getGlobalBounds()).has_value()) {
				drawable->draw(window);
			}
		}
	}
}

void RenderSystem::sort() {
	EntityManager* entities = m_entities;
	auto layerSort = [entities](IDtype a, IDtype b) -> bool {
		return entities->at(a)->getDrawable()->getSortOrder() < entities->at(b)->getDrawable()->getSortOrder();
	};

	for(auto& layer : m_drawables) {
		if(!std::is_sorted(layer.second.begin(), layer.second.end(), layerSort)) {
			std::sort(layer.second.begin(), layer.second.end(), layerSort);
		}
	}
}

}