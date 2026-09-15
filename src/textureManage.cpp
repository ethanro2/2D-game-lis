#include "textureManage.h"

SDL_Texture* textureManager::LoadTexture(const char* texture, SDL_Renderer* ren){
    SDL_Surface* tempSurface = IMG_Load(texture);
    if(!tempSurface){
        SDL_Log("IMG_Load failed: %s", IMG_GetError());
        return nullptr;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
    if(!tex){
        SDL_Log("SDL_CreateTextureFromSurface failed: %s", SDL_GetError());
    }

    SDL_FreeSurface(tempSurface);

    return tex;

}