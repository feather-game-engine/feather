// Helper anonymous functions to avoid including <algorithm>
namespace {
	template <typename T>
	constexpr T min(const T& a, const T& b) {
		return a < b ? a : b;
	}

	template <typename T>
	constexpr T max(const T& a, const T& b) {
		return a > b ? a : b;
	}
}



template <typename T>
constexpr Rect<T>::Rect() = default;

template <typename T>
constexpr Rect<T>::Rect(T left, T top, T width, T height)  :
	l(left), 
	t(top), 
	w(width), 
	h(height)
{

}

template<typename T>
constexpr Rect<T>::Rect(Vector2<T> topLeft, Vector2<T> size) :
	l(topLeft.x),
	t(topLeft.y),
	w(size.x),
	h(size.y)
{

}

template <typename T>
template <typename U>
constexpr Rect<T>::Rect(const Rect<U>& otherRect) :
	l(static_cast<T>(otherRect.l)),
	t(static_cast<T>(otherRect.t)),
	w(static_cast<T>(otherRect.w)),
	h(static_cast<T>(otherRect.h))
{

}

template <typename T>
template <typename U>
constexpr Rect<T>& Rect<T>::operator=(const Rect<U>& rhs) {
	l = static_cast<T>(rhs.l);
	t = static_cast<T>(rhs.t);
	w = static_cast<T>(rhs.w);
	h = static_cast<T>(rhs.h);

	return *this;
}

template <typename T>
constexpr bool Rect<T>::contains(const Vector2<T>& point) const {
	const T minX = min(l, static_cast<T>(l + w));
	const T maxX = max(l, static_cast<T>(l + w));
	const T minY = min(t, static_cast<T>(t + h));
	const T maxY = max(t, static_cast<T>(t + h));

	return (point.x >= minX) && (point.x < maxX) && (point.y >= minY) && (point.y < maxY);
}

template <typename T>
constexpr std::optional<Rect<T>> Rect<T>::intersects(const Rect<T>& rect) const {
	const T r1minX = min(l, static_cast<T>(l + w));
	const T r1maxX = max(l, static_cast<T>(l + w));
	const T r1minY = min(t, static_cast<T>(t + h));
	const T r1maxY = max(t, static_cast<T>(t + h));

	const T r2minX = min(rect.l, static_cast<T>(rect.l + rect.w));
	const T r2maxX = max(rect.l, static_cast<T>(rect.l + rect.w));
	const T r2minY = min(rect.t, static_cast<T>(rect.t + rect.h));
	const T r2maxY = max(rect.t, static_cast<T>(rect.t + rect.h));

	const T interLeft = max(r1minX, r2minX);
	const T interTop = max(r1minY, r2minY);
	const T interRight = min(r1maxX, r2maxX);
	const T interBottom = min(r1maxY, r2maxY);

	if (interLeft < interRight && interTop < interBottom) {
		return std::make_optional<Rect<T>>({
			{interLeft, interTop},
			{interRight - interLeft, interBottom - interTop}
		});
	}
	else {
		return std::nullopt;
	}
}


template <typename T>
constexpr SDL_Rect Rect<T>::toSDL_Rect() const {
	return SDL_Rect{
		static_cast<int>(l), 
		static_cast<int>(t), 
		static_cast<int>(w), 
		static_cast<int>(h)
	};
}