#include "Feather/ResourceManager.h"
#include <SDL2/SDL_mixer.h>
#include <stdexcept>

namespace fl {
ResourceManager::ResourceManager(SDL_Renderer* rend) 
	: renderer(rend)
{

}

void ResourceManager::setRenderer(SDL_Renderer* rend) {
	renderer = rend;
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
	if (texturesMap.contains(id))
		return texturesMap.at(id);
	return nullptr;
}

TTF_Font* ResourceManager::getFont(unsigned int id) const {
	if (fontsMap.contains(id))
		return fontsMap.at(id);
	return nullptr;
}

Mix_Chunk* ResourceManager::getSound(unsigned int id) const {
	if (soundsMap.contains(id))
		return soundsMap.at(id);
	return nullptr;
}

} // namespace fl
