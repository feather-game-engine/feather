#include <feather/components/keyboardcontrol.h>
#include <feather/entities/entity.h>

namespace fl {

KeyboardControl::KeyboardControl(Entity* owner) :
	Component(owner)
{

}

void KeyboardControl::bindOnKeyActive(SDL_Keycode key, KeyAction action) {
	if(m_keyHeldActions.contains(key)) {
		m_keyHeldActions.at(key).push_back(action);
	}
	else {
		m_keyHeldActions.insert(std::make_pair(key, std::vector<KeyAction>{action}));
	}
}

void KeyboardControl::bindOnKeyReleased(SDL_Keycode key, KeyAction action) {
	if (m_keyReleasedActions.contains(key)) {
		m_keyReleasedActions.at(key).push_back(action);
	}
	else {
		m_keyReleasedActions.insert(std::make_pair(key, std::vector<KeyAction>{action}));
	}
}

void KeyboardControl::bindOnKeyPressed(SDL_Keycode key, KeyAction action) {
	if (m_keyPressedActions.contains(key)) {
		m_keyPressedActions.at(key).push_back(action);
	}
	else {
		m_keyPressedActions.insert(std::make_pair(key, std::vector<KeyAction>{action}));
	}
}

const KeyBindings& KeyboardControl::getBindingsOnKeyPressed() const {
	return m_keyPressedActions;
}

const KeyBindings& KeyboardControl::getBindingsOnKeyReleased() const {
	return m_keyReleasedActions;
}

const KeyBindings& KeyboardControl::getBindingsOnKeyHeld() const {
	return m_keyHeldActions;
}


} // namespace fl