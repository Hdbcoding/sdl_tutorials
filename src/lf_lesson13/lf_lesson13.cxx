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

    LTexture back;
    if (!back.loadFromFile("hello2.bmp", context.ren))
        return 1;

    LTexture front;
    if (!front.loadFromFile("spritesheet.bmp", context.ren))
        return 1;
    front.setBlendMode(SDL_BLENDMODE_BLEND);

    Uint8 a{255};
    Input input;
    while (!input.didQuit())
    {
        input.poll();
        switch (input.getLastKey())
        {
        case SDLK_w:
            if (a >= 223)
                a = 255;
            else
                a += 32;
            break;
        case SDLK_s:
            if (a <= 32)
                a = 0;
            else
                a -= 32;
            break;
        }
        input.clearLastKey();

        SDL_SetRenderDrawColor(context.ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(context.ren);

        back.render(context.ren, 0, 0);

        front.setAlpha(a);
        front.render(context.ren, 0, 0);

        // update the screen
        SDL_RenderPresent(context.ren);
    }

    return 0;
}