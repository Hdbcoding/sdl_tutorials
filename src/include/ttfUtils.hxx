#pragma once

#include "SDL_ttf.h"

TTF_Font *loadFont(const std::string &filename, int fontSize);
SDL_Texture *loadText(const std::string &text, SDL_Color color, TTF_Font *font, SDL_Renderer *ren);

inline void cleanup(TTF_Font *font)
{
    if (!font)
        return;
    TTF_CloseFont(font);
}