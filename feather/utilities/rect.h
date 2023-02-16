#pragma once

#include <SDL2/SDL_rect.h>

namespace fl {

template <typename T>
class Rect {
public: // ATTRIBUTES
	T l = T(); // left
	T t = T(); // top
	T w = T(); // width
	T h = T(); // height

public: // METHODS & CONSTRUCTORS
	Rect();
	Rect(T left, T top, T width, T height);
	
	template <typename U>
	Rect(const Rect<U>& otherRect);

	template <typename U>
	Rect<T>& operator=(const Rect<U>& rhs);

	SDL_Rect toSDL_Rect() const;
}; // class Rect


#include "feather/utilities/rect.inl"

// COMMON TYPEDEFS
using FloatRect = fl::Rect<float>;
using IntRect = fl::Rect<int>;

}; // namespace fl