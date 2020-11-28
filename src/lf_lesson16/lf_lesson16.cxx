#include "SDL.h"
#include "SDL_image.h"
#include "utils.hxx"
#include "imgUtils.hxx"
#include "input.hxx"
#include "RenderingContext.hxx"
#include "LTexture.hxx"
#include "LFont.hxx"

int main(int, char **)
{
    RenderingContext context;
    if (!context.startup())
        return 1;

    LFont font;
    if (!font.loadFromFile("roboto/Roboto-Regular.ttf", 16))
        return 1;

    LTexture arrow;
    if (!arrow.loadFromFile("up.bmp", context.ren))
        return 1;

    Input input;
    while (!input.didQuit())
    {
        input.poll();

        input.clearLastKey();

        SDL_SetRenderDrawColor(context.ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(context.ren);

        arrow.render(context.ren, (context.SCREEN_WIDTH - arrow.getWidth()) / 2, (context.SCREEN_HEIGHT - arrow.getHeight()) / 2, 0);

        // update the screen
        SDL_RenderPresent(context.ren);
    }

    return 0;
}