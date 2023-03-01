#include "resourcemanager.h"
#include <SDL2/SDL_mixer.h>
#include <stdexcept>

namespace fl {
ResourceManager::ResourceManager(SDL_Renderer* rend) 
	: renderer(rend)
{

}

unsigned int ResourceManager::loadTexture(const std::string& path) {
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		throw std::invalid_argument(IMG_GetError());
	}

	newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
	if (newTexture == NULL) {
		throw std::runtime_error(SDL_GetError());
	}
	SDL_FreeSurface(loadedSurface);
	unsigned int id = ++textureCount;
	texturesMap.insert_or_assign(id, newTexture);
	
	return id;
}

unsigned int ResourceManager::loadFont(const std::string& path, int fontSize) {
	TTF_Font* newFont = TTF_OpenFont(path.c_str(), fontSize);
	if (newFont == NULL) {
		throw std::invalid_argument(TTF_GetError());
	}

	unsigned int id = ++fontCount;
	fontsMap.insert_or_assign(id,  newFont);

	return id;
}

unsigned int ResourceManager::loadSound(const std::string &path) {
    Mix_Chunk* newSound = Mix_LoadWAV(path.c_str());

    if (NULL == newSound) {
        throw std::invalid_argument(Mix_GetError());
    }

    unsigned int id = ++soundCount;
    soundsMap.insert_or_assign(id, newSound);

    return id;
}

SDL_Texture* ResourceManager::getTexture(unsigned int id) const {
	auto search = texturesMap.find(id);
	if (search == texturesMap.end())
		return NULL;
	return search->second;
}

TTF_Font* ResourceManager::getFont(unsigned int id) const {
	auto search = fontsMap.find(id);
	if (search == fontsMap.end())
		return NULL;
	return search->second;
}

Mix_Chunk* ResourceManager::getSound(unsigned int id) const {
    auto search = soundsMap.find(id);
    if (search == soundsMap.end())
        return NULL;
    return search->second;
}

} // namespace fl
