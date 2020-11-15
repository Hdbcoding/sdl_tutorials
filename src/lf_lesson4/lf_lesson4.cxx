#include <iostream>
#include <unordered_map>
#include "SDL.h"
#include "utils.hxx"
#include "input.hxx"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool loadSurfaces(SDL_Surface *surfaces[], std::string files[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "loading " << files[i] << std::endl;
        surfaces[i] = loadBMP(files[i]);
        if (surfaces[i] == nullptr)
            return false;
    }
    return true;
}

void cleanupSurfaces(SDL_Surface *surfaces[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (surfaces[i] != nullptr)
        {
            cleanup(surfaces[i]);
            surfaces[i] = nullptr;
        }
    }
}

void selectSurface(SDL_Keycode key, SDL_Surface *surfaces[], SDL_Surface **current)
{
    static const std::unordered_map<SDL_Keycode, int> inputMap{{SDLK_UP, 1}, {SDLK_DOWN, 2}, {SDLK_LEFT, 3}, {SDLK_RIGHT, 4}};
    std::unordered_map<SDL_Keycode, int>::const_iterator got = inputMap.find(key);
    if (got == inputMap.end())
    {
        current = &surfaces[0];
    }
    else
    {
        current = &surfaces[got->second];
    }
}

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

    // get the surface of the window
    SDL_Surface *surf = SDL_GetWindowSurface(win);
    const int numFiles{5};
    std::string files[numFiles]{"default.bmp", "up.bmp", "down.bmp", "left.bmp", "right.bmp"};
    SDL_Surface *surfaces[numFiles]{nullptr, nullptr, nullptr, nullptr, nullptr};
    if (!loadSurfaces(surfaces, files, numFiles))
    {
        cleanupSurfaces(surfaces, numFiles);
        cleanup(win);
        SDL_Quit();
        return 1;
    }

    Input input;
    SDL_Surface *current{surfaces[0]};
    while (!input.didQuit())
    {
        input.poll();

        selectSurface(input.getLastKey(), surfaces, &current);

        // render the image onto the window's surface
        SDL_BlitSurface(current, nullptr, surf, nullptr);

        // update the surface
        SDL_UpdateWindowSurface(win);
    }

    // cleanup
    cleanupSurfaces(surfaces, numFiles);
    cleanup(win);

    // close SDL
    SDL_Quit();

    return 0;
}