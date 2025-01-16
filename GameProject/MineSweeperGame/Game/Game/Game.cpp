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
	//delete startLevel;
	delete gameLevel;
	delete menuLevel;
}

Level* Game::LoadStartLevel()
{
	return startLevel;
}

void Game::PlayGame()
{
	// ȭ�� �����.
	system("cls");

	// ���� ������ ���� ������ ��ȯ.
	mainLevel = gameLevel;
}

void Game::ToggleLevel()
{
	// ȭ�� �����.
	system("cls");

}
