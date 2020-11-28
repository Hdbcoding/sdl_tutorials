#include <string>
#include "SDL.h"
#include "utils.hxx"
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

}