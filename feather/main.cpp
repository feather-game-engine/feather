#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <feather/components/keyboardcontrol.h>
#include <feather/components/transform.h>
#include <feather/components/sprite.h>
#include <feather/components/soundemitter.h>
#include <feather/components/velocity.h>
#include <feather/entities/entity.h>
#include <feather/entities/sharedcontext.h>
#include <feather/systems/entitymanager.h>
#include <feather/systems/keyboardcontrolsystem.h>
#include <feather/systems/movementsystem.h>
#include <feather/resourcemanager.h>
#include <feather/windows/window.h>
#include <feather/game.h>

int main(int argc, char* argv[]) {

    fl::Game game(std::string("Game Window"));

	std::shared_ptr<fl::Entity> entity = std::make_shared<fl::Entity>(&game.context);

	auto transform = entity->addComponent<fl::Transform>();
	auto sprite = entity->addComponent<fl::Sprite>();
    auto sfx = entity->addComponent<fl::SoundEmitter>();
	transform->setPosition({64, 64});

	sprite->loadTextureFromFile("./player.png");
    sfx->loadSoundFromFile("./track02.wav");

	auto v = entity->addComponent<fl::Velocity>();
	auto kc = entity->addComponent<fl::KeyboardControl>();

	kc->bindOnKeyPressed(SDLK_w, std::bind([v](){
		v->setY(-32.f);
	}));

	kc->bindOnKeyPressed(SDLK_s, std::bind([v](){
		v->setY(32.f);
	}));

	kc->bindOnKeyPressed(SDLK_a, std::bind([v](){
		v->setX(-32.f);
	}));

	kc->bindOnKeyPressed(SDLK_d, std::bind([v](){
		v->setX(32.f);
	}));


	game.em.includeSystem<fl::KeyboardControlSystem>();
	game.em.includeSystem<fl::MovementSystem>();
	

	game.em.add(entity);

	// START GAME LOOP

    sfx->play();

    do {
		game.update();
		game.handleEvents();
	} while(game.win.isOpen());

    game.quit();
	return 0;
}
