#include <string>
#include "SDL.h"

class LTexture
{
    SDL_Texture *texture{nullptr};
    int width{0};
    int height{0};
    double rotation{0};
    SDL_RendererFlip flipType{SDL_FLIP_NONE};

public:
    ~LTexture();

    bool loadFromFile(const std::string &filename, SDL_Renderer *ren);
    void free();
    void render(SDL_Renderer *ren, int x, int y, SDL_Rect *clip = nullptr);
    const int getWidth() const;
    const int getHeight() const;
    void setColorModulation(Uint8 r, Uint8 g, Uint8 b);
    void setBlendMode(SDL_BlendMode blending);
    void setAlpha(Uint8 alpha);
    void setRotation(double rotation);
    void setFlip(SDL_RendererFlip flip);
};