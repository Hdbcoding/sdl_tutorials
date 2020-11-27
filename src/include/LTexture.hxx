#include <string>
#include "SDL.h"

class LTexture {
    SDL_Texture *texture{nullptr};
    int width{0};
    int height{0};

public:
    ~LTexture();

    bool loadFromFile(const std::string &filename, SDL_Renderer *ren);
    void free();
    void render(SDL_Renderer *ren, int x, int y, SDL_Rect * clip = nullptr);
    const int getWidth() const;
    const int getHeight() const;
    void setColorModulation(Uint8 r, Uint8 g, Uint8 b);
};