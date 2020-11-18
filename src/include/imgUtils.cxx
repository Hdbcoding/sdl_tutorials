#include "SDL.h"
#include "SDL_image.h"
#include "utils.hxx"

SDL_Surface *loadImage(const std::string &filename)
{
    std::string path{getResourceDirectory() + filename};
    SDL_Surface *image = IMG_Load(path.c_str());
    if (image == nullptr)
        logSDLError("IMG_Load");
    return image;
}

SDL_Surface *loadImageOptimized(const std::string &filename, const SDL_Surface *source)
{
    SDL_Surface *image = loadImage(filename);
    SDL_Surface *optimized{nullptr};
    if (image != nullptr)
    {
        optimized = SDL_ConvertSurface(image, source->format, 0);
        if (optimized == nullptr)
        {
            logSDLError("SDL_ConvertSurface");
        }
        SDL_FreeSurface(image);
    }
    return optimized;
}

SDL_Texture *loadImageTexture(const std::string &filename, SDL_Renderer *ren)
{
    SDL_Texture *tex = nullptr;

    SDL_Surface *surf = loadImage(filename);
    if (surf == nullptr)
        return tex;

    tex = SDL_CreateTextureFromSurface(ren, surf);
    cleanup(surf);

    if (tex == nullptr)
        logSDLError("SDL_CreateTextureFromSurface");

    return tex;
}