#pragma once

#include "SDL.h"

class Input
{
private:
    bool quit;
    SDL_Keycode lastKey{SDLK_UNKNOWN};
    SDL_Event lastEvent{};

public:
    const bool didQuit() const;
    const SDL_Keycode getLastKey() const;
    SDL_Event getLastEvent() const;
    void clearLastKey();
    void clearLastEvent();
    void poll();
};