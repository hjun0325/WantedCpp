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

	// �¿� �̵�.
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

	// ����Ʈ ���.
	if (Engine::Get().GetKeyDown(VK_DOWN))
	{
		if (refLevel->CanPlayerMove(Vector2(mainBlock->blockPosition.x, mainBlock->blockPosition.y + 1)))
		{
			mainBlock->blockPosition.y += 1;
		}
		// �� �̻� ������ �� �ִ� ���� ���� ���.
		else
		{
			// �ʿ� ���� ��� ��ġ.
			refLevel->PlaceBlocksOnMap(Vector2(mainBlock->blockPosition.x, mainBlock->blockPosition.y));

			// ���� ��Ͽ��� ���� �ʿ� ���� �� 2�� ��ġ.
			if (mainBlock != nullptr)
			{
				delete mainBlock;
				mainBlock = nullptr;
			}
			mainBlock = new Block();
		}
	}

	// �ϵ� ���.
	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{

	}

	// ������ 90�� ȸ��.
	if (Engine::Get().GetKeyDown(VK_UP))
	{

	}

	// ���� 90�� ȸ��.
	if (Engine::Get().GetKeyDown(VK_LCONTROL))
	{
		refLevel->RotateBlock();
	}

	// ���.
	if (Engine::Get().GetKeyDown(VK_LSHIFT))
	{

	}
}
