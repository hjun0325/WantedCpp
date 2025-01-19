#include "Game.h"
#include "Level/StartLevel.h"
#include "Level/GameLevel.h"
#include "Level/MenuLevel.h"

Game* Game::instance = nullptr;

Game::Game()
{
	// Ŀ�� �Ⱥ��̰� ����
	SetCursorType(CursorType::NoCursor);

	// �̱��� ��ü ����.
	instance = this;

	// ���� ����.
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
	// ȭ�� �����.
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