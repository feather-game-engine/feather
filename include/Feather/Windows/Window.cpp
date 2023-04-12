#include <Feather/Windows/Window.h>

namespace fl {

Window::Window(const std::string& title, int x, int y, int w, int h, std::uint32_t flags) :
	m_title(title),
	m_area(x,y,w,h),
	m_flags(flags),
	m_defaultView({
		0.f, 0.f,
		static_cast<float>(w),
		static_cast<float>(h)
	}),
	m_view(m_defaultView)
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

void Window::handleEvents() {
	SDL_Event e[1];
	while(SDL_PeepEvents(e, 1, SDL_GETEVENT, SDL_WINDOWEVENT, SDL_WINDOWEVENT) > 0) {
		switch(e[0].window.event) {
			case SDL_WINDOWEVENT_FOCUS_LOST:
				// Pause the game
				break;
			case SDL_WINDOWEVENT_FOCUS_GAINED:
				// Resume the game
				break;
            case SDL_WINDOWEVENT_SIZE_CHANGED:
                // Handle window resizes
                m_area.w = e[0].window.data1;
                m_area.h = e[0].window.data2;
                display();
                break;
			case SDL_WINDOWEVENT_CLOSE:
				this->close();
				return; // Terminate function. No need to handle other events.
		}
	}

	if(SDL_PeepEvents(e, 1, SDL_GETEVENT, SDL_QUIT, SDL_QUIT) > 0) {
		this->close();
	}
}

void Window::clear(fl::Color color) {
	SDL_SetRenderDrawColor( m_renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(m_renderer);
}

namespace {
	SDL_RendererFlip getFlip(const IntRect& rect) {
		SDL_RendererFlip flip = SDL_FLIP_NONE;
		if(rect.w < 0) {
			flip = SDL_FLIP_HORIZONTAL;
		}
		else if (rect.h < 0) {
			flip = SDL_FLIP_VERTICAL;
		}
		return flip;
	}
}

void Window::draw(SDL_Texture* texture, const fl::FloatRect& textureRect, const fl::FloatRect& destRect) {
	SDL_RendererFlip flip = getFlip(textureRect);
	// Convert world coordinates to screen coordinates.
	SDL_Rect screenCoordsRect = m_view.mapToView(destRect).toSDL_Rect();
	SDL_Rect textureSDLRect = textureRect.toSDL_Rect();

	int error = SDL_RenderCopyEx(m_renderer, texture, &textureSDLRect, &screenCoordsRect, 0, NULL, flip);
	if(error != 0) {
		throw std::runtime_error(SDL_GetError());
	}
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
