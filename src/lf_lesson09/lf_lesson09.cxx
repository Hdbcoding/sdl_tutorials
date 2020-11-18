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

    SDL_Renderer *ren = createRenderer(win);
    if (ren == nullptr)
    {
        cleanup(win);
        return false;
    }

    SDL_Texture *image = loadImageTexture("spooky.png", ren);
    if (image == nullptr)
    {
        cleanup(ren, win);
        SDL_Quit();
        return 1;
    }

    SDL_Rect topLeft{0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    SDL_Rect topRight{SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
    SDL_Rect bottom{0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};

    Input input;
    while (!input.didQuit())
    {
        input.poll();

        SDL_RenderSetViewport(ren, &topLeft);
        SDL_RenderCopy(ren, image, nullptr, nullptr);

        SDL_RenderSetViewport(ren, &topRight);
        SDL_RenderCopy(ren, image, nullptr, nullptr);

        SDL_RenderSetViewport(ren, &bottom);
        SDL_RenderCopy(ren, image, nullptr, nullptr);

        // update the screen
        SDL_RenderPresent(ren);
    }

    // cleanup
    cleanup(image, ren, win);

    // close SDL
    SDL_Quit();

    return 0;
}