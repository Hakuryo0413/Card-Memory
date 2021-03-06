#pragma once

#include <vector>

#include "GameScreen.hpp"
#include "Window.hpp"
#include "GUIComponent.hpp"
#include "Button.hpp"

extern Window* gWindow;

class StartScreen : public GameScreen
{
public:
    StartScreen(StateManager* stateManager);
    ~StartScreen();
    void renderScreen();
    void updateScreen(float deltaTime);
    void handleEvent(const SDL_Event& event);
private:
    void createGUI();
    void startGame();
    void gotoAboutScreen();
    void goToLeaderboardScreen();
};