#include "Feather/Game.h"
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
    context.inputs = &im;
}

void Game::loop() {
    const float countPerSecond = SDL_GetPerformanceFrequency();
    const float timePerFrame = countPerSecond / m_fps;

    std::uint64_t NOW = SDL_GetPerformanceCounter();
    std::uint64_t PREV = 0;
    std::uint64_t elapsedTime = 0;

    do {
        PREV = NOW;
        NOW = SDL_GetPerformanceCounter();
        elapsedTime = NOW - PREV;
        while(elapsedTime < timePerFrame) {
            NOW = SDL_GetPerformanceCounter();
            elapsedTime = NOW - PREV;
        }
        float deltaTime = elapsedTime / static_cast<float>(countPerSecond);

        this->handleEvents();
        if(win.isOpen()) {
            this->update(deltaTime);
            this->postUpdate(deltaTime);
            this->draw();
        }
    
    } while(win.isOpen());
}

void Game::handleEvents() {
    SDL_PumpEvents();
    win.handleEvents();
    im.handleEvents();
}


void Game::update(float deltaTime) {
    em.update(deltaTime);
}

void Game::postUpdate(float deltaTime) {
    em.postUpdate(deltaTime);
}

void Game::draw() {
    win.clear(m_clearColor);
    em.draw(win);
    win.display();
}

void Game::quit() {
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Game::changeClearColor(fl::Color c) {
    m_clearColor = c;
}

}
