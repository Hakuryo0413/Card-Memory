#pragma once

class GameScreen;

class StateManager
{
public:
	StateManager();
	~StateManager();

	enum class Screen
	{
		StartScreen,
		SettingScreen,
		EndScreen,
		AboutScreen,
		GameBoard
	};

	void switchScreen(Screen newScreen);

	GameScreen * currentScreen;
	GameScreen * nextScreen;

	int boardRow;
	int boardColumn;
	int cardWidth;
	int cardHeight;
	int cardDistance;
};

