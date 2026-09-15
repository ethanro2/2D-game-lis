#pragma once
#include "game.h"


class gameObject {
    public: 
        gameObject(const char* textureSheet, SDL_Renderer* ren, int startX, int startY);
        ~gameObject();

        void update();
        void render();
        
    private:
        int x;
        int y;

        SDL_Texture* objTexture;
        SDL_Rect srcRect, destRect;
        SDL_Renderer* renderer;

};      