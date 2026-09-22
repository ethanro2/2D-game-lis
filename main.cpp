#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "src/game.h"


Game *game = nullptr;

int main(int argc, char* argv[])
{

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();
    game->init("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    //FULLSCREEN CURRENTLY SET TO FALSE FOR DEV PURPOSES. CHANGE IN FINAL VERSION!!!

    //Game Loop
    while(game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->clean();
    return 0;
};