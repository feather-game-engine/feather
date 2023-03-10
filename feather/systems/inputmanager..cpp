#include <feather/systems/inputmanager.h>

namespace fl {

void InputManager::handleEvents() {
	m_prevKeys = m_currKeys;
	m_currKeys.reset();

	SDL_Event e;
	while(SDL_PollEvent(&e)) {
		switch(e.type) {
			case SDL_KEYDOWN:
				SDL_Scancode code = SDL_GetScancodeFromKey(e.key.keysym.sym);
				m_currKeys.set(code);
				break;
		}
	}
}

bool InputManager::isKeyUp(SDL_KeyCode key) {
	SDL_Scancode code = SDL_GetScancodeFromKey(key);
	return m_prevKeys[code] && !m_currKeys[code];
}

bool InputManager::isKeyDown(SDL_KeyCode key) {
	SDL_Scancode code = SDL_GetScancodeFromKey(key);
	return m_currKeys[code];
}

bool InputManager::isKeyHeld(SDL_KeyCode key) {
	SDL_Scancode code = SDL_GetScancodeFromKey(key);
	return m_prevKeys[code] && m_currKeys[code];
}

Vector2i InputManager::getMousePos() const {
	Vector2i res;
	SDL_GetMouseState(&res.x, &res.y);

	return res;
}

} // namespace fl