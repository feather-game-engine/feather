#pragma once

#include <memory>
#include <map>
#include <vector>
#include <Feather/Components/Drawable.h>
#include <Feather/Entities/Entity.h>
#include <Feather/Windows/Window.h>


namespace fl {

class EntityManager;

using DrawLayer = unsigned;

class RenderSystem {
public:
	RenderSystem(EntityManager* entities);

	void add(std::vector<std::shared_ptr<Entity>> entities);
	void add(std::shared_ptr<Entity> entity);

	void remove(IDtype entityID);

	void update(float deltaTime);
	void draw(Window& window);

private:
	void sort();

	std::map<DrawLayer, std::vector<IDtype>> m_drawables;

	EntityManager* m_entities;
}; // class RenderSystem

} // namespace fl