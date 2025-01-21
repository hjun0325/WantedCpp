#include "Game.h"
#include "Level/StartLevel.h"
#include "Level/GameLevel.h"
#include "Level/MenuLevel.h"
#include "Level/GameOverLevel.h"
#include "Level/GameClearLevel.h"

Game* Game::instance = nullptr;

Game::Game()
{
	// Ŀ�� �Ⱥ��̰� ����
	SetCursorType(CursorType::NoCursor);

	// �̱��� ��ü ����.
	instance = this;

	// ���� ����.
	startLevel = new StartLevel();
	menuLevel = new MenuLevel();
	gameOverLevel = new GameOverLevel();
	gameClearLevel = new GameClearLevel();
	LoadLevel(startLevel);
}

Game::~Game()
{
	mainLevel = nullptr;
	delete startLevel;
	delete gameLevel;
	delete menuLevel;
	delete gameOverLevel;
	delete gameClearLevel;
}

void Game::ToggleLevel(const char* Text)
{
	// ȭ�� �����.
	system("cls");

	if (Text == "Resume Game" || Text == "Load Game")
	{
		if (gameLevel != nullptr)
		{
			mainLevel = gameLevel;
		}
	}
	else if (Text == "New Game" || Text == "Retry")
	{
		if (gameLevel != nullptr)
		{
			delete gameLevel;
			gameLevel = nullptr;
		}
		gameLevel = new GameLevel();
		mainLevel = gameLevel;
	}
	else if (Text == "Main")
	{
		// ���� ���� ������ �޴� �����̸� ���� �Ѿ �� ���� ���� delete ����.
		if (mainLevel->As<MenuLevel>())
		{
			mainLevel = startLevel;
		}

		// ���� ���� ������ ���� ������ ���� Ŭ���� �����̸� ���� �Ѿ �� ���� ���� delete.
		if (mainLevel->As<GameOverLevel>() || mainLevel->As < GameClearLevel>())
		{
			delete gameLevel;
			gameLevel = nullptr;
			mainLevel = startLevel;
		}
	}
	else if ("Menu")
	{
		mainLevel = menuLevel;
	}
}

void Game::SaveRecord(float record)
{
	gameClearLevel->As<GameClearLevel>()->SetRecord(record);
}
