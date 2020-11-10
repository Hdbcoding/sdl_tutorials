#include <iostream>
#include "SDL.h"
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

int main(int, char **)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        logSDLError(std::cout, "SDL_Init");
        return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (win == nullptr)
    {
        logSDLError(std::cout, "SDL_CreateWindow");
        SDL_Quit();
        return 1;
    }

    // get the surface of the window
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    // load an image
    std::string path{getResourceDirectory() + "hello2.bmp"};
    SDL_Surface *image = SDL_LoadBMP(path.c_str());
    if (image == nullptr)
    {
        logSDLError(std::cout, "SDL_LoadBMP");
        cleanup(win);
        SDL_Quit();
        return 1;
    }

    // render the image onto the window's surface
    SDL_BlitSurface(image, nullptr, surf, nullptr);

    // update the surface
    SDL_UpdateWindowSurface(win);

    // arbitrary wait
    SDL_Delay(3000);

    // cleanup
    cleanup(image, win);

    // close SDL
    SDL_Quit();

    return 0;
}