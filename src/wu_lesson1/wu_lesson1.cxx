#include <SDL.h>
#include <iostream>
#include "utils.hxx"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int, char **)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        logSDLError("SDL_Init");
        return 1;
    }

    // create a window
    SDL_Window *win = createWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (win == nullptr)
    {
        SDL_Quit();
        return 1;
    }

    // create a renderer which can draw to the window
    SDL_Renderer *ren = createRenderer(win);
    if (ren == nullptr)
    {
        cleanup(win);
        SDL_Quit();
        return 1;
    }

    // load bitmap image into "surface"
    SDL_Surface *bmp = loadBMP("hello2.bmp");
    if (bmp == nullptr)
    {
        cleanup(ren, win);
        SDL_Quit();
        return 1;
    }

    // create texture from surface
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    cleanup(bmp);
    if (tex == nullptr)
    {
        logSDLError("SDL_CreateTextureFromSurface");
        cleanup(ren, win);
        SDL_Quit();
        return 1;
    }

    // "rendering loop"
    for (int i = 0; i < 3; ++i)
    {
        // clear window
        SDL_RenderClear(ren);
        // draw texture
        SDL_RenderCopy(ren, tex, NULL, NULL);
        // update screen
        SDL_RenderPresent(ren);
        // sleep
        SDL_Delay(1000);
    }

    // cleanup
    cleanup(tex, ren, win);
    SDL_Quit();

    return 0;
}