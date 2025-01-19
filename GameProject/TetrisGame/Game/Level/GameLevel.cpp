#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Actor/Block.h"
#include "Actor/Player.h"

// 맵 초기화 함수
void InitializeMap(Map& map) {
	// 기본 맵 데이터 (블록 타입 초기화)
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

	// 맵 초기화: 타입 설정
	for (int i = 0; i < MAP_HEIGHT; ++i) {
		for (int j = 0; j < MAP_WIDTH; ++j) {
			map.mapCells[i][j].type = baseMap[i][j];
		}
	}
}
GameLevel::GameLevel()
{
	// 맵 초기화
	InitializeMap(map);


	// 플레이어 생성.
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
	// 맵 그리기.
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
	
	// 블럭 그리기.
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
			// 벽과 블록이 충돌한 경우.
			if (map.mapCells[position.y + ix][position.x + jx].type == 1 && player->mainBlock->blockType.rotations[player->mainBlock->blockType.rotateIdx][ix][jx] == 2)
			{
				return false;
			}

			// 블록과 블록이 충돌한 경우.
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
			// 맵에 블록을 배치.
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
	// 라인을 블록이 놓여진 4군데를 확인해서 클리어가 된 곳이 있으면 해당 위치 기준으로 위쪽 라인을 아래로 내려야함.
	

	// 블록이 놓여진 4x4배열이 놓여진 y좌표값에서만 찾기.
	
	// 라인 검사 변수.
	bool lineClear[4] = { true, true, true, true };

	// 라인 검사.
	for (int ix = 0; ix < 4;++ix)
	{
		for (int jx = 1; jx < MAP_WIDTH - 1;++jx)
		{
			// 라인에 빈공간이 있는 경우.
			if (map.mapCells[position.y + ix][jx].type == 0 || map.mapCells[position.y + ix][jx].type == 1)
			{
				lineClear[ix] = false;
			}
		}
	}
	
	// 라인 지우기 및 지운 라인 기준 위 블록들 한 칸씩 내리기.
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
