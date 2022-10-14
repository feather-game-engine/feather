#include "core.h"
#include "view.h"
#include "input.h"
#include "../PROJECT.h"
#include "vector.h"
#include "entity.h"
#include "rigidentity.h"
#include <unordered_map>

bool running = true;
SDL_Window *win = NULL;
SDL_Renderer *rend = NULL;
SDL_Event event;

bool paused;
bool f1;
bool f2;

Mix_Music *currentMusic;

TTF_Font *font;

const Uint8 *keyState;

double delta = 0;
Uint64 lastFrame = SDL_GetPerformanceCounter();
Uint64 currentFrame = 0;

int currentID;
std::unordered_map<int, Entity*> entityTracker;
bool drawHitboxes = false;

View view;

int main(int argc, char **argv){
	std::cout << "Starting Feather" << std::endl;

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG || IMG_INIT_JPG);
	TTF_Init();
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	std::cout << "Initialising SDL" << std::endl;

	std::string windowtitle;
	if(DEBUG_MODE){
		windowtitle = std::string(TITLE) + " (DEBUG MODE)";
		std::cout << "Debug mode is enabled" << std::endl;
	}
	else{
		windowtitle = TITLE;
	}

	win = SDL_CreateWindow(windowtitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DEFAULT_WIDTH, DEFAULT_HEIGHT, 0);
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

	srand((unsigned) time(0));
	std::cout << "RNG created" << std::endl;

	SDL_SetRenderDrawColor(rend, BG_COLOR[0], BG_COLOR[1], BG_COLOR[2], BG_COLOR[3]);

	Begin();

	Uint32 lastUpdate = SDL_GetTicks();

	while(running){
		lastFrame = currentFrame;
		currentFrame = SDL_GetPerformanceCounter();
		delta = (double)((currentFrame - lastFrame)*1000/(double)SDL_GetPerformanceFrequency());

		SDL_PollEvent(&event);
		keyState = SDL_GetKeyboardState(NULL);

		if(event.type == SDL_QUIT){
			running = false;
		}
		SDL_SetRenderDrawColor(rend, BG_COLOR[0], BG_COLOR[1], BG_COLOR[2], BG_COLOR[3]);
		SDL_RenderClear(rend);

		if(!paused){
			Step();
		}

		for(auto element : entityTracker){
			element.second->Draw();
			if (drawHitboxes && element.second->isActive() && dynamic_cast<RigidEntity*>(element.second)) {
				RigidEntity* re = dynamic_cast<RigidEntity*>(element.second);
				SDL_SetRenderDrawBlendMode(rend, SDL_BLENDMODE_BLEND);
				SDL_SetRenderDrawColor(rend, 0, 255, 0, 100);
				SDL_Rect target = { (int)re->transform.position.x + re->hitbox.x,(int)re->transform.position.y + re->hitbox.y, re->hitbox.w, re->hitbox.h };
				SDL_RenderFillRect(rend, &target);
			}
		}

		if(!paused){
			//PHYSICS
			Uint32 current = SDL_GetTicks();

			// Calculate deltaTime (in seconds)
			float deltaTime = (current - lastUpdate) / 1000.0f;

			//Loop through all rigid entities and make them Update() their position
			for(auto element : entityTracker){
				if(dynamic_cast<RigidEntity*>(element.second)) {
					RigidEntity *rigidEntity = dynamic_cast<RigidEntity*>(element.second);
					rigidEntity->Update(deltaTime);
				}
			}
			//END PHYSICS
			lastUpdate = current;
		}
		SDL_RenderPresent(rend);

		if(DEBUG_MODE){
			if(event.type == SDL_KEYDOWN){
				if(event.key.keysym.sym == SDLK_F1 && !f1){
					paused = !paused;
					f1 = true;
				}
				if (event.key.keysym.sym == SDLK_F2 && !f2) {
					f2 = true;
					drawHitboxes = !drawHitboxes;
				}
			}
			if(event.type == SDL_KEYUP){
				if(event.key.keysym.sym == SDLK_F1){
					f1 = false;
				}
				if (event.key.keysym.sym == SDLK_F2) {
					f2 = false;
				}
			}

		}

	}

	End();

	for(int i = 0; i < currentID; i++){
		entityTracker[i]->Destroy();
	}

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
