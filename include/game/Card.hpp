#pragma once

#include <SDL.h>

#include "AssetManager.hpp"
#include "Window.hpp"

extern Window* gWindow;

class Card
{
public:
    enum Suit
    {
        RED_CARD,
        GREEN_CARD,
        BLUE_CARD,
        YELLOW_CARD,
        TOTAL_SUIT,
        BACK_OF_CARD,
    };
    Card(int x, int y, int width_, int height_, Card::Suit suit_);
    ~Card();
    void update(float deltaTime);
    void render();
    bool isClicked(const SDL_Event& e);
    Suit getSuit();
    void disappear(float time);
    void hide(float time);
    void setShow(bool show);
private:
    Suit suit;
    SDL_Point position;
    int width, height;
    bool hidden;
    bool invisible;
    float timeToHide;
    float timeToDisappear;
    Uint8 alpha;
};