#include <iostream>
#include "SDL.h"
#include "utils.hxx"

std::string getRootDirectory()
{
    static std::string baseRes;
    if (baseRes.empty())
    {
        char *bp = SDL_GetBasePath();
        if (bp)
        {
            baseRes = bp;
            SDL_free(bp);
            std::cout << "Found base path: " << baseRes << std::endl;
        }
        else
        {
            std::cerr << "Error getting resource path: " << SDL_GetError() << std::endl;
            return "";
        }
    }
    return baseRes;
}

std::string getResourceDirectory()
{
    static std::string baseRes;
    if (baseRes.empty())
    {
        baseRes = getRootDirectory();

        size_t position = baseRes.rfind("bin");
        baseRes = baseRes.substr(0, position) + "resources" + PATH_SEP;
        std::cout << "Found resource path: " << baseRes << std::endl;
    }
    return baseRes;
}

/**
 * Log an SDL error to an output stream
 * @param os Output stream to write to
 * @param msg Message to write
 */
void logSDLError(std::ostream &out, const std::string &message)
{
    out << message << " error: " << SDL_GetError() << std::endl;
}

/**
 * Log an SDL error to the standard output stream
 */
void logSDLError(const std::string &message)
{
    logSDLError(std::cout, message);
}

SDL_Window *createWindow(int width, int height, std::string name)
{
    SDL_Window *win = SDL_CreateWindow("Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    if (win == nullptr)
        logSDLError("SDL_CreateWindow");
    return win;
}

SDL_Renderer *createRenderer(SDL_Window *win)
{
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == nullptr)
        logSDLError("SDL_CreateRenderer");
    return ren;
}

SDL_Surface *loadBMP(const std::string &filename)
{
    std::string path{getResourceDirectory() + filename};
    SDL_Surface *image = SDL_LoadBMP(path.c_str());
    if (image == nullptr)
        logSDLError("SDL_LoadBMP");
    return image;
}

SDL_Surface *loadBMPOptimized(const std::string &filename, const SDL_Surface *source)
{
    SDL_Surface *image = loadBMP(filename);
    SDL_Surface *optimized{nullptr};
    if (image != nullptr)
    {
        optimized = SDL_ConvertSurface(image, source->format, 0);
        if (optimized == nullptr)
        {
            logSDLError("SDL_ConvertSurface");
        }
        SDL_FreeSurface(image);
    }
    return optimized;
}

SDL_Texture *adaptSurface(SDL_Surface *surf, SDL_Renderer *ren)
{
    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, surf);

    if (tex == nullptr)
        logSDLError("SDL_CreateTextureFromSurface");

    return tex;
}