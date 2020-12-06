#include "SDL.h"
#include "LButton.hxx"
#include "LTexture.hxx"

LButton::LButton() {}

LButton::LButton(LTexture *sprites)
{
    this->setSprites(sprites);
}

void LButton::setSprites(LTexture *sprites)
{
    this->free();
    this->sprites = sprites;
    this->buildClippingMap();
}

void LButton::buildClippingMap()
{
    if (this->sprites == nullptr)
        return;
    this->clips = new SDL_Rect[4];
    int w{this->sprites->getWidth()};
    int h{this->sprites->getHeight()};
    for (int i = 0; i < 4; i++)
    {
        clips[i].x = i / 2 * w / 2;
        clips[i].y = i % 2 * h / 2;
        clips[i].w = w / 2;
        clips[i].h = h / 2;
    }
}

LButton::~LButton()
{
    this->free();
}

void LButton::free()
{
    if (this->clips != nullptr)
    {
        // button does not own its sprites, it only has a reference!
        this->sprites = nullptr;
        // this button does own its own clipping map, so delete that
        delete[] this->clips;
        this->clips = nullptr;
    }
}

void LButton::setPosition(int x, int y)
{
    this->position.x = x;
    this->position.y = y;
}

void LButton::handleEvent(SDL_Event *e)
{
    if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {
        int x, y;
        SDL_GetMouseState(&x, &y);

        int w{this->sprites->getWidth() / 2};
        int h{this->sprites->getHeight() / 2};
        bool inside = x >= this->position.x && y >= this->position.y && x <= (this->position.x + w) && y <= (this->position.y + h);
        if (inside)
        {
            switch (e->type)
            {
            case SDL_MOUSEMOTION:
                this->current = BUTTON_SPRITE_HOVER;
                break;
            case SDL_MOUSEBUTTONDOWN:
                this->current = BUTTON_SPRITE_DOWN;
                break;
            case SDL_MOUSEBUTTONUP:
                this->current = BUTTON_SPRITE_UP;
                break;
            }
        }
        else
        {
            this->current = BUTTON_SPRITE_OUT;
        }
    }
}

void LButton::render(SDL_Renderer *ren)
{
    this->sprites->render(ren, this->position.x, this->position.y, &this->clips[this->current]);
}