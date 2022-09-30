#include "input.h"

bool isKeyHeld(int key){
	switch(key){
		case 0:
			if(keyState[SDL_SCANCODE_UP]){
				return true;
			}
			break;
		case 1:
			if(keyState[SDL_SCANCODE_DOWN]){
				return true;
			}
			break;
		case 2:
			if(keyState[SDL_SCANCODE_LEFT]){
				return true;
			}
			break;
		case 3:
			if(keyState[SDL_SCANCODE_RIGHT]){
				return true;
			}
			break;
		case 4:
			if(keyState[SDL_SCANCODE_SPACE]){
				return true;
			}
			break;
	}
	return false;
}

Vector getMousePosition(){
	Vector mousePosition;
	int x = static_cast<int>(mousePosition.x);
	int y = static_cast<int>(mousePosition.y);

	SDL_GetMouseState(&x, &y);
	return mousePosition;
}
