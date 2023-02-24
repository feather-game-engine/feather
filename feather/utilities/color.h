#pragma once

#include <cstdint>

namespace fl {

class Color {
public: // static attributes
	static const Color Black;
	static const Color White;
	static const Color Red;
	static const Color Green;
	static const Color Blue;
	static const Color Yellow;
	static const Color Magenta;
	static const Color Cyan;
	static const Color Transparent;

public: // attributes
	std::uint8_t r{};
	std::uint8_t g{};
	std::uint8_t b{};
	std::uint8_t a{};

public:
	constexpr Color();

	constexpr Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255);
	constexpr Color(std::uint32_t color);

}; // class Color

#include "feather/utilities/color.inl"

} // namespace fl


