#include <SDL_image.h>

#include "StartScreen.hpp"

extern bool gQuit;

StartScreen::StartScreen(StateManager* stateManager) : GameScreen(stateManager)
{
    createGUI();
}

StartScreen::~StartScreen()
{
}

void StartScreen::renderScreen()
{
    SDL_RenderCopy(gWindow->getRenderer(), AssetManager::getInstance()->getTexture("start_screen_background.png"), NULL, NULL);
    renderWidget();
}

void StartScreen::updateScreen(float deltaTime)
{
}

void StartScreen::handleEvent(const SDL_Event& event)
{ 
    for(auto& component : GUIComponents)
    {
        component->handleEvent(event);
    }
}

void StartScreen::createGUI()
{
    createButton("Start.png", {555, 450}, std::bind(&StartScreen::startGame, this));
    createButton("Rules.png", {555, 500}, std::bind(&StartScreen::gotoAboutScreen, this));
    createButton("Rank.png", {555, 550}, std::bind(&StartScreen::goToLeaderboardScreen, this));
    createButton("Exit.png", {555, 600}, [](){ gQuit = true; });
}

void StartScreen::startGame()
{
    stateManager->switchScreen(StateManager::Screen::SettingScreen);
}

void StartScreen::gotoAboutScreen()
{
    stateManager->switchScreen(StateManager::Screen::AboutScreen);
}

void StartScreen::goToLeaderboardScreen()
{
    stateManager->switchScreen(StateManager::Screen::LeaderboardScreen);
}