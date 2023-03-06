#pragma once

#include <memory>
#include <feather/components/component.h>
#include <feather/windows/window.h>

namespace fl {

class Drawable : public fl::Component {
public:
	Drawable(fl::Entity* owner, unsigned drawLayer = 0, unsigned sortOrder = 0);

	virtual void draw(fl::Window& window) = 0;

	void setDrawLayer(unsigned drawLayer);
	unsigned getDrawLayer() const;

	void setSortOrder(unsigned sortOrder);
	unsigned getSortOrder() const;

	virtual FloatRect getGlobalBounds() const = 0;

protected:
	// Determines at which layer the drawable will be drawn (i.e. Background, Objects, GUI etc.) 
	unsigned m_drawLayer;

	// Determines how this Drawable will be sorted within its respective layer. Lower sortOrder are drawn first.
	unsigned m_sortOrder;

}; // class Drawable

} // namespace fl