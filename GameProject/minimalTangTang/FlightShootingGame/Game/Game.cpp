#pragma once

#include "Game.h"

// ����.
#include "Level/Level.h"
#include "Level/Menu/MainMenuLevel.h"
#include "Level/Menu/PauseMenuLevel.h"
#include "Level/Menu/WeaponSetupMenuLevel.h"
#include "Level/Game/MainGameLevel.h"

// �̱��� ���� ���� �ʱ�ȭ.
Game* Game::instance = nullptr;

Game::Game()
	:mainMenuLevel(new MainMenuLevel()),
	weaponSetupMenuLevel(new WeaponSetupMenuLevel()),
	mainGameLevel(new MainGameLevel()),
	pauseMenuLevel(new PauseMenuLevel())
{
	instance = this;

	// Ŀ�� �� ���̰� ����.
	SetCursorType(CursorType::NoCursor);

	// ���� �޴��� �ε� : ó���� ������ ���� �������� ����.
	LoadLevel(mainMenuLevel);
}

Game::~Game()
{
	delete mainMenuLevel;
	delete weaponSetupMenuLevel;
	delete mainGameLevel;
	delete pauseMenuLevel;

	LoadLevel(nullptr);	
}
void Game::ChangeLevel(Level* level)
{
	LoadLevel(level);
}

void Game::RestartGame(Level* currentLevel)
{
	delete mainGameLevel;
	mainGameLevel = new MainGameLevel();
	LoadLevel(mainGameLevel);
}

Level* Game::GetMainMenuLevel() const
{
	return mainMenuLevel;
}

Level* Game::GetWeaponSetupMenuLevel() const
{
	return weaponSetupMenuLevel;
}

Level* Game::GetPauseMenuLevel() const
{
	return pauseMenuLevel;
}

Level* Game::GetMainGameLevel() const
{
	return mainGameLevel;
}

