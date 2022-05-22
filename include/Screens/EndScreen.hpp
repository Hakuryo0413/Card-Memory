#pragma once

#include <fstream>
#include <functional>
#include "GameScreen.hpp"

extern bool gQuit;

class EndScreen : public GameScreen
{
public:
    EndScreen(StateManager* stateManager);
    ~EndScreen();
    void handleEvent(const SDL_Event& event);
    void renderScreen();
    void updateScreen(float deltaTime);
private:
    void createGUI();
    void goToMenu();
    void goToGame();
    void renderTurn();
    double timePauseMusic;
    int Easy_HighScore;
    int Moderate_HighScore;
    int Difficult_HighScore;
    void renderNotification();
    bool isRenderNotification;
};