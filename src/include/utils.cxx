#include <string>
#include <iostream>
#include <SDL.h>
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

std::string getResourceDirectory(){
    static std::string baseRes;
    if (baseRes.empty()){
        baseRes = getRootDirectory();

        size_t position = baseRes.rfind("bin");
        baseRes = baseRes.substr(0, position) + "resources" + PATH_SEP;
        std::cout << "Found resource path: " << baseRes << std::endl;
    }
    return baseRes;
}