#pragma once

#include <functional>
#include <memory>
#include <unordered_map>
#include <vector>
#include <feather/components/component.h>
#include <feather/systems/inputmanager.h>

namespace fl {

using KeyAction = std::function<void(void)>;

using KeyBindings = std::unordered_map<SDL_Keycode, std::vector<KeyAction>>;


class KeyboardControl : public Component {
public:
	KeyboardControl(Entity* owner);

	void bindOnKeyActive(SDL_Keycode key, KeyAction action);
	void bindOnKeyReleased(SDL_Keycode key, KeyAction action);
	void bindOnKeyPressed(SDL_Keycode key, KeyAction action);

	const KeyBindings& getBindingsOnKeyPressed() const;
	const KeyBindings& getBindingsOnKeyReleased() const;
	const KeyBindings& getBindingsOnKeyHeld() const;

private:
	KeyBindings 	m_keyPressedActions;
	KeyBindings 	m_keyHeldActions;
	KeyBindings 	m_keyReleasedActions;
}; // class KeyboardControl


} // namespace fl