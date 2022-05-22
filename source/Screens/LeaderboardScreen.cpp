#include "LeaderboardScreen.hpp"

LeaderboardScreen::LeaderboardScreen(StateManager* stateManager) : GameScreen(stateManager)
{
    createGUI();
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

