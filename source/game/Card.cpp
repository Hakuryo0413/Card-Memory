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
                case RED_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("red_card.png");
                    break;
                case GREEN_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("green_card.png");
                    break;
                case BLUE_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("blue_card.png");
                    break;
                case YELLOW_CARD:
                    cardTexture = AssetManager::getInstance()->getTexture("yellow_card.png");
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
        alpha = 255 * timeToDisappear / 2;
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