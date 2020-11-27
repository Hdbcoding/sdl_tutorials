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

    LTexture sheet;
    if (!sheet.loadFromFile("spritesheet.bmp", context.ren))
        return 1;

    Uint8 r{0};
    Uint8 g{0};
    Uint8 b{0};
    Input input;
    while (!input.didQuit())
    {
        input.poll();
        switch(input.getLastKey())
        {
            case SDLK_q:
                r += 32;
                break;
            case SDLK_w:
                g += 32;
                break;
            case SDLK_e:
                b += 32;
                break;
            case SDLK_a:
                r -= 32;
                break;
            case SDLK_s:
                g -= 32;
                break;
            case SDLK_d:
                b -= 32;
                break;
        }
        input.clearLastKey();

        SDL_SetRenderDrawColor(context.ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(context.ren);

        // top left
        sheet.setColorModulation(r, g, b);
        sheet.render(context.ren, 0, 0);

        // update the screen
        SDL_RenderPresent(context.ren);
    }

    return 0;
}