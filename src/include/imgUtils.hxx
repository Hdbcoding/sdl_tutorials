#pragma once
#include <string>
#include "SDL.h"

bool initIMGPng();
SDL_Surface *loadImage(const std::string &filename);
SDL_Surface *loadImageOptimized(const std::string &filename, const SDL_Surface *source);
SDL_Texture *loadImageTexture(const std::string &filename, SDL_Renderer *ren);