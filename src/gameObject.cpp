#include "gameObject.h"
#include "textureManage.h"

gameObject::gameObject(const char* textureSheet, SDL_Renderer* ren, int startX, int startY)
{
    renderer = ren;
    objTexture = textureManager::LoadTexture(textureSheet, ren);
    x = startX;
    y = startY;
}

void gameObject::update()
{
    x++;
    y++;


    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = x;
    destRect.y = y;
    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void gameObject::render()
{
    SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}