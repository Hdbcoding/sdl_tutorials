#include <string>
#include "SDL.h"
#include "utils.hxx"
#include "ttfUtils.hxx"
#include "LTextTexture.hxx"

LTextTexture::~LTextTexture()
{
    this->free();
}

void LTextTexture::free()
{
    if (this->text != nullptr)
    {
        cleanup(this->text);
        this->text = nullptr;
        this->width = 0;
        this->height = 0;
    }
}

bool LTextTexture::loadFromText(const std::string &text, SDL_Color color, LFont *font, SDL_Renderer *ren)
{
    this->free();
    SDL_Surface *surf = loadText(text, color, font->font);
    if (surf != nullptr)
    {
        this->text = loadText(text, color, font->font, ren);
        if (this->text != nullptr)
        {
            this->width = surf->w;
            this->height = surf->h;
        }
        cleanup(surf);
    }
    return this->text != nullptr;
}

void LTextTexture::render(SDL_Renderer *ren, int x, int y)
{
    SDL_Rect quad{x, y, this->width, this->height};
    SDL_RenderCopy(ren, this->text, nullptr, &quad);
}

const int LTextTexture::getWidth() const
{
    return this->width;
}

const int LTextTexture::getHeight() const
{
    return this->height;
}