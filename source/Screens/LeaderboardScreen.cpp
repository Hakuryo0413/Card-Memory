#include "LeaderboardScreen.hpp"

LeaderboardScreen::LeaderboardScreen(StateManager* stateManager) : GameScreen(stateManager)
{
    createGUI();
    std::ifstream inFile("HighScore.txt");
    inFile >> Easy_HighScore >> Moderate_HighScore >> Difficult_HighScore;
    std::cout << Easy_HighScore << " " << Moderate_HighScore << " " << Difficult_HighScore << std::endl;
    inFile.close();
}

LeaderboardScreen::~LeaderboardScreen()
{
}

void LeaderboardScreen::renderScreen()
{
    
    renderWidget();
    renderEasyHighScore();
    renderModerateHighScore();
    renderDifficultHighScore();
}

void LeaderboardScreen::updateScreen(float deltaTime)
{
}

void LeaderboardScreen::handleEvent(const SDL_Event& event)
{
    handleWidgetEvent(event);
}

void LeaderboardScreen::createGUI()
{
    createButton("button_home.png", {15, 10}, std::bind(&LeaderboardScreen::goToMenu, this));
}

void LeaderboardScreen::goToMenu()
{
    stateManager->switchScreen(StateManager::Screen::StartScreen);
}

void LeaderboardScreen::renderEasyHighScore()
{
    std::stringstream ss;
    if(Easy_HighScore == 99999)
    {
        ss << "Easy: " << "N/A";
    }
    else
    {
        ss << "Easy: " << Easy_HighScore;
    }
    ss << ",PaytoneOne.ttf,75,255,255,255";
    SDL_Texture * texture = AssetManager::getInstance()->getTexturefromText(ss.str());
    SDL_Rect rect;
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    rect.x = (SCREEN_WIDTH - rect.w) / 2;
    rect.y = 200;
    SDL_RenderCopy(gWindow->getRenderer(), texture, NULL, &rect);
}

void LeaderboardScreen::renderModerateHighScore()
{
    std::stringstream ss;
    if(Moderate_HighScore == 99999)
    {
        ss << "Moderate: " << "N/A";
    }
    else
    {
        ss << "Moderate: " << Moderate_HighScore;
    }
    ss << ",PaytoneOne.ttf,75,255,255,255";
    SDL_Texture * texture = AssetManager::getInstance()->getTexturefromText(ss.str());
    SDL_Rect rect;
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    rect.x = (SCREEN_WIDTH - rect.w) / 2;
    rect.y = 300;
    SDL_RenderCopy(gWindow->getRenderer(), texture, NULL, &rect);
}

void LeaderboardScreen::renderDifficultHighScore()
{
    std::stringstream ss;
    if(Difficult_HighScore == 99999)
    {
        ss << "Difficult: " << "N/A";
    }
    else
    {
        ss << "Difficult: " << Difficult_HighScore;
    }
    ss << ",PaytoneOne.ttf,75,255,255,255";
    SDL_Texture * texture = AssetManager::getInstance()->getTexturefromText(ss.str());
    SDL_Rect rect;
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
    rect.x = (SCREEN_WIDTH - rect.w) / 2;
    rect.y = 400;
    SDL_RenderCopy(gWindow->getRenderer(), texture, NULL, &rect);
}

