#include <SDL.h>
#include <input.hxx>

void Input::poll()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
            this->quit = true;
    }
}

const bool Input::didQuit()
{
    return this->quit;
}