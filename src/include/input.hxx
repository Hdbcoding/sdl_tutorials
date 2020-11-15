#pragma once
#include "SDL.h"

class Input
{
private:
    bool quit;
    SDL_Keycode lastKey{SDLK_UNKNOWN};
public:
    const bool didQuit();
    const SDL_Keycode getLastKey();
    void poll();
};