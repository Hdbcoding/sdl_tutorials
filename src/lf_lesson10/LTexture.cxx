#include "LTexture.hxx"
#include "utils.hxx"
#include "imgUtils.hxx"

LTexture::~LTexture()
{
    this->free();
}

void LTexture::free()
{
    if (this->texture != nullptr)
    {
        cleanup(this->texture);
        this->width = 0;
        this->height = 0;
    }
}

bool LTexture::loadFromFile(const std::string &filename, SDL_Renderer *ren)
{
    this->free();
    SDL_Surface *surf = loadImage(filename);
    if (surf == nullptr)
        return false;

    // assume cyan color key for opacity
    SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 0, 0xFF, 0xFF));
    this->texture = SDL_CreateTextureFromSurface(ren, surf);
    cleanup(surf);
    if (this->texture == nullptr)
        return false;

    this->width = surf->w;
    this->height = surf->h;

    return this->texture != nullptr;
}

void LTexture::render(SDL_Renderer *ren, int x, int y)
{
    SDL_Rect quad{x, y, this->width, this->height};
    SDL_RenderCopy(ren, this->texture, nullptr, &quad);
}

int LTexture::getWidth()
{
    return this->width;
}

int LTexture::getHeight()
{
    return this->height;
}