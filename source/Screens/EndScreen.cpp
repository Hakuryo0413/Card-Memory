#include "EndScreen.hpp"

EndScreen::EndScreen(StateManager* stateManager) : GameScreen(stateManager)
{
    createGUI();
    std::ifstream inFile("HighScore.txt");
    inFile >> Easy_HighScore >> Moderate_HighScore >> Difficult_HighScore;
    inFile.close();
    isRenderNotification = false;
    if(!Mix_PausedMusic())
    {
        Mix_PauseMusic();
        timePauseMusic = 2;
    }
    else
    {
        timePauseMusic = -1;
    }
    if(gSoundOn) Mix_PlayChannel(-1, AssetManager::getInstance()->getSoundBuffer("win_game_sound.wav"), 0);
    switch (stateManager->gameMode)
    {
        case StateManager::GameMode::Easy:
        {
            if (stateManager->turn < Easy_HighScore)
            {
                isRenderNotification = true;
                Easy_HighScore = stateManager->turn;
                std::ofstream outFile("HighScore.txt");
                outFile << Easy_HighScore << " " << Moderate_HighScore << " " << Difficult_HighScore;
                outFile.close();
            }
            break;
        }
        case StateManager::GameMode::Moderate:
        {
            if (stateManager->turn < Moderate_HighScore)
            {
                isRenderNotification = true;
                Moderate_HighScore = stateManager->turn;
                std::ofstream outFile("HighScore.txt");
                outFile << Easy_HighScore << " " << Moderate_HighScore << " " << Difficult_HighScore;
                outFile.close();
            }
            break;
        }
        case StateManager::GameMode::Difficult:
        {
            if (stateManager->turn < Difficult_HighScore)
            {
                isRenderNotification = true;
                Difficult_HighScore = stateManager->turn;
                std::ofstream outFile("HighScore.txt");
                outFile << Easy_HighScore << " " << Moderate_HighScore << " " << Difficult_HighScore;
                outFile.close();
            }
            break;
        }
    }
}

EndScreen::~EndScreen()
{
}

void drawRect(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color color);

void EndScreen::renderScreen()
{
    SDL_RenderCopy(gWindow->getRenderer(), AssetManager::getInstance()->getTexture("game_board_background.png"), NULL, NULL);
    renderTurn();
    renderWidget();
    if(isRenderNotification)
    {
        renderNotification();
    }
}

void EndScreen::updateScreen(float deltaTime)
{
    if(timePauseMusic!= -1)
    {
        timePauseMusic -= deltaTime;
        if(timePauseMusic < 0 && Mix_PausedMusic())
        {
            Mix_ResumeMusic();
        }
    }
}

void EndScreen::handleEvent(const SDL_Event& event)
{
    handleWidgetEvent(event);
}

void EndScreen::createGUI()
{
    createButton("button_restart.png", {555, 450}, std::bind(&EndScreen::goToGame, this));
    createButton("Exit.png", {555, 500}, [](){ gQuit = true; });
    createButton("button_home.png", {15, 10}, std::bind(&EndScreen::goToMenu, this));
}

void EndScreen::goToMenu()
{
    stateManager->switchScreen(StateManager::Screen::StartScreen);
}

void EndScreen::goToGame()
{
    stateManager->switchScreen(StateManager::Screen::GameBoard);
}

void EndScreen::renderTurn()
{
    std::stringstream ss;
    ss << "Turn: " << stateManager->turn << ",PaytoneOne.ttf,100,255,255,255";
    SDL_Texture* turnTexture = AssetManager::getInstance()->getTexturefromText(ss.str());
    SDL_Rect rect;
    SDL_QueryTexture(turnTexture, NULL, NULL, &rect.w, &rect.h);
    rect.x = SCREEN_WIDTH/2 - rect.w/2;
    rect.y = 100;
    SDL_RenderCopy(gWindow->getRenderer(), turnTexture, NULL, &rect);
}

void EndScreen::renderNotification()
{
    SDL_Texture* turnTexture = AssetManager::getInstance()->getTexturefromText("New High Score!,PaytoneOne.ttf,40,255,255,255");
    SDL_Rect rect;
    SDL_QueryTexture(turnTexture, NULL, NULL, &rect.w, &rect.h);
    rect.x = SCREEN_WIDTH/2 - rect.w/2;
    rect.y = 250;
    SDL_RenderCopy(gWindow->getRenderer(), turnTexture, NULL, &rect);
}