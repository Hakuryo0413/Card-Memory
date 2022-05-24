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
        a_CARD,
        b_CARD,
        c_CARD,
        d_CARD,
        e_CARD,
        f_CARD,
        g_CARD,
        h_CARD,
        i_CARD,
        k_CARD,
        l_CARD,
        m_CARD,
        n_CARD,
        o_CARD,
        p_CARD,
        q_CARD,
        r_CARD,
        s_CARD,
        t_CARD,
        u_CARD,
        v_CARD,
        w_CARD,
        x_CARD,
        y_CARD,
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