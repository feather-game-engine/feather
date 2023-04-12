#ifndef TEXT_H
#define TEXT_H
#include "core.h"

extern TTF_Font *font;

int drawText(std::string s, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int x, int y);

#endif
