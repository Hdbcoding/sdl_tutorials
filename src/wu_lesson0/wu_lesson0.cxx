#include <iostream>
#include "SDL.h"
#include "utils.hxx"

int main(int, char**)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        logSDLError("SDL_Init");
        return 1;
    }

    SDL_Quit();
    
    return 0;
}