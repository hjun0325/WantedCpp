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
	// 화면 지우기.
	system("cls");

	// 메인 레벨을 게임 레벨로 전환.
	mainLevel = gameLevel;
}

void Game::ToggleLevel()
{
	// 화면 지우기.
	system("cls");

}
