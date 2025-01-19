#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Actor/Block.h"
#include "Actor/Player.h"

// �� �ʱ�ȭ �Լ�
void InitializeMap(Map& map) {
	// �⺻ �� ������ (��� Ÿ�� �ʱ�ȭ)
	int baseMap[MAP_HEIGHT][MAP_WIDTH] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,1,1,1,1,1,1,1,1,1,1,1,},
	};

	// �� �ʱ�ȭ: Ÿ�� ����
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			map.mapCells[i][j].type = baseMap[i][j];
		}
	}
}
GameLevel::GameLevel()
{
	// �� �ʱ�ȭ
	InitializeMap(map);


	// �÷��̾� ����.
	player = new Player(this);
	AddActor(player);
}

GameLevel::~GameLevel()
{
}

void GameLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Game::Get().ToggleLevel("Menu");
	}
}

void GameLevel::Draw()
{
	// �� �׸���.
	for (int ix = 0;ix < MAP_HEIGHT;++ix)
	{
		for (int jx = 0;jx < MAP_WIDTH;++jx)
		{
			if (map.mapCells[ix][jx].type == 2)
			{
				Engine::Get().Draw(Vector2(0 + jx, 0 + ix), "*", map.mapCells[ix][jx].color);
			}
			else
			{
				Engine::Get().Draw(Vector2(0 + jx, 0 + ix), map.mapCells[ix][jx].type == 1 ? "#" : " ");
			}
		}
	}
	
	// �� �׸���.
	for (int ix = 0;ix < 4;++ix)
	{
		for (int jx = 0;jx < 4;++jx)
		{
			Engine::Get().Draw(
				Vector2(player->mainBlock->blockPosition.x + jx, player->mainBlock->blockPosition.y + ix),
				player->mainBlock->blockType.rotations[player->mainBlock->blockType.rotateIdx][ix][jx] == 2 ? "*" : "",
				player->mainBlock->blockType.color);
		}
	}

	//char buffer[256];
	//snprintf(buffer, 256, "mousePosition: (%d,%d) ", Engine::Get().MousePosition().x, Engine::Get().MousePosition().y);
	//Engine::Get().Draw(Vector2(15, 0), buffer);
}

bool GameLevel::CanPlayerMove(const Vector2& position)
{
 	for (int ix = 0;ix < 4;++ix)
	{
		for (int jx = 0;jx < 4;++jx)
		{
			// ���� ����� �浹�� ���.
			if (map.mapCells[position.y + ix][position.x + jx].type == 1 && player->mainBlock->blockType.rotations[player->mainBlock->blockType.rotateIdx][ix][jx] == 2)
			{
				return false;
			}

			// ��ϰ� ����� �浹�� ���.
			if (map.mapCells[position.y + ix][position.x + jx].type == 2 && player->mainBlock->blockType.rotations[player->mainBlock->blockType.rotateIdx][ix][jx] == 2)
			{
				return false;
			}
		}
	}

	return true;
}

void GameLevel::PlaceBlocksOnMap(const Vector2& position)
{
	for (int ix = 0;ix < 4;++ix)
	{
		for (int jx = 0;jx < 4;++jx)
		{
			// �ʿ� ����� ��ġ.
			if (map.mapCells[position.y + ix][position.x + jx].type == 0 && player->mainBlock->blockType.rotations[player->mainBlock->blockType.rotateIdx][ix][jx] == 2)
			{
				map.mapCells[position.y + ix][position.x + jx].type = 2;
				map.mapCells[position.y + ix][position.x + jx].color = player->mainBlock->blockType.color;
			}
		}
	}

	LineClear(position);
}

void GameLevel::LineClear(const Vector2& position)
{
	// ������ ����� ������ 4������ Ȯ���ؼ� Ŭ��� �� ���� ������ �ش� ��ġ �������� ���� ������ �Ʒ��� ��������.
	

	// ����� ������ 4x4�迭�� ������ y��ǥ�������� ã��.
	
	// ���� �˻� ����.
	bool lineClear[4] = { true, true, true, true };

	// ���� �˻�.
	for (int ix = 0; ix < 4;++ix)
	{
		for (int jx = 1; jx < MAP_WIDTH - 1;++jx)
		{
			// ���ο� ������� �ִ� ���.
			if (map.mapCells[position.y + ix][jx].type == 0 || map.mapCells[position.y + ix][jx].type == 1)
			{
				lineClear[ix] = false;
			}
		}
	}
	
	// ���� ����� �� ���� ���� ���� �� ��ϵ� �� ĭ�� ������.
	for (int ix = 0; ix < 4;++ix)
	{
		if (lineClear[ix] == true) 
		{
			for (int jx = position.y + ix - 1; jx > 0;--jx)
			{
				for (int kx = 1;kx < MAP_WIDTH - 1;++kx)
				{
					map.mapCells[jx + 1][kx].type = map.mapCells[jx][kx].type;
					map.mapCells[jx + 1][kx].color = map.mapCells[jx][kx].color;
				}
			}
		}
	}
	
}

void GameLevel::RotateBlock()
{
	player->mainBlock->blockType.rotateIdx = (player->mainBlock->blockType.rotateIdx + 3) % 4;
}
