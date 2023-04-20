#include "Feather/Components/Sprite.h"
#include "Feather/Entities/Entity.h"

#include <iostream>

namespace fl {

Sprite::Sprite(fl::Entity* owner, unsigned drawLayer, unsigned sortOrder)
	: fl::Drawable(owner, drawLayer, sortOrder),
	m_textureID(0u) // 0 == no texture
{

}

void Sprite::awake() {
	// Ensure that Owner Entity has a Transform component
	m_transform = m_owner->getComponent<Transform>();
	if (m_transform == nullptr)
		throw std::logic_error("Sprite component needs a Transform component.");
}

void Sprite::draw(fl::Window& window) {
	window.draw(m_owner->CONTEXT->resources->getTexture(m_textureID), m_textureRect, this->getGlobalBounds());
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

void Sprite::setTexture(IDtype textureID) {
	SDL_Texture* textureObj = getOwner()->CONTEXT->resources->getTexture(textureID);
	if(textureObj == nullptr)
		throw std::invalid_argument("Invalid. Non-existent texture ID given,");
	m_textureID = textureID;

	m_textureRect.l = 0;
	m_textureRect.t = 0;
	SDL_QueryTexture(textureObj, NULL, NULL, &m_textureRect.w, &m_textureRect.h);
}

void Sprite::setTexture(IDtype textureID, const IntRect& rect) {
	SDL_Texture* textureObj = getOwner()->CONTEXT->resources->getTexture(textureID);
	if(textureObj == nullptr)
		throw std::invalid_argument("Invalid. Non-existent texture ID given,");
	m_textureID = textureID;

	m_textureRect = rect;
}

void Sprite::setTextureRect(const fl::IntRect& rect) {
	m_textureRect = rect;
}

bool Sprite::hasTexture() const {
	return m_textureID > 0;
}

fl::IntRect Sprite::getTextureRect() const {
	return m_textureRect;
}

fl::FloatRect Sprite::getGlobalBounds() const {
	Vector2f scale = m_transform->getScale();
	Vector2f origin = m_transform->getOrigin();
	Vector2f scaledOrigin{
		origin.x * scale.x,
		origin.y * scale.y 
	};

	return FloatRect(
		{
			m_transform->getPosition() - scaledOrigin
		},
		{
			static_cast<float>(m_textureRect.w * scale.x), 
			static_cast<float>(m_textureRect.h * scale.y)	
		}
	);
}

} // namespace fl