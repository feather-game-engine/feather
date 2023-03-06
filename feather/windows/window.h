#pragma once

#include <string>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <feather/utilities/color.h>
#include <feather/utilities/rect.h>
#include <feather/windows/view.h>

const int DEFAULT_SCREEN_WIDTH = 640;
const int DEFAULT_SCREEN_HEIGHT = 480;

namespace fl {
class Window {
public:
	Window(const std::string& title, int x = SDL_WINDOWPOS_UNDEFINED, int y = SDL_WINDOWPOS_UNDEFINED, int w = DEFAULT_SCREEN_WIDTH, int h = DEFAULT_SCREEN_HEIGHT, std::uint32_t flags = SDL_WINDOW_SHOWN);

	void init();
	bool isOpen() const;
	void close();

	// TODO: OTHER METHODS
	void clear(fl::Color color = fl::Color::Black);

	void draw(SDL_Texture* texture, const fl::FloatRect& srcRect, const fl::FloatRect& destRect);
	void draw(SDL_Texture* texture, const fl::FloatRect& destRect);

	void display();

	SDL_Window* getWindow() const;
	SDL_Renderer* getRenderer() const;
	const View& getView() const;
	const View& getDefaultView() const;
	FloatRect getViewSpace() const;

	void setView(const View& view);

private: // Attributes
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	std::string m_title;
	IntRect m_area;
	std::uint32_t m_flags;

	View m_defaultView;
	View m_view;

	bool m_open;
}; // class Window

} // namespace fl