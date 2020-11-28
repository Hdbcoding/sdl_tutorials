#pragma once

#include <string>
#include "SDL.h"
#include "LFont.hxx"

class LTextTexture {
    SDL_Texture *text{nullptr};
    int width{0};
    int height{0};

public:
    ~LTextTexture();
    void free();

    bool loadFromText(const std::string &text, SDL_Color color, LFont *font, SDL_Renderer *ren);
    void render(SDL_Renderer *ren, int x, int y);
    const int getWidth() const;
    const int getHeight() const;
};