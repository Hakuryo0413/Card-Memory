#include "GameBoard.hpp"

GameBoard::GameBoard(StateManager* stateManager) : GameScreen(stateManager)
{
    createGUI();
    createBoard(stateManager->boardRow, stateManager->boardColumn, stateManager->cardWidth, stateManager->cardHeight, stateManager->cardDistance);
    selectedCards = std::make_pair(nullptr, nullptr);
    maxScore = stateManager->boardRow * stateManager->boardColumn / 2;
    score = 0;
    timeToGoEndScreen = -1;
    turn = 0;
    freezeTime = -1;
    selectCardSound = AssetManager::getInstance()->getSoundBuffer("button_click_sound.wav");
    correctSelectCardSound = AssetManager::getInstance()->getSoundBuffer("button_click_sound.wav");
    wrongSelectCardSound = AssetManager::getInstance()->getSoundBuffer("button_click_sound.wav");
    canNotSelectCardSound = AssetManager::getInstance()->getSoundBuffer("button_click_sound.wav");
}

GameBoard::~GameBoard()
{
}

void GameBoard::renderScreen()
{
    SDL_RenderCopy(gWindow->getRenderer(), AssetManager::getInstance()->getTexture("game_board_background.png"), NULL, NULL);
    renderBoard();
    renderWidget();
    renderTurn();
}

void GameBoard::updateScreen(float deltaTime)
{
    updateBoard(deltaTime);
    if(freezeTime > 0)
    {
        freezeTime -= deltaTime;
    }
    if(score == maxScore)
    {
        timeToGoEndScreen = 2;
        score = 0;
    }
    if(timeToGoEndScreen > 0)
    {
        timeToGoEndScreen -= deltaTime;
        if(timeToGoEndScreen <= 0)
        {
            stateManager->turn = turn;
            stateManager->switchScreen(StateManager::Screen::EndScreen);
        }
    }
}

void GameBoard::handleEvent(const SDL_Event& event)
{ 
    for(auto& component : GUIComponents)
    {
        component->handleEvent(event);
    }

    for(auto& card : board)
    {
        if(card->isClicked(event))
        {
            if(!(freezeTime > 0))
            {
                if(selectedCards.first == nullptr)
                {
                    selectedCards.first = card;
                    card->setShow(true);
                    Mix_PlayChannel(-1, selectCardSound, 0);
                }
                else if(selectedCards.first != card)
                {
                    selectedCards.second = card;
                    card->setShow(true);
                    turn++;
                    if(selectedCards.first->getSuit() == selectedCards.second->getSuit())
                    {
                        score++;
                        selectedCards.first->disappear(1);
                        selectedCards.second->disappear(1);
                        selectedCards.first = nullptr;
                        selectedCards.second = nullptr;
                        Mix_PlayChannel(-1, correctSelectCardSound, 0);
                    }
                    else
                    {
                        freezeTime = 1;
                        selectedCards.first->hide(freezeTime);
                        selectedCards.second->hide(freezeTime);
                        selectedCards.first = nullptr;
                        selectedCards.second = nullptr;
                        Mix_PlayChannel(-1, wrongSelectCardSound, 0);
                    }
                }
            }
            else
            {
                Mix_PlayChannel(-1, canNotSelectCardSound, 0);
            }
        }
    }
}

void GameBoard::createGUI()
{
    createButton("button_home.png", {15, 10}, std::bind(&GameBoard::goToHome, this));
}

void GameBoard::createBoard(int row, int column, int width, int height, int distance)
{
    float maxOccurrence = (float)row * column / 2 / Card::TOTAL_SUIT;
    if(maxOccurrence != (int)maxOccurrence)
    {
        maxOccurrence = (int)maxOccurrence + 1;
    }
    std::map <int, int> occurrence;
    std::vector <Card::Suit> suits;
    for(int i = 0; i < row * column/2; i++)
    {
        int suit;
        do
        {
            suit = rand() % Card::TOTAL_SUIT;
        } while(occurrence[suit] >= maxOccurrence);
        occurrence[suit]++;
        suits.push_back((Card::Suit)suit);
        suits.push_back((Card::Suit)suit);
    }
    std::random_shuffle(suits.begin(), suits.end());
    int startX = SCREEN_WIDTH/2 - (column * width + distance * (column - 1))/2;
    int startY = SCREEN_HEIGHT/2 - (row * height + distance * (row - 1))/2;
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            board.push_back(new Card(startX + j * (width + distance),
                                    startY + i * (height + distance),
                                    width, height, suits[i * column + j]));
        }
    }
}

void GameBoard::renderBoard()
{
    for(auto& card : board)
    {
        card->render();
    }
}

void GameBoard::updateBoard(float deltaTime)
{
    for(auto& card : board)
    {
        card->update(deltaTime);
    }
}

void GameBoard::renderTurn()
{
    std::stringstream ss;
    ss << "Turn: " << turn << ",PaytoneOne.ttf,40,255,255,255";
    SDL_Texture* turnTexture = AssetManager::getInstance()->getTexturefromText(ss.str());
    SDL_Rect rect;
    SDL_QueryTexture(turnTexture, NULL, NULL, &rect.w, &rect.h);
    rect.x = 1090;
    rect.y = 145;
    SDL_RenderCopy(gWindow->getRenderer(), turnTexture, NULL, &rect);
}

void GameBoard::goToHome()
{
    stateManager->switchScreen(StateManager::Screen::StartScreen);
}