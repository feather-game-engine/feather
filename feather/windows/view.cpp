#include <feather/windows/view.h>
#include <cmath>

#ifdef DEBUG_MODE
#include <feather/debug/debug.h>
#endif

namespace fl {

View::View() : 
	View({0.f, 0.f, 1000.f, 1000.f})
{
}

View::View(const Vector2f& area, const Vector2f& center) :
	m_center(center),
	m_area(area)
{
#ifdef DEBUG_MODE
	fl::log << "Created a View with Center: " << center.x << ", " << center.y << " ;Area: " << area.x << ", " << area.y << " ;" << "\n";
#endif
}

View::View(const FloatRect& rect) :
	m_center(rect.l + (rect.w * 0.5f), rect.t + (rect.h * 0.5f)),
	m_area(rect.w, rect.h)
{

#ifdef DEBUG_MODE
	fl::log << "Created View: " << static_cast<int>(rect.l) << ", " << static_cast<int>(rect.t) << ", " << rect.w << ", " << rect.h << "\n";
#endif
}

const Vector2f& View::getCenter() const {
	return m_center;
}

const Vector2f& View::getArea() const {
	return m_area;
}

const FloatRect& View::getViewport() const {
	return m_viewport;
}

FloatRect View::getViewSpace() const {
	return FloatRect({
		m_center - (m_area * 0.5f),
		m_area
	});
}

void View::setCenter(const Vector2f& center) {
	m_center = center;
}

void View::setArea(const Vector2f& area) {
	m_area = area;
}

void View::setViewport(const FloatRect& viewport) {
	m_viewport = viewport;
}

void View::move(const Vector2f& offset) {
	m_center += offset;
}

FloatRect View::mapToView(const FloatRect& rect) {
	return FloatRect{
		mapToView({rect.l, rect.t}),
		{rect.w, rect.h}
	};
}

Vector2f View::mapToView(const Vector2f& coord) {
	Vector2f screenTL = m_center - (m_area * 0.5f);

	return Vector2f{coord - screenTL};
}

} // namespace fl
