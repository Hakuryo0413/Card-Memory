#include "StateManager.hpp"
#include "GameScreen.hpp"
#include "StartScreen.hpp"
#include "EndScreen.hpp"
#include "SettingScreen.hpp"
#include "AboutScreen.hpp"
#include "GameBoard.hpp"

#include <iostream> //TODO:remove

StateManager::StateManager()
{
}

StateManager::~StateManager()
{
	delete currentScreen;
	delete nextScreen;
}

void StateManager::switchScreen(Screen newScreen)
{
	if (nextScreen != nullptr)
	{
		//delete nextScreen;
		nextScreen = nullptr;
	}
	switch (newScreen)
	{
	case Screen::StartScreen:
		nextScreen = new StartScreen(this);
		break;
	case Screen::EndScreen:
		nextScreen = new EndScreen(this);
		break;
	case Screen::SettingScreen:
		nextScreen = new SettingScreen(this);
		break;
	case Screen::AboutScreen:
		nextScreen = new AboutScreen(this);
		break;
	case Screen::GameBoard:
		nextScreen = new GameBoard(this);
		break;
	default:
		break;
	}

	if (nextScreen != nullptr)
	{
		std::swap(currentScreen, nextScreen);
	}
}

