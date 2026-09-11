#pragma once

#include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class textureManager {
public:
    static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
};