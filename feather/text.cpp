#include "text.h"

int drawText(std::string s, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int x, int y){
	SDL_Color tcolor = { r, g, b, a };
	const char *text= s.c_str();
	SDL_Surface *image = TTF_RenderText_Solid(font, text, tcolor);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(rend, image);
	int sprw;
	int sprh;
	SDL_QueryTexture(texture, NULL, NULL, &sprw, &sprh);
	SDL_Rect dst = { x, y, sprw, sprh };
	SDL_RenderCopy(rend, texture, NULL, &dst);
	SDL_FreeSurface(image);
	SDL_DestroyTexture(texture);
	return 0;
}

/*char *i2s(int i){
	char *s;
	sprintf(s, "%d", i);
	return s;
}*/
