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
#include <feather/components/collider.h>
#include <feather/entities/entity.h>
#include <feather/entities/sharedcontext.h>
#include <feather/systems/entitymanager.h>
#include <feather/systems/keyboardcontrolsystem.h>
#include <feather/systems/movementsystem.h>
#include <feather/systems/collisionsystem.h>
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

    auto hitbox = entity->addComponent<fl::Collider>();
    hitbox->setHitbox(64, 64);

	auto v = entity->addComponent<fl::Velocity>();
	auto kc = entity->addComponent<fl::KeyboardControl>();

	kc->bindOnKeyActive(SDLK_w, std::bind([v](){
		v->setY(-248);
	}));

	kc->bindOnKeyActive(SDLK_s, std::bind([v](){
		v->setY(248);
	}));

	kc->bindOnKeyActive(SDLK_a, std::bind([v](){
		v->setX(-248);
	}));

	kc->bindOnKeyActive(SDLK_d, std::bind([v](){
		v->setX(248);
	}));


	// std::shared_ptr<fl::Entity> enemy = std::make_shared<fl::Entity>(&game.context);
	// auto transform_enemy = enemy->addComponent<fl::Transform>();
	// auto sprite_enemy = enemy->addComponent<fl::Sprite>();
	// transform_enemy->setPosition({256, 64});

	// sprite_enemy->loadTextureFromFile("./enemy.png");

    // auto hitbox_enemy = enemy->addComponent<fl::Collider>();
    // hitbox_enemy->setHitbox(64, 64);


	game.em.includeSystem<fl::KeyboardControlSystem>();
	game.em.includeSystem<fl::MovementSystem>();
    game.em.includeSystem<fl::CollisionSystem>();
	

	game.em.add(entity);
	// game.em.add(enemy);

	// START GAME LOOP

    sfx->play();

    game.loop();

    game.quit();
	return 0;
}
