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
		GameBoard,
		LeaderboardScreen,
	};

	void switchScreen(Screen newScreen);

	GameScreen * currentScreen;
	GameScreen * nextScreen;

	int boardRow;
	int boardColumn;
	int cardWidth;
	int cardHeight;
	int cardDistance;
	int turn;

	enum class GameMode
	{
		Easy,
		Moderate,
		Difficult,
	};

	GameMode gameMode;
};

