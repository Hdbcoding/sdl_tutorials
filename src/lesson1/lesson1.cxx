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
        std::cout << "SDL Init error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // create a window
    SDL_Window *win = SDL_CreateWindow("Hello world!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr)
    {
        std::cout << "SDL_CreateWindow error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // create a renderer which can draw to the window
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr)
    {
        cleanup(win);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // load bitmap image into "surface"
    std::string imagePath = getResourceDirectory() + "hello.bmp";
    SDL_Surface *bmp = SDL_LoadBMP(imagePath.c_str());
    if (bmp == nullptr)
    {
        cleanup(ren, win);
        std::cout << "SDL_LoadBMP error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // create texture from surface
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    cleanup(bmp);
    SDL_FreeSurface(bmp);
    if (tex == nullptr)
    {
        cleanup(ren, win);
        std::cout << "SDL_CreateTextureFromSurface error: " << SDL_GetError() << std::endl;
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