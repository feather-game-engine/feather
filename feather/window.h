#pragma once

#include <string>
#include <stdexcept>
#include <SDL2/SDL.h>

const int DEFAULT_SCREEN_WIDTH = 640;
const int DEFAULT_SCREEN_HEIGHT = 480;

namespace fl {
class Window {
public:
	Window(const std::string& title, int x = SDL_WINDOWPOS_UNDEFINED, int y = SDL_WINDOWPOS_UNDEFINED, int w = DEFAULT_SCREEN_WIDTH, int h = DEFAULT_SCREEN_HEIGHT, Uint32 flags = SDL_WINDOW_SHOWN);

	bool isOpen() const;
	void close();

	// TODO: OTHER METHODS

	SDL_Window* getWindow() const;
	SDL_Renderer* getRenderer() const;

private: // Attributes
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	bool m_open;
}; // class Window

} // namespace fl