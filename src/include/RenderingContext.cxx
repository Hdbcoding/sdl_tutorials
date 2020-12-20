#include "SDL.h"
#include "utils.hxx"
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
    SDL_Quit();
}

bool RenderingContext::startup(Uint32 flags)
{
    // todo - sdl init management to its own class?
    if (SDL_Init(flags) != 0)
    {
        logSDLError("SDL_Init");
        return false;
    }

    this->win = createWindow(this->SCREEN_WIDTH, this->SCREEN_HEIGHT);
    if (this->win == nullptr)
        return false;

    this->ren = createRenderer(win);
    if (this->ren == nullptr)
        return false;
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);

    return true;
}