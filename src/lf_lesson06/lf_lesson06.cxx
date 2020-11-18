#include "SDL.h"
#include "SDL_image.h"
#include "utils.hxx"
#include "imgUtils.hxx"
#include "input.hxx"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int, char **)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        logSDLError("SDL_Init");
        return 1;
    }

    if (!initIMGPng())
        return 1;

    SDL_Window *win = createWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (win == nullptr)
    {
        SDL_Quit();
        return 1;
    }

    // get the surface of the window
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    SDL_Surface *image = loadImageOptimized("spooky.png", surf);

    if (image == nullptr)
    {
        cleanup(win);
        SDL_Quit();
        return 1;
    }

    Input input;
    SDL_Rect stretch;
    stretch.x = 0;
    stretch.y = 0;
    stretch.w = SCREEN_WIDTH;
    stretch.h = SCREEN_HEIGHT;
    while (!input.didQuit())
    {
        input.poll();

        // render the image onto the window's surface
        SDL_BlitScaled(image, nullptr, surf, &stretch);

        // update the surface
        SDL_UpdateWindowSurface(win);
    }

    // cleanup
    cleanup(image, win);

    // close SDL
    SDL_Quit();

    return 0;
}