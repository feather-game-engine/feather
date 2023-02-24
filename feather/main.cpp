#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "feather/components/transform.h"
#include "feather/components/sprite.h"
#include "feather/entities/entity.h"
#include "feather/entities/sharedcontext.h"
#include "feather/systems/entitymanager.h"
#include "feather/resourcemanager.h"
#include "feather/window.h"

namespace {
	int init() {
		if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
			std::cout << "SDL cannot be initialized. Got Error: " << SDL_GetError() << std::endl;
			return -1;
		}
		int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
		if(!(IMG_Init(imgFlags) & imgFlags)) {
			std::cout << "SDL_image cannot be initialized. Caught Error: " << IMG_GetError() << std::endl;
			return -2;
		}
		if(TTF_Init() < 0) {
			std::cout << "SDL_ttf cannot be initialized. Caught Error: " << TTF_GetError() << std::endl;
			return -3;
		}

		std::cout << "SDL initialized successfully." << std::endl;
		return 0;
	}

	int close() {
		TTF_Quit();
		IMG_Quit();
		SDL_Quit();

		return 0;
	}
}
	

int main(int argc, char* argv[]) {
	bool initialized = (init() == 0);
	if (!initialized) {
		std::cout << "SDL Initialization returned with an error. Terminating Program." << std::endl;
		return -1;
	}


	fl::EntityManager entityManager;
	fl::Window gameWindow("FEATHER GAME ENGINE - TEST RUN");
	fl::ResourceManager resources(gameWindow.getRenderer());

	fl::SharedContext context{
		&entityManager,
		&resources,
		&gameWindow
	};

	std::shared_ptr<fl::Entity> entity = std::make_shared<fl::Entity>(&context);

	auto transform = entity->addComponent<fl::Transform>();
	auto sprite = entity->addComponent<fl::Sprite>();
	transform->position.x = 64;
	transform->position.y = 64;

	sprite->loadTextureFromFile("./player.png");

	entityManager.add(entity);


	// START GAME LOOP

	std::uint64_t NOW = SDL_GetPerformanceCounter();
	std::uint64_t LAST = 0;
	float deltaTime = 0;
	
	do {
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();

		deltaTime = static_cast<float>((NOW - LAST)*1000 / static_cast<float>(SDL_GetPerformanceFrequency()));

		// Handle Events
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				gameWindow.close();
			}
		}
		if (gameWindow.isOpen()) {
			entityManager.update(deltaTime);
			entityManager.postUpdate(deltaTime);
			gameWindow.clear();
			entityManager.draw(gameWindow);
			gameWindow.display();
		}

	} while(gameWindow.isOpen());


	return close();
}