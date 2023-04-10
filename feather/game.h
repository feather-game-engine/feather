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

    void loop();

    void setFrameRateLimit(float fps);
    void changeClearColor(fl::Color c);
    void quit();
protected:
    void handleEvents();
    void update(float deltaTime);
    void postUpdate(float deltaTime);
    void draw();

public:
    fl::Window win;
    fl::EntityManager em;
    fl::ResourceManager rs;
    fl::InputManager im;

	fl::SharedContext context;

    

private:
    float m_fps{60.f};
    fl::Color m_clearColor = fl::Color::Cyan;
};

}
