#pragma once

#include <set>
#include "feather/systems/entitymanager.h"

namespace fl {

class ComponentSystem {
public:

	virtual void update(float deltaTime);
	virtual void postUpdate(float deltaTime);

	virtual void add(std::shared_ptr<fl::Entity> entity) = 0;

protected:
	std::set<unsigned> m_entityIDs;

}; // class ComponentSystem

} // namespace fl