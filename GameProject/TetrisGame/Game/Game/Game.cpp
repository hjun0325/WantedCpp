#include "Game.h"
#include "Level/StartLevel.h"
#include "Level/GameLevel.h"
#include "Level/MenuLevel.h"
#include "Level/GameOverLevel.h"
#include "Level/GameClearLevel.h"

Game* Game::instance = nullptr;

Game::Game()
{
	// 커서 안보이게 설정
	SetCursorType(CursorType::NoCursor);

	// 싱글톤 객체 설정.
	instance = this;

	// 레벨 생성.
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
	// 화면 지우기.
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
		// 현재 메인 레벨이 메뉴 레벨이면 메인 넘어갈 때 게임 레벨 delete 금지.
		if (mainLevel->As<MenuLevel>())
		{
			mainLevel = startLevel;
		}

		// 현재 메인 레벨이 게임 오버나 게임 클리어 레벨이면 메인 넘어갈 때 게임 레벨 delete.
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
