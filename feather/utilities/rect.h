#pragma once

#include <optional>
#include <SDL2/SDL_rect.h>
#include <feather/utilities/vector2.h>

namespace fl {

template <typename T>
class Rect {
public: // ATTRIBUTES
	T l = T(); // left
	T t = T(); // top
	T w = T(); // width
	T h = T(); // height

public: // METHODS & CONSTRUCTORS
	constexpr Rect();
	constexpr Rect(T left, T top, T width, T height);
	constexpr Rect(Vector2<T> topLeft, Vector2<T> size);
	template <typename U>
	constexpr Rect(const Rect<U>& otherRect);

	template <typename U>
	constexpr Rect<T>& operator=(const Rect<U>& rhs);

	constexpr bool contains(const Vector2<T>& point) const;
	constexpr std::optional<Rect<T>> intersects(const Rect<T>& rect) const;

	constexpr SDL_Rect toSDL_Rect() const;
}; // class Rect


#include "feather/utilities/rect.inl"

// COMMON TYPEDEFS
using FloatRect = fl::Rect<float>;
using IntRect = fl::Rect<int>;

}; // namespace fl