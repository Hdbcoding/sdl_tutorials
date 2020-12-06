#pragma once
#include "SDL.h"
#include "LTexture.hxx"

enum LButtonSprite
{
    BUTTON_SPRITE_OUT = 0,
    BUTTON_SPRITE_HOVER = 1,
    BUTTON_SPRITE_DOWN = 2,
    BUTTON_SPRITE_UP = 3,
};

class LButton
{
    SDL_Point position{0, 0};
    LTexture *sprites{nullptr};
    SDL_Rect *clips{nullptr};
    LButtonSprite current{BUTTON_SPRITE_OUT};
    void buildClippingMap();
    void free();
public:
    LButton();
    LButton(LTexture *sprites);
    ~LButton();
    void setSprites(LTexture *sprites);
    void setPosition(int x, int y);
    void handleEvent(SDL_Event *e);
    void render(SDL_Renderer *ren);
};