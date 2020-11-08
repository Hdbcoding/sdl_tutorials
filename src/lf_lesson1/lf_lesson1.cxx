#include <iostream>
#include "SDL.h"

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
    if (win == nullptr){
        logSDLError(std::cout, "SDL_CreateWindow");
        SDL_Quit();
        return 1;
    }

    // get the surface of the window
    SDL_Surface *surf = SDL_GetWindowSurface(win);

    // draw a rect on the surface
    Uint32 color = SDL_MapRGB(surf->format, 0x12, 0x93, 0xF2);
    SDL_FillRect(surf, nullptr, color);

    // update the surface
    SDL_UpdateWindowSurface(win);

    // arbitrary wait
    SDL_Delay(3000);

    // cleanup window
    SDL_DestroyWindow(win);

    // close SDL
    SDL_Quit();

    return 0;
}