#pragma once

#include "SDL.h"
#include "SDL_image.h"

struct RenderingContext
{
    int SCREEN_WIDTH{640};
    int SCREEN_HEIGHT{480};
    SDL_Window *win{nullptr};
    SDL_Renderer *ren{nullptr};

    ~RenderingContext();
    void free();
    bool startup(Uint32 sdlFlags = SDL_INIT_VIDEO, Uint32 imgFlags = IMG_INIT_PNG);
};