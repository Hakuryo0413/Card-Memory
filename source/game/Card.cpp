#include "Card.hpp"

Card::Card(int x, int y, int width_, int height_, Card::Suit suit_)
{
    position.x = x;
    position.y = y;
    width = width_;
    height = height_;
    suit = suit_;
    hidden = true;
    invisible = false;
    timeToHide = -1;
    timeToDisappear = -1;
    alpha = 255;
}

Card::~Card()
{
}

void Card::render()
{
    if(!invisible)
    {
        SDL_Texture* cardTexture = NULL;
        if(hidden)
        {
            cardTexture = AssetManager::getInstance()->getTexture("back_of_card.png");
        }
        else
        {
            switch(suit)
            {
                case a_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("2.png");
                    break;
                case b_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("3.png");
                    break;
                case c_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("4.png");
                    break;
                case d_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("5.png");
                    break;
                case e_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("6.png");
                    break;
                case f_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("7.png");
                    break;
                case g_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("8.png");
                    break;
                case h_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("9.png");
                    break;
                case i_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("10.png");
                    break;
                case k_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("11.png");
                    break;
                case l_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("12.png");
                    break;
                case m_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("13.png");
                    break;
                case n_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("14.png");
                    break;
                case o_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("15.png");
                    break;
                case p_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("16.png");
                    break;
                case q_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("17.png");
                    break;
                case r_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("18.png");
                    break;
                case s_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("19.png");
                    break;
                case t_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("20.png");
                    break;
                case u_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("21.png");
                    break;
                case v_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("22.png");
                    break;
                case w_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("23.png");
                    break;
                case x_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("24.png");
                    break;
                case y_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("25.png");
                    break;
            }
        }
        SDL_SetTextureAlphaMod(cardTexture, alpha);
        SDL_Rect destRect = {position.x, position.y, width, height};
        SDL_RenderCopy(gWindow->getRenderer(), cardTexture, NULL, &destRect);
    }
}

bool Card::isClicked(const SDL_Event& e)
{
    if(!invisible)
    {
        if(e.type == SDL_MOUSEBUTTONDOWN)
        {
            if(e.button.x >= position.x && e.button.x <= position.x + width && e.button.y >= position.y && e.button.y <= position.y + height)
            {
                return true;
            }
        }
    }
    return false;
}

void Card::update(float deltaTime)
{
    if(timeToDisappear > 0)
    {
        timeToDisappear -= deltaTime;
        alpha = 255 * timeToDisappear / 1;
        if(timeToDisappear <= 0)
        {
            invisible = true;
            timeToDisappear = -1;
        }
    }
    if(timeToHide > 0)
    {
        timeToHide -= deltaTime;
        if(timeToHide <= 0)
        {
            hidden = true;
            timeToHide = -1;
        }
    }
}

Card::Suit Card::getSuit()
{
    return suit;
}

void Card::disappear(float time)
{
    this->timeToDisappear = time;
}

void Card::hide(float time)
{
    this->timeToHide = time;
}

void Card::setShow(bool show)
{
    this->hidden = !show;
}