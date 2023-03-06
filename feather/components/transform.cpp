#include "feather/components/transform.h"
#include "feather/entities/entity.h"

namespace fl {

Transform::Transform(fl::Entity* owner)
	: fl::Component(owner) 
{

}

Transform& Transform::translate(float x, float y){
	m_position.x += x;
	m_position.y += y;
	return *this;
}

Transform& Transform::translate(Vector2f direction){
	m_position += direction;
	return *this;
}

Transform& Transform::scale(float x, float y){
	m_scale.x *= x;
	m_scale.y *= y;
	return *this;
}

Transform& Transform::scale(Vector2f factor){
	m_scale.x *= factor.x;
	m_scale.y *= factor.y;
	return *this;
}

Transform& Transform::setPosition(const Vector2f& position) {
	m_position = position;
	return *this;
}

Transform& Transform::setOrigin(const Vector2f& origin) {
	m_origin = origin;
	return *this;
}

Transform& Transform::setScale(const Vector2f& magnitude) {
	m_scale = magnitude;
	return *this;
}

Transform& Transform::setRotation(double angle) {
	m_angle = angle;
	return *this;
}

const Vector2f& Transform::getPosition() const{
	return m_position;
}
const Vector2f& Transform::getScale() const{
	return m_scale;
}
const Vector2f& Transform::getOrigin() const{
	return m_origin;
}

}