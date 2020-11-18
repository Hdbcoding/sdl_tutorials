#include <iostream>
#include <unordered_map>
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

    int imgFlags = IMG_INIT_PNG;
    int initted = IMG_Init(imgFlags);
    if ((initted & imgFlags) != imgFlags)
    {
        logSDLError("IMG_Init");
        return 1;
    }

    SDL_Window *win = createWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (win == nullptr)
    {
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *ren = createRenderer(win);
    if (ren == nullptr) {
        cleanup(win);
        return false;
    }
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);

    SDL_Texture *image = loadImageTexture("spooky.png", ren);
    if (image == nullptr)
    {
        cleanup(ren, win);
        SDL_Quit();
        return 1;
    }

    Input input;
    while (!input.didQuit())
    {
        input.poll();

        // clear the screen
        SDL_RenderClear(ren);

        // render the current texture
        SDL_RenderCopy(ren, image, NULL, NULL);

        // update the screen
        SDL_RenderPresent(ren);
    }

    // cleanup
    cleanup(image, ren, win);

    // close SDL
    IMG_Quit();
    SDL_Quit();

    return 0;
}