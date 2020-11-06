#include <SDL.h>
#include <iostream>
#include "utils.hxx"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

/**
 * Log an SDL error to an output stream
 * @param os Output stream to write to
 * @param msg Message to write
 */
void logSDLError(std::ostream &os, const std::string &msg)
{
    os << msg << " error: " << SDL_GetError() << std::endl;
}

SDL_Texture *loadTexture(const std::string &filename, SDL_Renderer *ren)
{
    SDL_Texture *texture{nullptr};
    
    std::string path{getResourceDirectory() + filename};
    SDL_Surface *bmp = SDL_LoadBMP(path.c_str());
    if (bmp == nullptr)
    {
        logSDLError(std::cout, "SDL_LoadBMP");
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(ren, bmp);
        cleanup(bmp);
        if (texture == nullptr){
            logSDLError(std::cout, "SDL_CreateTextureFromSurface");
        }
    }
    return texture;
}

int main(int, char **)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        logSDLError(std::cout, "SDL_Init");
        return 1;
    }

    // create a window
    SDL_Window *win = SDL_CreateWindow("Hello world!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == nullptr)
    {
        logSDLError(std::cout, "SDL_CreateWindow");
        SDL_Quit();
        return 1;
    }

    // create a renderer which can draw to the window
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr)
    {
        cleanup(win);
        logSDLError(std::cout, "SDL_CreateRenderer");
        SDL_Quit();
        return 1;
    }

    // load bitmap image into "surface"
    SDL_Texture *tex = loadTexture("hello.bmp", ren);
    if (tex == nullptr)
    {
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