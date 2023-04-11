#include <Feather/Components/Velocity.h>
#include <Feather/Entities/Entity.h>

namespace fl {

Velocity::Velocity(Entity* owner) :
	Component(owner)
{

}

void Velocity::awake() {
	auto transform = m_owner->getComponent<Transform>();
	if (transform == nullptr) {
		throw std::logic_error("Velocity Component requires a Transform component");
	}
}

void Velocity::set(const Vector2f& vel)
{
	m_velocity = vel;
	clampVelocity();
}

void Velocity::set(float x, float y)
{
	m_velocity.x = x;
	m_velocity.y = y;
	clampVelocity();
}

void Velocity::setX(float x)
{
	m_velocity.x = x;
	clampVelocity();
}

void Velocity::setY(float y)
{
	m_velocity.y = y;
	clampVelocity();
}

const Vector2f& Velocity::get() const
{
	return m_velocity;
}

void Velocity::clampVelocity()
{
	if (fabs(m_velocity.x) > m_maxVelocity.x)
	{
		if(m_velocity.x > 0)
		{
			m_velocity.x = m_maxVelocity.x;
		}
		else
		{
			m_velocity.x = -m_maxVelocity.x;
		}
	}

	if (fabs(m_velocity.y) > m_maxVelocity.y)
	{
		if (m_velocity.y > 0.f)
		{
			m_velocity.y = m_maxVelocity.y;
		}
		else
		{
			m_velocity.y = - m_maxVelocity.y;
		}
	}
}

} // namespace fl