#include <string>
#include "SDL_ttf.h"
#include "utils.hxx"

bool initTTF()
{
    if (TTF_Init() != 0)
    {
        logSDLError("TTF_Init");
        return false;
    }
    return true;
}

TTF_Font *loadFont(const std::string &filename, int fontSize)
{
    std::string path{getResourceDirectory() + filename};
    TTF_Font *font = TTF_OpenFont(path.c_str(), fontSize);
    if (font == nullptr)
        logSDLError("TTF_OpenFont");
    return font;
}

SDL_Surface *loadText(const std::string &text, SDL_Color color, TTF_Font *font)
{
    SDL_Surface *surf = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surf == nullptr)
        logSDLError("TTF_RenderText_Solid");
    return surf;
}

SDL_Texture *loadText(const std::string &text, SDL_Color color, TTF_Font *font, SDL_Renderer *ren)
{
    SDL_Surface *surf = loadText(text, color, font);
    if (surf == nullptr)
        return nullptr;

    SDL_Texture *texture = adaptSurface(surf, ren);
    cleanup(surf);

    return texture;
}

void cleanup(TTF_Font *font)
{
    if (!font)
        return;
    TTF_CloseFont(font);
}