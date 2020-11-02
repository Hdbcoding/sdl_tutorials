#include <SDL2.h>
#include <iostream>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int, char**)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL Init error: " << SDL_GetError() << std::endl;
        return 0;
    }

    SDL_Quit();
    
    return 0;
}