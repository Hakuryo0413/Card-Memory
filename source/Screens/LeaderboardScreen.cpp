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

