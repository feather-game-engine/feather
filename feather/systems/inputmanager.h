#pragma once

#include <bitset>
#include <SDL2/SDL_events.h>

#include <feather/utilities/vector2.hpp>

namespace fl {

class InputManager {
public:
	void handleEvents();

	bool isKeyUp(SDL_KeyCode key);
	bool isKeyDown(SDL_KeyCode key);
	bool isKeyHeld(SDL_KeyCode key);

	Vector2i getMousePos() const;
private:
	std::bitset<256> m_prevKeys;
	std::bitset<256> m_currKeys;

}; // class InputManager

} // namespace fl