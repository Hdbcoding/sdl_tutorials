#include "SDL.h"
#include "utils.hxx"
#include "input.hxx"
#include "RenderingContext.hxx"
#include "LTexture.hxx"
#include "LButton.hxx"

int main(int, char **)
{
    RenderingContext context;
    if (!context.startup())
        return 1;

    LTexture tex;
    if (!tex.loadFromFile("buttons.bmp", context.ren))
        return 1;

    LButton b;
    b.setSprites(&tex);
    int x{(context.SCREEN_WIDTH - tex.getWidth() / 2) / 2};
    int y{(context.SCREEN_HEIGHT - tex.getHeight() / 2) / 2};
    b.setPosition(x, y);

    Input input;
    while (!input.didQuit())
    {
        input.poll();
        SDL_Event e = input.getLastEvent();
        b.handleEvent(&e);

        SDL_SetRenderDrawColor(context.ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(context.ren);

        b.render(context.ren);

        // update the screen
        SDL_RenderPresent(context.ren);
    }

    return 0;
}