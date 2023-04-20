#pragma once

#include "Feather/Components/Component.h"
#include "Feather/Utilities/Vector2.h"

namespace fl {

class Transform : public fl::Component
{
public:
	Transform(fl::Entity* owner);

	Transform& translate(float x, float y);
	Transform& translate(Vector2f direction);

	Transform& scale(float x, float y);
	Transform& scale(Vector2f factor);

	Transform& setPosition(const Vector2f& position);
	Transform& setOrigin(const Vector2f& origin);
	Transform& setScale(const Vector2f& magnitude);
	Transform& setRotation(double angle);

	const Vector2f& getPosition() const;
	const Vector2f& getScale() const;
	const Vector2f& getOrigin() const;
private:
	Vector2f m_position{0,0};
	Vector2f m_scale{1,1};
	Vector2f m_origin{0,0};
	double m_angle{};
}; // class Transform

} // namespace fl