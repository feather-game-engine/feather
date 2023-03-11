#include <feather/windows/window.h>

namespace fl {

Window::Window(const std::string& title, int x, int y, int w, int h, std::uint32_t flags) :
	m_title(title),
	m_area(x,y,w,h),
	m_flags(flags)
{

}

void Window::init() {
	m_window = SDL_CreateWindow(m_title.c_str(), m_area.l, m_area.t, m_area.w, m_area.h, m_flags);

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
	SDL_SetRenderDrawColor( m_renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(m_renderer);
}

void Window::draw(SDL_Texture* texture, const fl::FloatRect& textureRect, const fl::FloatRect& destRect) {
	// Convert world coordinates to screen coordinates.
	SDL_Rect screenCoordsRect = m_view.mapToView(destRect).toSDL_Rect();
	SDL_Rect textureSDLRect = textureRect.toSDL_Rect();

	SDL_RenderCopy(m_renderer, texture, &textureSDLRect, &screenCoordsRect);
}

void Window::draw(SDL_Texture* texture, const fl::FloatRect& destRect) {
	// Convert world coordinates to screen coordinates.
	SDL_Rect dstSDLRect = m_view.mapToView(destRect).toSDL_Rect();

	SDL_RenderCopy(m_renderer, texture, NULL ,&dstSDLRect);
}

void Window::display() {
	SDL_RenderPresent(m_renderer);
}

SDL_Window* Window::getWindow() const {
	return m_window;
}

SDL_Renderer* Window::getRenderer() const {
	return m_renderer;
}

const View& Window::getView() const {
	return m_view;
}

const View& Window::getDefaultView() const {
	return m_defaultView;
}

FloatRect Window::getViewSpace() const {
	return m_view.getViewSpace();
}

void Window::setView(const View& view) {
	m_view = view;
}

} // namespace fl
