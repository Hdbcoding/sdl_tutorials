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

    Input input;
    while (!input.didQuit())
    {
        input.poll();

        // clear the screen
        SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(ren);

        // red filled rectangle
        SDL_Rect fillRect{SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
        SDL_SetRenderDrawColor(ren, 0xFF, 0x00, 0x00, 0xFF);
        SDL_RenderFillRect(ren, &fillRect);

        // green outline
        SDL_Rect outlineRect{SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3};
        SDL_SetRenderDrawColor(ren, 0x00, 0xFF, 0x00, 0xff);
        SDL_RenderDrawRect(ren, &outlineRect);

        // blue line
        SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0xFF, 0xFF);
        SDL_RenderDrawLine(ren, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

        // dotted line using points
        SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0x00, 0xFF);
        for (int i = 0; i < SCREEN_HEIGHT; i += 4)
        {
            SDL_RenderDrawPoint(ren, SCREEN_WIDTH / 2, i);
        }

        // update the screen
        SDL_RenderPresent(ren);
    }

    // cleanup
    cleanup(ren, win);

    // close SDL
    SDL_Quit();

    return 0;
}