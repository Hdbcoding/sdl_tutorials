#pragma once

#include <iostream>
#include "SDL.h"

#ifdef _WIN32
const char PATH_SEP = '\\';
#else
const char PATH_SEP = '/';
#endif

std::string getRootDirectory();

std::string getResourceDirectory();

void logSDLError(const std::string &message);

void logSDLError(std::ostream &out, const std::string &message);

SDL_Window *createWindow(int width, int height, std::string name = "Tutorial");

SDL_Renderer *createRenderer(SDL_Window *win);

SDL_Surface *loadBMP(const std::string &filename);

SDL_Surface *loadBMPOptimized(const std::string &filename, const SDL_Surface *source);

SDL_Texture *adaptSurface(SDL_Surface *surf, SDL_Renderer *ren);

template <typename T, typename... Args>
void cleanup(T *t, Args &&... args)
{
    cleanup(t);
    cleanup(std::forward<Args>(args)...);
}

template <>
inline void cleanup<SDL_Window>(SDL_Window *win)
{
    if (!win)
        return;
    SDL_DestroyWindow(win);
}

template <>
inline void cleanup<SDL_Renderer>(SDL_Renderer *ren)
{
    if (!ren)
        return;
    SDL_DestroyRenderer(ren);
}

template <>
inline void cleanup<SDL_Texture>(SDL_Texture *tex)
{
    if (!tex)
        return;
    SDL_DestroyTexture(tex);
}

template <>
inline void cleanup<SDL_Surface>(SDL_Surface *surf)
{
    if (!surf)
        return;
    SDL_FreeSurface(surf);
}