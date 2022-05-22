#pragma once

#include <functional>
#include "GameScreen.hpp"

class LeaderboardScreen : public GameScreen
{
public:
    LeaderboardScreen(StateManager* stateManager);
    ~LeaderboardScreen();
    void handleEvent(const SDL_Event& event);
    void renderScreen();
    void updateScreen(float deltaTime);
private:
    void createGUI();
    void goToMenu();
    int Easy_HighScore;
    int Moderate_HighScore;
    int Difficult_HighScore;
};