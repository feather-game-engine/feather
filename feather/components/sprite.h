#pragma once

#include <stdexcept>
#include <string>
#include <SDL2/SDL.h>
#include "feather/components/drawable.h"
#include "feather/utilities/rect.h"

namespace fl {

class Sprite : public fl::Drawable {
public:
	Sprite(fl::Entity* owner, unsigned drawLayer, unsigned sortOrder);

	virtual void awake();

	virtual void draw(fl::Window& window);

	unsigned loadTextureFromFile(const std::string& path);
	void setTextureRect(const fl::IntRect& rect);
	fl::IntRect getTextureRect() const;

	/**
	 * getGlobalBounds()
	 * @brief get the bounding rectangle of the entity in relation to the global coordinates after taking into account transformations.
	 * @return global bounding rectangle of the entity.
	 * */ 
	fl::IntRect getGlobalBounds() const;
private:
	unsigned m_textureID;

	fl::IntRect m_textureRect;
}; // class Sprite

}; // namespace fl