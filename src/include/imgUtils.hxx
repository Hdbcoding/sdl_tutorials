#pragma once
#include <string>
#include "SDL.h"

SDL_Surface *loadImage(const std::string &filename);
SDL_Surface *loadImageOptimized(const std::string &filename, const SDL_Surface *source);