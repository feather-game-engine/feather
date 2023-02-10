#pragma once
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

namespace Feather {

class ResourceManager {
public: // Methods and Constructors
	ResourceManager() = delete;
	ResourceManager(SDL_Renderer* rend);

	/**
	 * loadTexture()
	 * - Creates an SDL_Texture* object from path and stores it into memory. 
	 * Returns the id of the loaded SDL_Texture for future access.
	*/
	unsigned int loadTexture(const std::string& path);
	/**
	 * loadFont()
	 * - Creates a TTF_Font* object from path and stores it into memory.
	 * Returns the id of the loaded TTF_Font for future access.
	*/
	unsigned int loadFont(const std::string& path, int fontSize);

	/**
	 * getTexture()
	 * - Returns a pointer to SDL_Texture referred to by given id. Returns NULL for invalid id.
	*/
	SDL_Texture* getTexture(unsigned int id) const;

	/**
	 * getFont()
	 * - Returns a pointer to TTF_Font referred to by given id. Returns NULL  for invalid id.
	*/
	TTF_Font* getFont(unsigned int id) const;

private:
	std::unordered_map<unsigned int, SDL_Texture*> texturesMap;
	unsigned int textureCount = 0;
	std::unordered_map<unsigned int, TTF_Font*> fontsMap;
	unsigned int fontCount = 0;
	// TODO: Map for audios/musics


	SDL_Renderer* renderer;
}; // class ResourceHolder

} // namespace Feather