#include "game.h"
#include <SDL2/SDL_timer.h>

namespace fl {

Game::Game(const std::string& name) :
    win(name),
    rs(NULL)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL cannot be initialized. Got Error: " << SDL_GetError() << std::endl;
        return;
    }
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if(!(IMG_Init(imgFlags) & imgFlags)) {
        std::cout << "SDL_image cannot be initialized. Caught Error: " << IMG_GetError() << std::endl;
        return;
    }
    if(TTF_Init() < 0) {
        std::cout << "SDL_ttf cannot be initialized. Caught Error: " << TTF_GetError() << std::endl;
        return;
    }
    if(Mix_Init(MIX_INIT_MP3) < 0) {
        std::cout << "SDL_mixer cannot be initialised. Caught error: " << Mix_GetError() << std::endl;
        return;
    }

    std::cout << "SDL initialized successfully." << std::endl;
     //open audio, temporary solution until proper audio system is created
     Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048);

    // actually start the window.
    win.init();
    rs.setRenderer(win.getRenderer());

    context.entities = &em;
    context.resources = &rs;
    context.window = &win;

    NOW = SDL_GetPerformanceCounter();
}

void Game::update() {
    LAST = NOW;
    NOW = SDL_GetPerformanceCounter();

    deltaTime = static_cast<float>((NOW - LAST)*1000 / static_cast<float>(SDL_GetPerformanceFrequency()));

    em.update(deltaTime);
    em.postUpdate(deltaTime);
    win.clear(fl::Color::Cyan);
    em.draw(win);
    win.display();
}

void Game::quit() {
    win.close();
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::changeClearColor(fl::Color c) {
    clearColor = c;
}

}
