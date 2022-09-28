#ifndef INPUT_H
#define INPUT_H
#include "core.h"
#include "transform.h"

extern const Uint8 *keyState;

const int Key_Up = 0;
const int Key_Down = 1;
const int Key_Left = 2;
const int Key_Right = 3;
const int Key_Space = 4;

bool isKeyHeld(int key);

Transform getMousePosition();

#endif
