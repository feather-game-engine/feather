#include "Feather/Components/Sprite.h"
#include "Feather/Entities/Entity.h"

namespace fl {

Sprite::Sprite(fl::Entity* owner, unsigned drawLayer, unsigned sortOrder)
	: fl::Drawable(owner, drawLayer, sortOrder),
	m_textureID(0u) // 0 == no texture
{

}

void Sprite::awake() {
	// Ensure that Owner Entity has a Transform component
	std::shared_ptr<fl::Transform> ownerTransform = m_owner->getComponent<fl::Transform>();
	if (ownerTransform == nullptr)
		throw std::logic_error("Sprite component needs a Transform component.");
}

void Sprite::draw(fl::Window& window) {
	window.draw(m_owner->CONTEXT->resources->getTexture(m_textureID), this->getGlobalBounds());
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

	return m_textureID;
}

void Sprite::setTextureRect(const fl::FloatRect& rect) {
	m_textureRect = rect;
}

fl::FloatRect Sprite::getTextureRect() const {
	return m_textureRect;
}

fl::FloatRect Sprite::getGlobalBounds() const {
	auto transform = m_owner->getComponent<fl::Transform>();
	return FloatRect(
		{
			transform->getPosition() - transform->getOrigin()
		},
		{
			m_textureRect.w, m_textureRect.h	
		}
	);
}

} // namespace fl