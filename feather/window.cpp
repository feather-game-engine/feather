#include "feather/window.h"

namespace fl {

Window::Window(const std::string& title, int x, int y, int w, int h, std::uint32_t flags) {
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

void Window::clear(fl::Color color) {
	SDL_SetRenderDrawColor( gRenderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(m_renderer);
}

void Window::draw(SDL_Texture* texture, const fl::IntRect& srcRect, const fl::IntRect& destRect) {
	SDL_RenderCopy(m_renderer, texture, srcRect.toSDL_Rect(), destRect.toSDL_Rect());
}

void Window::draw(SDL_Texture* texture, const fl::IntRect& destRect) {
	SDL_RenderCopy(m_renderer, texture, destRect.toSDL_Rect();)
}

void Window::dsiplay() {
	SDL_RenderPresent(m_renderer);t
}

SDL_Window* Window::getWindow() const {
	return m_window;
}

SDL_Renderer* Window::getRenderer() const {
	return m_renderer;
}

} // namespace fl