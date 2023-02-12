#include "feather/components/transform.h"
#include "feather/entities/entity.h"

namespace fl {

Transform::Transform(fl::Entity* owner)
	: fl::Component(owner) 
{

}

Transform& Transform::Translate(int x, int y){
	position.x += x;
	position.y += y;
	return *this;
}

Transform& Transform::Translate(Vector direction){
	position += direction;
	return *this;
}

Transform& Transform::Scale(int x, int y){
	scale.x *= x;
	scale.y *= y;
	return *this;
}

Transform& Transform::Scale(Vector magnitude){
	scale *= magnitude;
	return *this;
}

}