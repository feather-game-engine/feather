#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <Feather/Components/AnimationComponent.h>
#include <Feather/Components/KeyboardControl.h>
#include <Feather/Components/Transform.h>
#include <Feather/Components/Sprite.h>
#include <Feather/Components/SoundEmitter.h>
#include <Feather/Components/Velocity.h>
#include <Feather/Components/Collider.h>
#include <Feather/Entities/Entity.h>
#include <Feather/Entities/SharedContext.h>
#include <Feather/Systems/AnimationSystem.h>
#include <Feather/Systems/EntityManager.h>
#include <Feather/Systems/KeyboardControlSystem.h>
#include <Feather/Systems/MovementSystem.h>
#include <Feather/Systems/CollisionSystem.h>
#include <Feather/ResourceManager.h>
#include <Feather/Windows/Window.h>
#include <Feather/Game.h>

int main(int argc, char* argv[]) {
    fl::Game game(std::string("Game Window"));

	const fl::IDtype SKELETON_TEXTURE = game.rs.loadTexture("./Skeleton_Walk.png");

	std::shared_ptr<fl::Entity> entity = std::make_shared<fl::Entity>(&game.context);

	auto transform = entity->addComponent<fl::Transform>();
	auto sprite = entity->addComponent<fl::Sprite>();
    auto sfx = entity->addComponent<fl::SoundEmitter>();
	transform->setPosition({64, 64});

	sprite->loadTextureFromFile("./player.png");
    sfx->loadSoundFromFile("./track02.wav");

    auto hitbox = entity->addComponent<fl::Collider>();
    hitbox->setHitbox(64, 64);

	auto animation = entity->addComponent<fl::AnimationComponent>();
	int L = 0;
	const int T = 0;
	const int W = 22;
	const int H = 33;
	const float frameTime = 1.f / 12.f;
	const fl::IDtype walkRightID = 1;
	const fl::IDtype walkLeftID = 2;

	fl::Animation walkRightAnimation;
	walkRightAnimation.loop = true;
	while (L < 286) {
		fl::FrameData frame{
			SKELETON_TEXTURE,
			fl::IntRect{L, T, W, H},
			frameTime
		};
		walkRightAnimation.frames.push_back(frame);
		L += W;
	}

	fl::Animation walkLeftAnimation;
	walkLeftAnimation.loop = true;
	L = 22;
	while (L <= 286) {
		fl::FrameData frame{
			SKELETON_TEXTURE,
			fl::IntRect{L, T, -W, H},
			frameTime
		};
		walkLeftAnimation.frames.push_back(frame);
		L += W;
	}

	animation->addAnimation(walkRightID, walkRightAnimation);
	animation->addAnimation(walkLeftID, walkLeftAnimation);
	animation->setAnimation(walkRightID);

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
	kc->bindOnKeyPressed(SDLK_a, std::bind([animation, walkLeftID](){
		animation->setAnimation(walkLeftID);
	}));

	kc->bindOnKeyActive(SDLK_d, std::bind([v](){
		v->setX(248);
	}));
	kc->bindOnKeyPressed(SDLK_d, std::bind([animation, walkRightID](){
		animation->setAnimation(walkRightID);
	}));


	game.em.includeSystem<fl::AnimationSystem>();
	game.em.includeSystem<fl::KeyboardControlSystem>();
	game.em.includeSystem<fl::MovementSystem>();
    game.em.includeSystem<fl::CollisionSystem>();
	

	game.em.add(entity);
	// game.em.add(enemy);

	game.changeClearColor(fl::Color::Black);

	// START GAME LOOP

    sfx->play();

    game.loop();

    game.quit();
	return 0;
}
