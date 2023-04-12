#pragma once

#include <SDL2/SDL.h>

namespace fl {

template <typename T>
class Vector2 {
public:
	T x{};
	T y{};

public: // Constructors and Methods
	constexpr Vector2(T X, T Y);
	constexpr Vector2();

	template <typename U>
	constexpr explicit Vector2(const Vector2<U>& other);

	/**
	 * Convers this Vector to an SDL_Point type.
	*/
	constexpr SDL_Point toSDL_Point() const;
}; // class Vector2

// OPERATORS
template <typename T>
constexpr Vector2<T> operator-(const Vector2<T> &rhs);

template <typename T>
constexpr Vector2<T> &operator+=(Vector2<T> &lhs, const Vector2<T> &rhs);

template <typename T>
constexpr Vector2<T> &operator-=(Vector2<T> &lhs, const Vector2<T> &rhs);

template <typename T>
constexpr Vector2<T> operator+(const Vector2<T> &lhs, const Vector2<T> &rhs);

template <typename T>
constexpr Vector2<T> operator-(const Vector2<T> &lhs, const Vector2<T> &rhs);

template <typename T>
constexpr Vector2<T> operator*(const Vector2<T> &lhs, T rhs);

template <typename T>
constexpr Vector2<T> operator*(T lhs, const Vector2<T> &rhs);

template <typename T>
constexpr Vector2<T> &operator*=(Vector2<T> &lhs, T rhs);

template <typename T>
constexpr Vector2<T> operator/(const Vector2<T> &lhs, T rhs);

template <typename T>
constexpr Vector2<T> &operator/=(Vector2<T> &lhs, T rhs);

template <typename T>
constexpr Vector2<T> operator==(const Vector2<T> &lhs, const Vector2<T> &rhs);

template <typename T>
constexpr Vector2<T> operator!=(const Vector2<T> &lhs, const Vector2<T> &rhs);

/***************************************
 * IMPLEMENTATIONS
***************************************/
#include <Feather/Utilities/Vector2.inl>

using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;
using Vector2u = Vector2<unsigned>;
using Vector2d = Vector2<double>;

} // namespace fl