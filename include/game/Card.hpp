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
        2_CARD,
        3_CARD,
        4_CARD,
        5_CARD,
        6_CARD,
        7_CARD,
        8_CARD,
        9_CARD,
        10_CARD,
        11_CARD,
        12_CARD,
        13_CARD,
        14_CARD,
        15_CARD,
        16_CARD,
        17_CARD,
        18_CARD,
        19_CARD,
        20_CARD,
        21_CARD,
        22_CARD,
        23_CARD,
        24_CARD,
        25_CARD,
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