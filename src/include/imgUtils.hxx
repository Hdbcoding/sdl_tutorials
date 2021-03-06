#pragma once

#include <string>
#include "SDL.h"
#include "SDL_image.h"

bool initIMGPng(Uint32 flags = IMG_INIT_PNG);
SDL_Surface *loadImage(const std::string &filename);
SDL_Surface *loadImageOptimized(const std::string &filename, const SDL_Surface *source);
SDL_Texture *loadImageTexture(const std::string &filename, SDL_Renderer *ren);