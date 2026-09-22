#include "textureManage.h"
#include <iostream>

SDL_Texture* textureManager::LoadTexture(const char* texture, SDL_Renderer* ren) {
    if (!texture || !ren) {
        std::cerr << "Invalid texture path or renderer." << std::endl;
        return nullptr;
    }

    SDL_Surface* tempSurface = IMG_Load(texture);
    if (!tempSurface) {
        std::cerr << "Failed to load texture: " << texture << " - " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    if (!tex) {
        std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(tempSurface);
    return tex;
}