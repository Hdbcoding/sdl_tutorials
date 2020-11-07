#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
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

/**
 * Load a texture from resources to a given renderer
 * @param fileName Name of the file in the resources folder
 * @param ren SDL_Renderer to load the texture onto
 * @return the loaded texture
 */
SDL_Texture *loadTexture(const std::string &filename, SDL_Renderer *ren)
{
    std::string path{getResourceDirectory() + filename};
    SDL_Texture *tex{IMG_LoadTexture(ren, path.c_str())};
    if (tex == nullptr)
        logSDLError(std::cout, "IMG_LoadTexture");
    return tex;
}

/**
 * Draw an sdl_texture to an sdl_renderer at position x, y
 * @param tex Texture to draw
 * @param ren Renderer to draw the loaded texture
 * @param x x coord
 * @param y y coord
 */
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    SDL_RenderCopy(ren, tex, NULL, &dst);
}

/**
 * Draw a texture tiled across the entire window
 * @param tex Texture to draw
 * @param ren Renderer to draw the texture to
 */
void renderTiledBackground(SDL_Texture *tex, SDL_Renderer *ren)
{
    int bw, bh;
    SDL_QueryTexture(tex, NULL, NULL, &bw, &bh);
    for (int x = 0; x < SCREEN_WIDTH; x += bw)
    {
        for (int y = 0; y < SCREEN_HEIGHT; y += bh)
        {
            renderTexture(tex, ren, x, y);
        }
    }
}

/**
 * Draw a texture centered in the window
 * @param tex Texture to draw
 * @param ren Renderer to draw the texture to
 */
void renderCenteredTexture(SDL_Texture *tex, SDL_Renderer *ren)
{
    int iw, ih;
    SDL_QueryTexture(tex, NULL, NULL, &iw, &ih);
    int x{SCREEN_WIDTH / 2 - iw / 2};
    int y{SCREEN_HEIGHT / 2 - ih / 2};
    renderTexture(tex, ren, x, y);
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
    SDL_Window *win = SDL_CreateWindow("Hello world!", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
    SDL_Texture *background = loadTexture("tile.bmp", ren);
    SDL_Texture *face = loadTexture("face.bmp", ren);
    if (background == nullptr || face == nullptr)
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
        // draw background
        renderTiledBackground(background, ren);
        // draw texture
        renderCenteredTexture(face, ren);
        // update screen
        SDL_RenderPresent(ren);
        // sleep
        SDL_Delay(1000);
    }

    // cleanup
    cleanup(background, face, ren, win);
    SDL_Quit();

    return 0;
}