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
    this->text = loadText(text, color, font->font, ren);

    return this->text != nullptr;
}

void LTextTexture::render(SDL_Renderer *ren, int x, int y)
{

}

const int LTextTexture::getWidth() const
{
    return this->width;
}

const int LTextTexture::getHeight() const
{
    return this->height;
}