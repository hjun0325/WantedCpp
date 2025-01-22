#include "MainGameLevel.h"
#include "Game/Game.h"
#include "Engine/Engine.h"
#include "Actor/Player.h"

int baseMap[MAP_HEIGHT][MAP_WIDTH] =
{
	{0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1},
	{0,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1},
	{0,0,0,2,1,0,0,1,1,0,0,0,0,1,0,1,0,1,0,1},
	{0,0,1,1,0,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1},
	{0,0,1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1},
	{0,0,0,0,1,0,0,1,1,0,0,0,0,1,0,1,0,1,0,1},
	{0,0,1,1,0,0,1,0,0,0,1,0,0,1,0,1,0,1,0,1},
	{0,0,1,0,1,0,1,0,1,1,1,0,0,1,0,1,0,1,0,1},
	{0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1},
	{0,0,1,1,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1},
};

MainGameLevel::MainGameLevel()
	: mapPosition(0, 0)//, myPosition(0,0)
{
	player = new Player(Vector2(2, 2));
	AddActor(player);
}

MainGameLevel::~MainGameLevel()
{
}

void MainGameLevel::Update(float daltaTime)
{

	// ����Ű.
	if (Game::Get().GetKeyDown(VK_ESCAPE))
	{

		Game::Get().ChangeLevel(Game::Get().GetPauseMenuLevel());
	}

	if (Game::Get().GetKeyDown(VK_LEFT))
	{
		
		mapPosition.x -= 1;
		baseMap[player->Getposition().y][player->Getposition().x] = 0;
		player->Setposition(Vector2(mapPosition.x + 2, mapPosition.y + 2));
		baseMap[player->Getposition().y][player->Getposition().x] = 2;
	}

	if (Game::Get().GetKeyDown(VK_RIGHT))
	{

		mapPosition.x += 1;
		baseMap[player->Getposition().y][player->Getposition().x] = 0;
		player->Setposition(Vector2(mapPosition.x + 2, mapPosition.y + 2));
		baseMap[player->Getposition().y][player->Getposition().x] = 2;
	}

	if (Game::Get().GetKeyDown(VK_UP))
	{

		mapPosition.y -= 1;
		baseMap[player->Getposition().y][player->Getposition().x] = 0;
		player->Setposition(Vector2(mapPosition.x + 2, mapPosition.y + 2));
		baseMap[player->Getposition().y][player->Getposition().x] = 2;
	}

	if (Game::Get().GetKeyDown(VK_DOWN))
	{

		mapPosition.y += 1;
		baseMap[player->Getposition().y][player->Getposition().x] = 0;
		player->Setposition(Vector2(mapPosition.x + 2, mapPosition.y + 2));
		baseMap[player->Getposition().y][player->Getposition().x] = 2;
	}
}

void MainGameLevel::Draw()
{
	// �ܼ�â�� ����� ũ��, ���� �� ũ��. 
	// �׸���� ����� ũ�⸸.
	for (int ix = 0;ix < Engine::Get().ScreenSize().y;++ix)
	{
		for (int jx = 0; jx < Engine::Get().ScreenSize().x;++jx)
		{
			if (baseMap[mapPosition.y + ix][mapPosition.x + jx] == 2)
			{
				Engine::Get().Draw(Vector2(jx, ix), "P", Color::Red);
			}
			else {
				Engine::Get().Draw(Vector2(jx, ix), baseMap[mapPosition.y + ix][mapPosition.x + jx] == 0 ? "0" : "1");
			}
		}
	}
}