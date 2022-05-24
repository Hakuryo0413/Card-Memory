#pragma once

#include <functional>
#include "GameScreen.hpp"

class SettingScreen : public GameScreen
{
public:
    SettingScreen(StateManager* stateManager);
    ~SettingScreen();
    void handleEvent(const SDL_Event& event);
    void renderScreen();
    void updateScreen(float deltaTime);
private:
    void createGUI();
    void goToMenu();
    void goToGame();
    void select4x4();
    void select6x6();
    void select6x8();
};