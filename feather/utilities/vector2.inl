template <typename T>
constexpr Vector2<T>::Vector2() = default;

template<typename T>
constexpr Vector2<T>::Vector2(T X, T Y) : 
	x(X), 
	y(Y)
{

}

template <typename T>
template <typename U>
constexpr Vector2<T>::Vector2(const Vector2<U>& other)  : 
	x(static_cast<T>(other.x)), 
	y(static_cast<T>(other.y)) 
{

}

template <typename T>
constexpr SDL_Point Vector2<T>::toSDL_Point() const {
	return SDL_Point{
		static_cast<int>(x),
		static_cast<int>(y)
	};
}

/************************************
 * Vector2 OPERATORS
************************************/
template<typename T>
constexpr Vector2<T> operator-(const Vector2<T>& rhs) {
	return Vector2<T>(-rhs.x, -rhs.y);
}

template<typename T>
constexpr Vector2<T>& operator+=(Vector2<T>& lhs, const Vector2<T>& rhs) {
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return lhs;
}

template<typename T>
constexpr Vector2<T>& operator-=(Vector2<T>& lhs, const Vector2<T>& rhs) {
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	return lhs;
}

template<typename T>
constexpr Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs) {
	return Vector2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
}

template<typename T>
constexpr Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs) {
	return Vector2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
}

template<typename T>
constexpr Vector2<T> operator*(const Vector2<T>& lhs, T rhs) {
	return Vector2<T>(lhs.x * rhs, lhs.y * rhs);
}

template <typename T>
constexpr Vector2<T> operator*(T lhs, const Vector2<T>& rhs) {
	return Vector2<T>(rhs.x * lhs, rhs.y * lhs);
}

template <typename T>
constexpr Vector2<T>& operator*=(Vector2<T>& lhs, T rhs) {
	lhs.x *= rhs;
	lhs.y *= rhs;

	return lhs;
}

template<typename T>
constexpr Vector2<T> operator/(const Vector2<T>& lhs, T rhs) {
	return Vector2<T>(lhs.x / rhs, lhs.y / rhs);
}

template <typename T>
constexpr Vector2<T> operator/=(Vector2<T>& lhs, T rhs) {
	lhs.x /= rhs;
	lhs.y /= rhs;
	return lhs;
}

template<typename T>
bool operator==(const Vector2<T>& lhs, const Vector2<T>& rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y;
}

template<typename T>
bool operator!=(const Vector2<T>& lhs, const Vector2<T>& rhs) {
	return lhs.x != rhs.x || lhs.y != rhs.y;
}
