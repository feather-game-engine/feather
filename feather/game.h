#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "feather/windows/window.h"
#include "feather/systems/entitymanager.h"
#include "feather/resourcemanager.h"
#include "feather/entities/sharedcontext.h"
#include "feather/utilities/color.h"

namespace fl {
  
class Game {
public:

    Game(const std::string& name);
    void update();
    void quit();

    fl::Window win;
    fl::EntityManager em;
    fl::ResourceManager rs;

	fl::SharedContext context;

    std::uint64_t NOW;
    std::uint64_t LAST;
    float deltaTime;
};

}
