#include "SDL.h"
#include "utils.hxx"
#include "input.hxx"
#include "RenderingContext.hxx"
#include "LTexture.hxx"

int main(int, char **)
{
    RenderingContext context;
    if (!context.startup())
        return 1;

    LTexture up;
    if (!up.loadFromFile("up.bmp", context.ren))
        return 1;
    LTexture down;
    if (!down.loadFromFile("down.bmp", context.ren))
        return 1;
    LTexture left;
    if (!left.loadFromFile("left.bmp", context.ren))
        return 1;
    LTexture right;
    if (!right.loadFromFile("right.bmp", context.ren))
        return 1;

    Input input;
    LTexture *current = &up;
    while (!input.didQuit())
    {
        input.poll();

        const Uint8 *currentKeyStates = SDL_GetKeyboardState(nullptr);
        if (currentKeyStates[SDL_SCANCODE_UP])
        {
            current = &up;
        }
        else if (currentKeyStates[SDL_SCANCODE_DOWN])
        {
            current = &down;
        }
        else if (currentKeyStates[SDL_SCANCODE_LEFT])
        {
            current = &left;
        }
        else if (currentKeyStates[SDL_SCANCODE_RIGHT])
        {
            current = &right;
        }

        SDL_SetRenderDrawColor(context.ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(context.ren);

        current->render(context.ren, 0, 0);

        // update the screen
        SDL_RenderPresent(context.ren);
    }

    return 0;
}