#pragma once

#include <feather/utilities/rect.h>
#include <feather/utilities/vector2.h>

namespace fl {

class View {
public:
	View();
	View(const Vector2f& area, const Vector2f& center);
	View(const FloatRect& rectangle);

	const Vector2f& getCenter() const;
	const Vector2f& getArea() const;
	const FloatRect& getViewport() const;
	// const Angle& getRotation() const;

	FloatRect getViewSpace() const;

	void setCenter(const Vector2f& center);
	void setArea(const Vector2f& area);
	// void setRotation(const Angle& angle);
	void setViewport(const FloatRect& viewport);

	// void reset(const FloatRect& rectangle);
	void move(const Vector2f& offset);
	// void rotate(Angle angle);
	// void zoom(float factor);

	/*******************************************
	 * @brief maps the given rect in relation to this view.
	 * 
	 * This method accepts a rectangle oriented in world coordinates and transform it to a rectangle oriented more towards this view (i.e. screen coordinates).
	 * @param rect rectangle to be mapped.
	 * @return a rectangle mapped relatively to the view.
	*******************************************/
	FloatRect mapToView(const FloatRect& rect);

	/******************************************
	 * @brief maps the given vector in relation to this view
	 * 
	 * @param coord vector to be mapped.
	 * @return a vector mapped to the view.
	******************************************/
	Vector2f mapToView(const Vector2f& coord);

private:
	Vector2f 	m_center;
	Vector2f 	m_area;
	// Angle 		m_rotation;

	FloatRect 	m_viewport{{0, 0}, {1, 1}};

}; // class View


} // namespace fl
