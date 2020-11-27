#include "SDL.h"
#include "SDL_image.h"
#include "utils.hxx"
#include "imgUtils.hxx"
#include "input.hxx"
#include "RenderingContext.hxx"
#include "LTexture.hxx"

SDL_Rect *buildClippingMap(const LTexture &image)
{
    SDL_Rect *clips = new SDL_Rect[4];
    for (int i = 0; i < 4; i++)
    {
        clips[i].x = i / 2 * image.getWidth() / 2;
        clips[i].y = i % 2 * image.getHeight() / 2;
        clips[i].w = image.getWidth() / 2;
        clips[i].h = image.getHeight() / 2;
    }
    return clips;
}

int main(int, char **)
{
    RenderingContext context;
    if (!context.startup())
        return 1;

    LTexture sheet;
    if (!sheet.loadFromFile("spritesheet.bmp", context.ren))
        return 1;

    SDL_Rect *clips = buildClippingMap(sheet);


    Input input;
    while (!input.didQuit())
    {
        input.poll();

        SDL_SetRenderDrawColor(context.ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(context.ren);

        // top left
        sheet.render(context.ren, 0, 0, &clips[0]);

        // top right
        sheet.render(context.ren, context.SCREEN_WIDTH - clips[1].w, 0, &clips[1]);

        // bottom left
        sheet.render(context.ren, 0, context.SCREEN_HEIGHT - clips[2].h, &clips[2]);

        // bottom right
        sheet.render(context.ren, context.SCREEN_WIDTH - clips[3].w, context.SCREEN_HEIGHT - clips[3].h, &clips[3]);

        // update the screen
        SDL_RenderPresent(context.ren);
    }

    delete[] clips;

    return 0;
}