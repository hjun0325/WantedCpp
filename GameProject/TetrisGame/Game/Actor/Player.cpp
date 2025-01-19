#include "Player.h"
#include "Actor/Block.h"
#include "Level/GameLevel.h"
#include <Engine/Engine.h>

Player::Player(GameLevel* level)
	: refLevel(level)
{
	mainBlock = new Block();
}

Player::~Player()
{
	delete mainBlock;
}

void Player::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// 좌우 이동.
	if (Engine::Get().GetKeyDown(VK_LEFT))
	{
		if (refLevel->CanPlayerMove(Vector2(mainBlock->blockPosition.x - 1, mainBlock->blockPosition.y)))
		{
			mainBlock->blockPosition.x -= 1;
		}
	}
	if (Engine::Get().GetKeyDown(VK_RIGHT))
	{
		if (refLevel->CanPlayerMove(Vector2(mainBlock->blockPosition.x + 1, mainBlock->blockPosition.y)))
		{
			mainBlock->blockPosition.x += 1;
		}
	}

	// 소프트 드랍.
	if (Engine::Get().GetKeyDown(VK_DOWN))
	{
		if (refLevel->CanPlayerMove(Vector2(mainBlock->blockPosition.x, mainBlock->blockPosition.y + 1)))
		{
			mainBlock->blockPosition.y += 1;
		}
		// 더 이상 내려갈 수 있는 곳이 없는 경우.
		else
		{
			// 맵에 현재 블록 배치.
			refLevel->PlaceBlocksOnMap(Vector2(mainBlock->blockPosition.x, mainBlock->blockPosition.y));

			// 메인 블록에서 빼고 맵에 정수 값 2로 배치.
			if (mainBlock != nullptr)
			{
				delete mainBlock;
				mainBlock = nullptr;
			}
			mainBlock = new Block();
		}
	}

	// 하드 드랍.
	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{

	}

	// 오른쪽 90도 회전.
	if (Engine::Get().GetKeyDown(VK_UP))
	{

	}

	// 왼쪽 90도 회전.
	if (Engine::Get().GetKeyDown(VK_LCONTROL))
	{
		refLevel->RotateBlock();
	}

	// 잡기.
	if (Engine::Get().GetKeyDown(VK_LSHIFT))
	{

	}
}
