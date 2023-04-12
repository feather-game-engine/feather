#include "Feather/Components/Drawable.h"

namespace fl {

Drawable::Drawable(fl::Entity* owner, unsigned drawLayer, unsigned sortOrder)
	: fl::Component(owner),
	m_drawLayer(drawLayer),
	m_sortOrder(sortOrder)
{

}

void Drawable::setDrawLayer(unsigned drawLayer) {
	m_drawLayer = drawLayer;
}

unsigned Drawable::getDrawLayer() const {
	return m_drawLayer;
}

void Drawable::setSortOrder(unsigned sortOrder) {
	m_sortOrder = sortOrder;
}

unsigned Drawable::getSortOrder() const {
	return m_sortOrder;
}

} // namespace