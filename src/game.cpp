#include "game.h"
#include <iostream>
#include <SDL2/SDL_image.h>
#include "textureManage.h"
#include "gameObject.h"

gameObject* player;


Game::Game(){

}
Game::~Game(){
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen){
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystems Initialized" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window)
        {
            std::cout << "window Created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer Created" << std::endl;
        }

        isRunning = true;
        
   }
   else{
            isRunning = false;
        }
        player = new gameObject("assets/player.png", renderer, 0, 0);
       
    }

 void Game::handleEvents()
 {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
    case SDL_QUIT:
        isRunning = false;
        break;
    
    default:
        break;
    }

 }
void Game::update()
{
    player->update();
}
void Game::render(){
    SDL_RenderClear(renderer);
    //Add stuff to render
    player->render();
    //End render stuff
    SDL_RenderPresent(renderer);
}
void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std:: cout << "Game Cleaned" << std::endl;
}
    
bool Game::running(){
    return isRunning; 
}
