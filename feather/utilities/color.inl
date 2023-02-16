constexpr Color::Color() = default;

constexpr Color::Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) 
	: r(red),
	g(green),
	b(blue),
	a(alpha)
{

}

constexpr Color::Color(std::uint32_t color)
	: r(static_cast<std::uint8_t>((color & 0xff000000) >> 24)),
	g(static_cast<std::uint8_t>((color & 0x00ff0000) >> 16)),
	b(static_cast<std::uint8_t>((color & 0x0000ff00) >> 8)),
	a(static_cast<std::uint8_t>(color & 0x000000ff))
{

}

constexpr Color Color::Black(0, 0, 0);
constexpr Color Color::White(255, 255, 255);
constexpr Color Color::Red(255, 0, 0);
constexpr Color Color::Green(0, 255, 0);
constexpr Color Color::Blue(0, 0, 255);
constexpr Color Color::Yellow(255, 255, 0);
constexpr Color Color::Magenta(255, 0, 255);
constexpr Color Color::Cyan(0, 255, 255);
constexpr Color Color::Transparent(0, 0, 0, 0);
