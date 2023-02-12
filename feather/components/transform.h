#pragma once

#include "feather/components/component.h"
#include "feather/vector.h"

namespace fl {

class Transform : public fl::Component
{
public:
	Vector position;
	Vector scale;
	double angle;

public:
	Transform(fl::Entity* owner);

	Transform& Translate(int x, int y);
	Transform& Translate(Vector direction);

	Transform& Scale(int x, int y);
	Transform& Scale(Vector magnitude);
}; // class Transform

} // namespace fl