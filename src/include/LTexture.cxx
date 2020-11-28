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
    Uint32 key = SDL_MapRGB(surf->format, 0, 0xFF, 0xFF);
    SDL_SetColorKey(surf, SDL_TRUE, key);

    this->texture = SDL_CreateTextureFromSurface(ren, surf);
    cleanup(surf);
    if (this->texture == nullptr)
        return false;

    this->width = surf->w;
    this->height = surf->h;

    return this->texture != nullptr;
}

void LTexture::render(SDL_Renderer *ren, int x, int y, SDL_Rect *clip)
{
    SDL_Rect quad{x, y, this->width, this->height};

    if (clip != nullptr)
    {
        quad.w = clip->w;
        quad.h = clip->h;
    }

    SDL_RenderCopyEx(ren, this->texture, clip, &quad, this->rotation, nullptr, this->flipType);
}

const int LTexture::getWidth() const
{
    return this->width;
}

const int LTexture::getHeight() const
{
    return this->height;
}

void LTexture::setColorModulation(Uint8 r, Uint8 g, Uint8 b)
{
    SDL_SetTextureColorMod(this->texture, r, g, b);
}

void LTexture::setBlendMode(SDL_BlendMode blending)
{
    SDL_SetTextureBlendMode(this->texture, blending);
}

void LTexture::setAlpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod(this->texture, alpha);
}

void LTexture::setRotation(double rotation)
{
    this->rotation = rotation;
}

void LTexture::setFlip(SDL_RendererFlip flip)
{
    this->flipType = flip;
}