#pragma once

#include "SDL.h"

struct RenderingContext
{
    int SCREEN_WIDTH{640};
    int SCREEN_HEIGHT{480};
    SDL_Window *win{nullptr};
    SDL_Renderer *ren{nullptr};

    ~RenderingContext();
    void free();
    bool startup(Uint32 flags = SDL_INIT_VIDEO);
};