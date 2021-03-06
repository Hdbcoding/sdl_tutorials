#include "SDL.h"
#include "SDL_image.h"
#include "utils.hxx"
#include "imgUtils.hxx"
#include "RenderingContext.hxx"

RenderingContext::~RenderingContext()
{
    this->free();
}

void RenderingContext::free()
{
    cleanup(this->ren, this->win);
    this->ren = nullptr;
    this->win = nullptr;
    IMG_Quit();
    SDL_Quit();
}

bool RenderingContext::startup(Uint32 sdlFlags, Uint32 imgFlags)
{
    // todo - sdl init management to its own class?
    if (SDL_Init(sdlFlags) != 0)
    {
        logSDLError("SDL_Init");
        return false;
    }

    // todo - img init management to its own class?
    if (!initIMGPng(imgFlags))
        return false;

    this->win = createWindow(this->SCREEN_WIDTH, this->SCREEN_HEIGHT);
    if (this->win == nullptr)
        return false;

    this->ren = createRenderer(win);
    if (this->ren == nullptr)
        return false;
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}