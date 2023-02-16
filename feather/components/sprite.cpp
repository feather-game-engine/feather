#include "feather/components/sprite.h"
#include "feather/entities/entity.h"

namespace fl {

Sprite::Sprite(fl::Entity* owner, unsigned drawLayer, unsigned sortOrder)
	: fl::Drawable(owner, drawLayer, sortOrder),
	m_textureID(0u), // 0 == no texture
{

}

void Sprite::awake() {
	// Ensure that Owner Entity has a Transform component
	std::shared_ptr<fl::Transform> ownerTransform = m_owner->getComponent<fl::Transform>();
	if (ownerTransform == nullptr)
		throw std::logic_error("Sprite component needs a Transform component.");
}

void Sprite::draw(fl::Window& window) {

}

unsigned Sprite::loadTextureFromFile(const std::string& path) {
	m_textureID = m_owner->CONTEXT->resources->loadTexture(path);

	SDL_Texture* textureObj = m_owner->CONTEXT->resources->getTexture(m_textureID);

	int width = 0;
	int height = 0;
	SDL_QueryTexture(textureObj, NULL, NULL, &width, &height);
	// Initial textureRect becomes {0, 0, width, height}; ie. The whole size of the texture.
	m_textureRect.w = width;
	m_textureRect.h = height;
}

void Sprite::setTextureRect(const fl::IntRect& rect) {
	m_textureRect = rect;
}

fl::IntRect Sprite::getTextureRect() const {
	return m_textureRect;
}

} // namespace fl