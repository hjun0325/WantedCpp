#include "Game.h"
#include "Level/StartLevel.h"
#include "Level/GameLevel.h"
#include "Level/MenuLevel.h"

Game* Game::instance = nullptr;

Game::Game()
{
	// 커서 안보이게 설정
	SetCursorType(CursorType::NoCursor);

	// 싱글톤 객체 설정.
	instance = this;

	// 레벨 생성.
	startLevel = new StartLevel();
	gameLevel = new GameLevel();
	menuLevel = new MenuLevel();
	mainLevel = startLevel;
}

Game::~Game()
{
	mainLevel = nullptr;
	delete startLevel;
	delete gameLevel;
	delete menuLevel;
}

Level* Game::LoadStartLevel()
{
	return startLevel;
}

void Game::ToggleLevel(const char* Text)
{
	// 화면 지우기.
	system("cls");

	if (Text == "Resume Game" || Text == "Start Game")
	{
		mainLevel = gameLevel;
	}
	else if (Text == "Main")
	{
		mainLevel = startLevel;
	}
	else if ("Menu")
	{
		mainLevel = menuLevel;
	}
}