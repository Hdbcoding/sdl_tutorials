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

    LTexture background;
    if (!background.loadFromFile("hello2.bmp", context.ren))
        return 1;

    LTexture character;
    if (!character.loadFromFile("spooky.png", context.ren))
        return 1;

    Input input;
    while (!input.didQuit())
    {
        input.poll();

        background.render(context.ren, 0, 0);
        character.render(context.ren, 240, 190);

        // update the screen
        SDL_RenderPresent(context.ren);
    }

    return 0;
}