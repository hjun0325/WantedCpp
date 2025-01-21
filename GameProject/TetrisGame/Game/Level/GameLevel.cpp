#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Actor/GhostBlock.h"
#include "Actor/Block.h"
#include "Actor/Player.h"

int GameLevel::lineClearCount = 0;

// �� �ʱ�ȭ �Լ�.
void InitializeMap(Map& map) {
	// �⺻ �� ������ (��� Ÿ�� �ʱ�ȭ).
	int baseMap[MAP_HEIGHT][MAP_WIDTH] = {
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
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,0,0,0,0,0,0,0,0,0,0,1,},
		{1,1,1,1,1,1,1,1,1,1,1,1,},
	};

	// �� �ʱ�ȭ: Ÿ�� ����.
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			map.mapCells[i][j].type = baseMap[i][j];
		}
	}
}
GameLevel::GameLevel()
	: mapPosition(Engine::Get().ScreenSize().x / 2 - MAP_WIDTH / 2, Engine::Get().ScreenSize().y / 2 - MAP_HEIGHT / 2)
	//: mapPosition(0, 0)
{
	// �� �ʱ�ȭ
	InitializeMap(map);


	// �÷��̾� ����.
	player = new Player(this);
	AddActor(player);

	// ��Ʈ ��� ����.
	ghostBlock = new GhostBlock(player->mainBlock, this);

	timer.SetTime(0.01f);
}

GameLevel::~GameLevel()
{
	if (ghostBlock != nullptr)
	{
		delete ghostBlock;
		ghostBlock = nullptr;
	}

	if (holdGhostBlock != nullptr)
	{
		delete holdGhostBlock;
		holdGhostBlock = nullptr;
	}
}

void GameLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	timer.Update(deltaTime);
	if (timer.IsTimeOut())
	{
		currentTime += 0.01f;
		timer.Reset();
	}
	
	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Game::Get().ToggleLevel("Menu");
	}

	// ���� ������ ���� ��ȯ.
	if (gameOver == true)
	{
		Game::Get().LoadLevel(Game::Get().GetGameOverLevel());
	}

	// ���� Ŭ����� ���� ��ȯ.
	if (lineClearCount >= 40)
	{
		lineClearCount = 0;
		Game::Get().SaveRecord(currentTime);
		Game::Get().LoadLevel(Game::Get().GetGameClearLevel());
	}

	// 1�ʿ� �� ĭ�� �������� ���� �ӵ��� Ÿ�̸� ����
	static float moveTimer = 0.0f; // Ÿ�̸Ӹ� �����ؼ� ���
	const float moveInterval = 1.0f; // 1�ʿ� �� �� �̵�

	// Ÿ�̸� ������Ʈ
	moveTimer += deltaTime;

	if (moveTimer >= moveInterval)
	{
		if (CanPlayerMove(Vector2(player->mainBlock->blockPosition.x, player->mainBlock->blockPosition.y + 1)))
		{
			player->mainBlock->blockPosition.y += 1;
		}
		// �� �̻� ������ �� �ִ� ���� ���� ���.
		else
		{
			// �ʿ� ���� ��� ��ġ.
			PlaceBlocksOnMap(Vector2(player->mainBlock->blockPosition.x, player->mainBlock->blockPosition.y));

			player->DeleteAndCreateBlock();

			DeleteAndCreateGhostBlock();

		}
		moveTimer -= moveInterval; // ���� �ð���ŭ Ÿ�̸� �ʱ�ȭ
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
				Engine::Get().Draw(Vector2(mapPosition.x + jx, mapPosition.y + ix), "0", map.mapCells[ix][jx].color);
			}
			else
			{
				if (ix == 0 || ix == 1)
				{
					Engine::Get().Draw(Vector2(mapPosition.x + jx, mapPosition.y + ix), " ");
				}
				else
				{
					Engine::Get().Draw(Vector2(mapPosition.x + jx, mapPosition.y + ix), map.mapCells[ix][jx].type == 1 ? "#" : " ");
				}
			}
		}
	}

	// ��� �׸���.
	for (int ix = 0;ix < 4;++ix)
	{
		for (int jx = 0;jx < 4;++jx)
		{
			// ��Ʈ ��� �׸���.
			Engine::Get().Draw(
				Vector2(ghostBlock->blockPosition.x + jx, ghostBlock->blockPosition.y + ix),
				ghostBlock->ghostBlockType.rotations[ghostBlock->ghostBlockType.rotateIdx][ix][jx] == 3 ? "0" : "",
				ghostBlock->ghostBlockType.color);

			// ���� ��� �׸���.
			Engine::Get().Draw(
				Vector2(player->mainBlock->blockPosition.x + jx, player->mainBlock->blockPosition.y + ix),
				player->mainBlock->blockType.rotations[player->mainBlock->blockType.rotateIdx][ix][jx] == 2 ? "0" : "",
				player->mainBlock->blockType.color);
		}
	}

	// Ȧ�� ��� �׸���.
	Engine::Get().Draw(
		Vector2(mapPosition.x - 5, mapPosition.y + 2), "HOLD"
	);

	if (player->holdBlock != nullptr)
	{
		for (int ix = 0;ix < 4;++ix)
		{
			for (int jx = 0;jx < 4;++jx)
			{
				Engine::Get().Draw(
					Vector2(mapPosition.x - 5 + jx, mapPosition.y + 3 + ix), player->holdBlock->blockType.rotations[player->holdBlock->blockType.rotateIdx][ix][jx] == 2 ? "0" : ""
				);
			}
		}
	}

	// ���� Ŭ���� ���� ǥ��.
	Engine::Get().Draw(
		Vector2(mapPosition.x - 16, mapPosition.y + 15), "LineClear: "
	);

	char countBuffer[10];
	snprintf(countBuffer, 10, "%d", lineClearCount);
	Engine::Get().Draw(
		Vector2(lineClearCount > 9 ? mapPosition.x - 6 : mapPosition.x - 5, mapPosition.y + 15), countBuffer > "40" ? "40" : countBuffer
	);

	Engine::Get().Draw(
		Vector2(mapPosition.x - 4, mapPosition.y + 15), "/40"
	);

	char timerBuffer[20];
	currentTime = currentTime * 100 / 100;
	snprintf(timerBuffer, 20, "Timer: %f", currentTime);
	Engine::Get().Draw(
		Vector2(mapPosition.x - 16, mapPosition.y + 16), timerBuffer
	);

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
			if (map.mapCells[position.y - mapPosition.y + ix][position.x - mapPosition.x + jx].type == 1 && player->mainBlock->blockType.rotations[player->mainBlock->blockType.rotateIdx][ix][jx] == 2)
			{
				return false;
			}

			// ��ϰ� ����� �浹�� ���.
			if (map.mapCells[position.y - mapPosition.y + ix][position.x - mapPosition.x + jx].type == 2 && player->mainBlock->blockType.rotations[player->mainBlock->blockType.rotateIdx][ix][jx] == 2)
			{
				return false;
			}
		}
	}

	return true;
}

int GameLevel::HardDropCanPlayerMove(const Vector2& position)
{
	int possibleN = -1;
	while (CanPlayerMove(Vector2(position.x, position.y + possibleN + 1)))
	{
		possibleN += 1;
	}

	return possibleN;
}

void GameLevel::PlaceBlocksOnMap(const Vector2& position)
{
	for (int ix = 0;ix < 4;++ix)
	{
		for (int jx = 0;jx < 4;++jx)
		{
			// �ʿ� ����� ��ġ.
			if (map.mapCells[position.y - mapPosition.y + ix][position.x - mapPosition.x + jx].type == 0 && player->mainBlock->blockType.rotations[player->mainBlock->blockType.rotateIdx][ix][jx] == 2)
			{
				// ���� ����� ���� ���� ������ ����� ���� ����.
				if (position.y < mapPosition.y + 1)
				{
					gameOver = true;
				}
				map.mapCells[position.y - mapPosition.y + ix][position.x - mapPosition.x + jx].type = 2;
				map.mapCells[position.y - mapPosition.y + ix][position.x - mapPosition.x + jx].color = player->mainBlock->blockType.color;
			}
		}
	}

	LineClear(position);
}

void GameLevel::LineClear(const Vector2& position)
{
	// ����� ������ 4x4�迭�� ������ y��ǥ�������� ã��.

	// ���� �˻� ����.
	bool lineClear[4] = { true, true, true, true };

	// ���� �˻�.
	for (int ix = 0; ix < 4;++ix)
	{
		for (int jx = 1; jx < MAP_WIDTH - 1;++jx)
		{
			// ���ο� ������� �ִ� ���.
			if (map.mapCells[position.y - mapPosition.y + ix][jx].type == 0 || map.mapCells[position.y - mapPosition.y + ix][jx].type == 1)
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
			// ���� Ŭ���� ���� ����.
			++lineClearCount;

			// ��� ��ĭ�� ������.
			for (int jx = position.y - mapPosition.y + ix - 1; jx > 0;--jx)
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

void GameLevel::RotateBlock(int LR)
{
	// �������� ȸ��.
	if (LR == 0)
	{
		// ���� ��� ȸ�� �ε��� ����.
		player->mainBlock->blockType.rotateIdx = (player->mainBlock->blockType.rotateIdx + 3) % 4;

		// ȸ���� ���� ��ϰ� ��, �ٸ� ��ϰ��� �浹 �˻� (ȸ���� �ٷ� �ȵǴ� ���, �ݺ�).
		while (!CanPlayerMove(player->mainBlock->blockPosition))
		{
			// ���� �߾��� �������� ����� ���ʿ� �ִ� ���.
			if ((mapPosition.x + MAP_WIDTH / 2) > player->mainBlock->blockPosition.x)
			{
				player->mainBlock->blockPosition.x += 1;
				ghostBlock->blockPosition.x += 1;
			}
			// ���� �߾��� �������� ����� �����ʿ� �ִ� ���.
			else
			{
				player->mainBlock->blockPosition.x -= 1;
				ghostBlock->blockPosition.x -= 1;
			}
		}

		ghostBlock->ghostBlockType.rotateIdx = (ghostBlock->ghostBlockType.rotateIdx + 3) % 4;
	}
	// ���������� ȸ��.
	else
	{
		player->mainBlock->blockType.rotateIdx = (player->mainBlock->blockType.rotateIdx + 1) % 4;

		// ȸ���� ���� ��ϰ� �ʰ� �ٸ� ��ϰ��� �浹 �˻� (ȸ���� �ٷ� �ȵǴ� ���, �ݺ�).
		while (!CanPlayerMove(player->mainBlock->blockPosition))
		{
			// ���� �߾��� �������� ����� ���ʿ� �ִ� ���.
			if ((mapPosition.x + MAP_WIDTH / 2) > player->mainBlock->blockPosition.x)
			{
				player->mainBlock->blockPosition.x += 1;
				ghostBlock->blockPosition.x += 1;
			}
			// ���� �߾��� �������� ����� �����ʿ� �ִ� ���.
			else
			{
				player->mainBlock->blockPosition.x -= 1;
				ghostBlock->blockPosition.x -= 1;
			}
		}

		ghostBlock->ghostBlockType.rotateIdx = (ghostBlock->ghostBlockType.rotateIdx + 1) % 4;
	}
}

void GameLevel::DeleteAndCreateGhostBlock()
{
	if (ghostBlock != nullptr)
	{
		delete ghostBlock;
		ghostBlock = nullptr;
	}
	ghostBlock = new GhostBlock(player->mainBlock, this);
}

void GameLevel::SetGhostBlockPosition(int V)
{
	ghostBlock->blockPosition.x += V;
}

void GameLevel::GhostBlockReset()
{
	ghostBlock->ghostBlockType.rotateIdx = 0;
	ghostBlock->blockPosition = player->mainBlock->blockPosition;
}
