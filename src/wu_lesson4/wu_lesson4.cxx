#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "utils.hxx"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

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
        logSDLError("IMG_LoadTexture");
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
 * Draw an sdl_texture to an sdl_renderer at position x, y
 * @param tex Texture to draw
 * @param ren Renderer to draw the loaded texture
 * @param x x coord
 * @param y y coord
 * @param w width
 * @param h height
 */
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;
    SDL_RenderCopy(ren, tex, NULL, &dst);
}

/**
 * Draw a texture tiled across the entire window
 * @param tex Texture to draw
 * @param ren Renderer to draw the texture to
 */
void renderTiledBackground(SDL_Texture *tex, SDL_Renderer *ren)
{
    const int tile{50};
    for (int x = 0; x < SCREEN_WIDTH; x += tile)
    {
        for (int y = 0; y < SCREEN_HEIGHT; y += tile)
        {
            renderTexture(tex, ren, x, y, tile, tile);
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

/**
 * Render a background and image in a loop
 * @param ren Renderer
 * @param background Background tiled image
 * @param image Foreground image
 */
void renderLoop(SDL_Renderer *ren, SDL_Texture *background, SDL_Texture *image)
{
    SDL_Event e;
    while (true)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
                goto endOfRender;
        }

        // clear window
        SDL_RenderClear(ren);
        // draw background
        renderTiledBackground(background, ren);
        // draw texture
        renderCenteredTexture(image, ren);
        // update screen
        SDL_RenderPresent(ren);
    }
endOfRender:;
}

int main(int, char **)
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        logSDLError("SDL_Init");
        return 1;
    }

    // create a window
    SDL_Window *win = createWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
    if (win == nullptr)
    {
        SDL_Quit();
        return 1;
    }

    // create a renderer which can draw to the window
    SDL_Renderer *ren = createRenderer(win);
    if (ren == nullptr)
    {
        cleanup(win);
        SDL_Quit();
        return 1;
    }

    // load bitmap image into "surface"
    SDL_Texture *background = loadTexture("tile.bmp", ren);
    SDL_Texture *face = loadTexture("spooky.png", ren);
    if (background == nullptr || face == nullptr)
    {
        cleanup(ren, win);
        SDL_Quit();
        return 1;
    }

    renderLoop(ren, background, face);

    // cleanup
    cleanup(background, face, ren, win);
    SDL_Quit();

    return 0;
}