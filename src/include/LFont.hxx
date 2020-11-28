#pragma once

#include <string>
#include "SDL.h"
#include "SDL_ttf.h"

struct LFont
{
    TTF_Font *font{nullptr};
    
    ~LFont();
    void free();

    bool loadFromFile(const std::string &filename, int fontSize);
};