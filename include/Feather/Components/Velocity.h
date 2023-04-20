#pragma once

#include <cmath>
#include <Feather/Components/Component.h>
#include <Feather/Components/Transform.h>
#include <Feather/Utilities/Vector2.h>

namespace fl {

class Velocity : public Component {
public:
	Velocity(Entity* entity);

	virtual void awake() override;

	void set(const Vector2f& vel);
	void set(float x, float y);
	void setX(float x);
	void setY(float y);
	const Vector2f& get() const;

private:
	void clampVelocity();

	Vector2f m_velocity{0.f, 0.f};
	Vector2f m_maxVelocity{1000.f, 1000.f};
}; // class Velocity

} // namespace fl