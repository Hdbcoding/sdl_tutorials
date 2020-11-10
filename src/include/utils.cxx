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

SDL_Surface *loadBMP(std::string filename)
{
    std::string path{getResourceDirectory() + "hello2.bmp"};
    SDL_Surface *image = SDL_LoadBMP(path.c_str());
    if (image == nullptr)
    {
        logSDLError("SDL_LoadBMP");
    }
    return image;
}