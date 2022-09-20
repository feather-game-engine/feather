#include "core.h"
#include "input.h"
#include "../PROJECT.h"

bool running = true;
SDL_Window *win = NULL;
SDL_Renderer *rend = NULL;
SDL_Event event;

Mix_Music *currentMusic;

TTF_Font *font;

const Uint8 *keyState;

double delta = 0;
Uint64 lastFrame = SDL_GetPerformanceCounter();
Uint64 currentFrame = 0;

int main(){
	std::cout << "Starting Feather" << std::endl;

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG || IMG_INIT_JPG);
	TTF_Init();
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	std::cout << "Initialising SDL" << std::endl;

	win = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DEFAULT_WIDTH, DEFAULT_HEIGHT, 0);
	if(win == NULL){
		std::cout << "Error -1. Failed to create window." << std::endl;
		return -1;
	}
	std::cout << "Window created" << std::endl;

	rend = SDL_CreateRenderer(win, -1, 0);
	if(rend == NULL){
		std::cout << "Error -2. Failed to create rendering context." << std::endl;
		return -2;
	}
	std::cout << "Rendering context created" << std::endl;

	font = TTF_OpenFont("feather/FreeSans.ttf", 25);
	std::cout << "Font loaded" << std::endl;

	SDL_SetRenderDrawColor(rend, 81, 144, 245, 255);

	Begin();

	while(running){
		lastFrame = currentFrame;
		currentFrame = SDL_GetPerformanceCounter();
		delta = (double)((currentFrame - lastFrame)*1000/(double)SDL_GetPerformanceFrequency());

		SDL_PollEvent(&event);
		keyState = SDL_GetKeyboardState(NULL);

		if(event.type == SDL_QUIT){
			running = false;
		}

		SDL_RenderClear(rend);

		onFrame();

		SDL_RenderPresent(rend);
	}

	End();

	std::cout << "Stopping Music" << std::endl;
	Mix_HaltMusic();
	Mix_FreeMusic(currentMusic);

	std::cout << "Destroying rendering context" << std::endl;
	SDL_DestroyRenderer(rend);

	std::cout << "Destroying window" << std::endl;
	SDL_DestroyWindow(win);

	std::cout << "Destroying font" << std::endl;
	TTF_CloseFont(font);

	std::cout << "Exiting game" << std::endl;
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	std::cout << "Feather Shutdown" << std::endl;
	return 0;
}
