#include "SDL.h"
#include "SDL_ttf.h"
#include "ttfUtils.hxx"
#include "utils.hxx"
#include "input.hxx"
#include "RenderingContext.hxx"
#include "LTextTexture.hxx"
#include "LFont.hxx"

int main(int, char **)
{
    RenderingContext context;
    if (!context.startup())
        return 1;

    if (!initTTF())
        return 1;

    LFont font;
    if (!font.loadFromFile("roboto/Roboto-Regular.ttf", 28))
        return 1;

    LTextTexture text;
    SDL_Color color{123,212,23,255};
    if (!text.loadFromText("hahahaha", color, &font, context.ren))
        return 1;

    Input input;
    while (!input.didQuit())
    {
        input.poll();

        input.clearLastKey();

        SDL_SetRenderDrawColor(context.ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(context.ren);

        text.render(context.ren, (context.SCREEN_WIDTH - text.getWidth()) / 2, (context.SCREEN_HEIGHT - text.getHeight()) / 2);

        // update the screen
        SDL_RenderPresent(context.ren);
    }

    return 0;
}