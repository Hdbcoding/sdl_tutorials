#include <string>
#include "SDL_ttf.h"
#include "utils.hxx"

TTF_Font *loadFont(const std::string &filename, int fontSize)
{
    std::string path{getResourceDirectory() + filename};
    TTF_Font *font = TTF_OpenFont(filename.c_str(), fontSize);
    if (font == nullptr)
        logSDLError("TTF_OpenFont");
    return font;
}

SDL_Texture *loadText(const std::string &text, SDL_Color color, TTF_Font *font, SDL_Renderer *ren)
{
    SDL_Surface *surf = TTF_RenderText_Solid(font, text.c_str(), color);

    if (surf == nullptr)
    {
        logSDLError("TTF_RenderText_Solid");
        return nullptr;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, surf);
    cleanup(surf);

    if (texture == nullptr)
        logSDLError("SDL_CreateTextureFromSurface");

    return texture;
}