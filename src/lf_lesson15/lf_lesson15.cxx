#include "SDL.h"
#include "SDL_image.h"
#include "utils.hxx"
#include "imgUtils.hxx"
#include "input.hxx"
#include "RenderingContext.hxx"
#include "LTexture.hxx"

int main(int, char **)
{
    RenderingContext context;
    if (!context.startup())
        return 1;

    LTexture arrow;
    if (!arrow.loadFromFile("up.bmp", context.ren))
        return 1;

    double degrees = 0;
    SDL_RendererFlip flipType = SDL_FLIP_NONE;

    Input input;
    while (!input.didQuit())
    {
        input.poll();

        switch (input.getLastKey())
        {
        case SDLK_a:
            degrees -= 20;
            break;
        case SDLK_s:
            degrees = 0;
            break;
        case SDLK_d:
            degrees += 20;
        case SDLK_q:
            flipType = SDL_FLIP_HORIZONTAL;
            break;
        case SDLK_w:
            flipType = SDL_FLIP_NONE;
            break;
        case SDLK_e:
            flipType = SDL_FLIP_VERTICAL;
            break;
        }

        input.clearLastKey();

        SDL_SetRenderDrawColor(context.ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(context.ren);

        arrow.setRotation(degrees);
        arrow.setFlip(flipType);
        arrow.render(context.ren, (context.SCREEN_WIDTH - arrow.getWidth()) / 2, (context.SCREEN_HEIGHT - arrow.getHeight()) / 2, 0);

        // update the screen
        SDL_RenderPresent(context.ren);
    }

    return 0;
}