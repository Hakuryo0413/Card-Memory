#include "SettingScreen.hpp"

SettingScreen::SettingScreen(StateManager* stateManager) : GameScreen(stateManager)
{
    createGUI();
}

SettingScreen::~SettingScreen()
{
}

void drawRect(SDL_Renderer* renderer, SDL_Rect rect, SDL_Color color);

void SettingScreen::renderScreen()
{
    SDL_RenderCopy(gWindow->getRenderer(), AssetManager::getInstance()->getTexture("game_board_background.png"), NULL, NULL);
    renderWidget();
    
}

void SettingScreen::updateScreen(float deltaTime)
{
}

void SettingScreen::handleEvent(const SDL_Event& event)
{
    handleWidgetEvent(event);
}

void SettingScreen::createGUI()
{
    createButton("button_home.png", {1230, 102}, std::bind(&SettingScreen::goToMenu, this));
    createButton("Easy.png", {555, 200}, std::bind(&SettingScreen::select4x4, this));
    createButton("Moderate.png", {555, 300}, std::bind(&SettingScreen::select6x6, this));
    createButton("Difficult.png", {555, 400}, std::bind(&SettingScreen::select6x8, this));
}

void SettingScreen::goToMenu()
{
    stateManager->switchScreen(StateManager::Screen::StartScreen);
}

void SettingScreen::goToGame()
{
    stateManager->switchScreen(StateManager::Screen::GameBoard);
}

void SettingScreen::select4x4()
{
    stateManager->boardRow = 4;
    stateManager->boardColumn = 4;
    stateManager->cardWidth = 125;
    stateManager->cardHeight = 125;
    stateManager->cardDistance = 5;
    goToGame();
}

void SettingScreen::select6x6()
{
    stateManager->boardRow = 6;
    stateManager->boardColumn = 6;
    stateManager->cardWidth = 100;
    stateManager->cardHeight = 100;
    stateManager->cardDistance = 5;
    goToGame();
}

void SettingScreen::select6x8()
{
    stateManager->boardRow = 6;
    stateManager->boardColumn = 8;
    stateManager->cardWidth = 100;
    stateManager->cardHeight = 100;
    stateManager->cardDistance = 5;
    goToGame();
}