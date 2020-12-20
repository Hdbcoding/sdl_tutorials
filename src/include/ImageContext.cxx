#include "SDL_image.h"
#include "imgUtils.hxx"
#include "ImageContext.hxx"

ImageContext::~ImageContext()
{
    this->free();
}

void ImageContext::free()
{
    IMG_Quit();
}

bool ImageContext::startup(Uint32 flags)
{
    return initIMGPng();
}