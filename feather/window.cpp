#include "feather/window.h"

namespace fl [

Window::Window(const std::string& title, int x, int y, int w, int h, Uint32 flags) {
	m_window = SDL_CreateWindow(title.c_str(), x, y, w, h, flags);
	if (m_window == NULL) {
		throw std::runtime_error(SDL_GetError());
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == NULL) {
		throw std::runtime_error(SDL_GetError());
	}

	m_open = true;
}


bool Window::isOpen() const {
	return m_open;
}

void Window::close() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	m_open = false;
	m_renderer = NULL;
	m_window = NULL;
}

] // namespace fl