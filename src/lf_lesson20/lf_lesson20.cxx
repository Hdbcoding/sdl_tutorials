#include "SDL.h"
#include "utils.hxx"
#include "input.hxx"
#include "RenderingContext.hxx"
#include "LTexture.hxx"

int main(int, char **)
{
    RenderingContext context;
    if (!context.startup(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC))
        return 1;

    if (SDL_NumJoysticks() < 1)
    {
        return 1;
    }

    LTexture up;
    if (!up.loadFromFile("up.bmp", context.ren))
        return 1;

    const int JOYSTICK_DEAD_ZONE = 8000;
    SDL_Joystick *controller = SDL_JoystickOpen(0);
    if (controller == nullptr)
    {
        logSDLError("SDL_JoystickOpen");
        return 1;
    }

    SDL_Haptic *haptic = SDL_HapticOpen(0);
    if (haptic == nullptr)
    {
        logSDLError("SDL_HapticOpenFromJoystick");
        SDL_JoystickClose(controller);
        return 1;
    }

    if (SDL_HapticRumbleInit(haptic) < 0)
    {
        logSDLError("SDL_HapticRumbleInit");
        SDL_JoystickClose(controller);
        return 1;
    }

    int x{0};
    int y{0};
    double angle{0};

    Input input;
    while (!input.didQuit())
    {
        input.poll();
        SDL_Event e = input.getLastEvent();
        if (e.type == SDL_JOYAXISMOTION)
        {
            if (e.jaxis.which == 0)
            {
                if (e.jaxis.axis == 0)
                {
                    x = e.jaxis.value;
                }
                else
                {
                    y = e.jaxis.value;
                }
            }
        }
        else if (e.type == SDL_JOYBUTTONDOWN)
        {
            if (SDL_HapticRumblePlay(haptic, 0.5, 500) != 0)
            {
                logSDLError("SDL_HapticRumblePlay");
            }
        }

        angle = SDL_atan2((double)x, (double)y) * (-180 / M_PI) + 180;

        if (x == 0 && y == 0)
            angle = 0;

        up.setRotation(angle);

        SDL_SetRenderDrawColor(context.ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(context.ren);

        up.render(context.ren, 0, 0);

        // update the screen
        SDL_RenderPresent(context.ren);
    }

    SDL_HapticClose(haptic);
    SDL_JoystickClose(controller);

    return 0;
}