#pragma once

#include <vector>
#include <algorithm>

#include "GameScreen.hpp"
#include "Window.hpp"
#include "GUIComponent.hpp"
#include "Button.hpp"
#include "Card.hpp"
extern Window* gWindow;

class GameBoard : public GameScreen
{
public:
    GameBoard(StateManager* stateManager);
    ~GameBoard();
    void renderScreen();
    void updateScreen(float deltaTime);
    void handleEvent(const SDL_Event& event);
    void renderTurn();
private:
    void createGUI();
    void createBoard(int row = 2, int column = 3, int width = 100, int height = 120, int distance = 10);
    void renderBoard();
    void updateBoard(float deltaTime);
    std::vector <Card*> board;
    std::pair <Card* , Card*> selectedCards;
    int maxScore;
    int score;
    float freezeTime;
    float timeToGoEndScreen;
    int turn;
    void goToHome();
};