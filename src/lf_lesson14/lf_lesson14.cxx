#include "SDL.h"
#include "SDL_image.h"
#include "utils.hxx"
#include "imgUtils.hxx"
#include "input.hxx"
#include "RenderingContext.hxx"
#include "LTexture.hxx"

SDL_Rect *loadClips(const LTexture &image)
{
    SDL_Rect *clips = new SDL_Rect[4];

    int iw = image.getWidth() / 4;
    int ih = image.getHeight();

    for (int i = 0; i < 4; ++i)
    {
        clips[i].w = image.getWidth() / 4;
        clips[i].h = image.getHeight();
        clips[i].y = 0;
        clips[i].x = i * image.getWidth() / 4;
    }

    return clips;
}

int main(int, char **)
{
    RenderingContext context;
    if (!context.startup())
        return 1;

    LTexture walk;
    if (!walk.loadFromFile("walk.bmp", context.ren))
        return 1;

    SDL_Rect *clips = loadClips(walk);

    int frame{0};
    const int totalFrames{4};
    const int slowdown{24};
    Input input;
    while (!input.didQuit())
    {
        input.poll();

        SDL_SetRenderDrawColor(context.ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(context.ren);

        ++frame;
        if (frame / slowdown >= totalFrames)
            frame = 0;

        SDL_Rect *currentClip = &clips[frame / slowdown];
        walk.render(context.ren, (context.SCREEN_WIDTH - currentClip->w) / 2, (context.SCREEN_HEIGHT - currentClip->h) / 2, currentClip);

        // update the screen
        SDL_RenderPresent(context.ren);
    }

    delete[] clips;

    return 0;
}