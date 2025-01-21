#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Actor/GhostBlock.h"
#include "Actor/Block.h"
#include "Actor/Player.h"

int GameLevel::lineClearCount = 0;

// 맵 초기화 함수.
void InitializeMap(Map& map) {
	// 기본 맵 데이터 (블록 타입 초기화).
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

	// 맵 초기화: 타입 설정.
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
	// 맵 초기화
	InitializeMap(map);


	// 플레이어 생성.
	player = new Player(this);
	AddActor(player);

	// 고스트 블록 생성.
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

	// 게임 오버시 레벨 전환.
	if (gameOver == true)
	{
		Game::Get().LoadLevel(Game::Get().GetGameOverLevel());
	}

	// 게임 클리어시 레벨 전환.
	if (lineClearCount >= 40)
	{
		lineClearCount = 0;
		Game::Get().SaveRecord(currentTime);
		Game::Get().LoadLevel(Game::Get().GetGameClearLevel());
	}

	// 1초에 한 칸씩 내려가기 위한 속도와 타이머 설정
	static float moveTimer = 0.0f; // 타이머를 누적해서 계산
	const float moveInterval = 1.0f; // 1초에 한 번 이동

	// 타이머 업데이트
	moveTimer += deltaTime;

	if (moveTimer >= moveInterval)
	{
		if (CanPlayerMove(Vector2(player->mainBlock->blockPosition.x, player->mainBlock->blockPosition.y + 1)))
		{
			player->mainBlock->blockPosition.y += 1;
		}
		// 더 이상 내려갈 수 있는 곳이 없는 경우.
		else
		{
			// 맵에 현재 블록 배치.
			PlaceBlocksOnMap(Vector2(player->mainBlock->blockPosition.x, player->mainBlock->blockPosition.y));

			player->DeleteAndCreateBlock();

			DeleteAndCreateGhostBlock();

		}
		moveTimer -= moveInterval; // 남은 시간만큼 타이머 초기화
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

	// 블록 그리기.
	for (int ix = 0;ix < 4;++ix)
	{
		for (int jx = 0;jx < 4;++jx)
		{
			// 고스트 블록 그리기.
			Engine::Get().Draw(
				Vector2(ghostBlock->blockPosition.x + jx, ghostBlock->blockPosition.y + ix),
				ghostBlock->ghostBlockType.rotations[ghostBlock->ghostBlockType.rotateIdx][ix][jx] == 3 ? "0" : "",
				ghostBlock->ghostBlockType.color);

			// 메인 블록 그리기.
			Engine::Get().Draw(
				Vector2(player->mainBlock->blockPosition.x + jx, player->mainBlock->blockPosition.y + ix),
				player->mainBlock->blockType.rotations[player->mainBlock->blockType.rotateIdx][ix][jx] == 2 ? "0" : "",
				player->mainBlock->blockType.color);
		}
	}

	// 홀드 블록 그리기.
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

	// 라인 클리어 개수 표시.
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
			// 벽과 블록이 충돌한 경우.
			if (map.mapCells[position.y - mapPosition.y + ix][position.x - mapPosition.x + jx].type == 1 && player->mainBlock->blockType.rotations[player->mainBlock->blockType.rotateIdx][ix][jx] == 2)
			{
				return false;
			}

			// 블록과 블록이 충돌한 경우.
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
			// 맵에 블록을 배치.
			if (map.mapCells[position.y - mapPosition.y + ix][position.x - mapPosition.x + jx].type == 0 && player->mainBlock->blockType.rotations[player->mainBlock->blockType.rotateIdx][ix][jx] == 2)
			{
				// 메인 블록이 맵의 위쪽 범위를 벗어나면 게임 오버.
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
	// 블록이 놓여진 4x4배열이 놓여진 y좌표값에서만 찾기.

	// 라인 검사 변수.
	bool lineClear[4] = { true, true, true, true };

	// 라인 검사.
	for (int ix = 0; ix < 4;++ix)
	{
		for (int jx = 1; jx < MAP_WIDTH - 1;++jx)
		{
			// 라인에 빈공간이 있는 경우.
			if (map.mapCells[position.y - mapPosition.y + ix][jx].type == 0 || map.mapCells[position.y - mapPosition.y + ix][jx].type == 1)
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
			// 라인 클리어 개수 증가.
			++lineClearCount;

			// 블록 한칸씩 내리기.
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
	// 왼쪽으로 회전.
	if (LR == 0)
	{
		// 메인 블록 회전 인덱스 설정.
		player->mainBlock->blockType.rotateIdx = (player->mainBlock->blockType.rotateIdx + 3) % 4;

		// 회전한 메인 블록과 맵, 다른 블록간의 충돌 검사 (회전이 바로 안되는 경우, 반복).
		while (!CanPlayerMove(player->mainBlock->blockPosition))
		{
			// 맵의 중앙을 기준으로 블록이 왼쪽에 있는 경우.
			if ((mapPosition.x + MAP_WIDTH / 2) > player->mainBlock->blockPosition.x)
			{
				player->mainBlock->blockPosition.x += 1;
				ghostBlock->blockPosition.x += 1;
			}
			// 맵의 중앙을 기준으로 블록이 오른쪽에 있는 경우.
			else
			{
				player->mainBlock->blockPosition.x -= 1;
				ghostBlock->blockPosition.x -= 1;
			}
		}

		ghostBlock->ghostBlockType.rotateIdx = (ghostBlock->ghostBlockType.rotateIdx + 3) % 4;
	}
	// 오른쪽으로 회전.
	else
	{
		player->mainBlock->blockType.rotateIdx = (player->mainBlock->blockType.rotateIdx + 1) % 4;

		// 회전한 메인 블록과 맵과 다른 블록간의 충돌 검사 (회전이 바로 안되는 경우, 반복).
		while (!CanPlayerMove(player->mainBlock->blockPosition))
		{
			// 맵의 중앙을 기준으로 블록이 왼쪽에 있는 경우.
			if ((mapPosition.x + MAP_WIDTH / 2) > player->mainBlock->blockPosition.x)
			{
				player->mainBlock->blockPosition.x += 1;
				ghostBlock->blockPosition.x += 1;
			}
			// 맵의 중앙을 기준으로 블록이 오른쪽에 있는 경우.
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
