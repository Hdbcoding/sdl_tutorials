#pragma once

#include "SDL.h"
#include "SDL_image.h"

struct ImageContext 
{
    ~ImageContext();
    void free();
    bool startup(Uint32 flags = IMG_INIT_PNG);
};