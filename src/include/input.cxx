#include <SDL.h>
#include <input.hxx>

void Input::poll()
{
    SDL_Event e;
    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
            this->quit = true;
        else if (e.type == SDL_KEYDOWN)
        {
            this->lastKey = e.key.keysym.sym;
        }
    }
}

const bool Input::didQuit() const
{
    return this->quit;
}

const SDL_Keycode Input::getLastKey() const
{
    return this->lastKey;
}

void Input::clearLastKey()
{
    this->lastKey = SDLK_UNKNOWN;
}