#include "Player.h"
#include "Block.h"
#include "GhostBlock.h"
#include "Level/GameLevel.h"
#include <Engine/Engine.h>

Player::Player(GameLevel* level)
	: refLevel(level)
{
	mainBlock = new Block(refLevel->MapPosition());
}

Player::~Player()
{
	if (mainBlock != nullptr)
	{
		delete mainBlock;
		mainBlock = nullptr;
	}

	if (holdBlock != nullptr)
	{
		delete holdBlock;
		holdBlock = nullptr;
	}
}

void Player::Update(float deltaTime)
{
	Super::Update(deltaTime);

	static float leftKeyTimer = 0.0f;   // ���� Ű Ÿ�̸�
	static float rightKeyTimer = 0.0f;  // ������ Ű Ÿ�̸�
	static float softDropTimer = 0.0f;  // ����Ʈ ��� Ÿ�̸�
	const float moveInterval = 0.2f;    // 0.2�ʸ��� �� ĭ �̵�
	const float softDropInterval = 0.1f; // ����Ʈ ��� �ӵ� (0.1�ʸ��� �� ĭ)

	softDropTimer += deltaTime;

	// �¿� �̵�.
	if (Engine::Get().GetKeyDown(VK_LEFT))
	{
		leftKeyTimer = moveInterval; // �ﰢ �̵�
		if (refLevel->CanPlayerMove(Vector2(mainBlock->blockPosition.x - 1, mainBlock->blockPosition.y)))
		{
			mainBlock->blockPosition.x -= 1;
			refLevel->SetGhostBlockPosition(-1);
			UpdateGhostBlockPosition();
		}
	}
	if (Engine::Get().GetKey(VK_LEFT))
	{
		leftKeyTimer -= deltaTime;
		if (leftKeyTimer <= 0.0f)
		{
			if (refLevel->CanPlayerMove(Vector2(mainBlock->blockPosition.x - 1, mainBlock->blockPosition.y)))
			{
				mainBlock->blockPosition.x -= 1;
				refLevel->SetGhostBlockPosition(-1);
				UpdateGhostBlockPosition();
			}
		}
	}

	if (Engine::Get().GetKeyDown(VK_RIGHT))
	{
		rightKeyTimer = moveInterval; // �ﰢ �̵�
		if (refLevel->CanPlayerMove(Vector2(mainBlock->blockPosition.x + 1, mainBlock->blockPosition.y)))
		{
			mainBlock->blockPosition.x += 1;
			refLevel->SetGhostBlockPosition(1);
			UpdateGhostBlockPosition();
		}
	}
	if (Engine::Get().GetKey(VK_RIGHT))
	{
		rightKeyTimer -= deltaTime;
		if (rightKeyTimer <= 0.0f)
		{
			if (refLevel->CanPlayerMove(Vector2(mainBlock->blockPosition.x + 1, mainBlock->blockPosition.y)))
			{
				mainBlock->blockPosition.x += 1;
				refLevel->SetGhostBlockPosition(1);
				UpdateGhostBlockPosition();
			}
		}
	}

	// ����Ʈ ���.
	if (Engine::Get().GetKey(VK_DOWN) && softDropTimer >= softDropInterval)
	{
		if (refLevel->CanPlayerMove(Vector2(mainBlock->blockPosition.x, mainBlock->blockPosition.y + 1)))
		{
			mainBlock->blockPosition.y += 1;
		}
		// �� �̻� ������ �� �ִ� ���� ���� ���.
		else
		{
			// �ʿ� ���� ��� ��ġ.
			refLevel->PlaceBlocksOnMap(Vector2(mainBlock->blockPosition));

			DeleteAndCreateBlock();
			refLevel->DeleteAndCreateGhostBlock();
		}

		// Ÿ�̸� �ʱ�ȭ
		softDropTimer = 0.0f;
	}

	// �ϵ� ���.
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		int possibleN = refLevel->HardDropCanPlayerMove(mainBlock->blockPosition);
		mainBlock->blockPosition.y += possibleN;

		// �ʿ� ���� ��� ��ġ.
		refLevel->PlaceBlocksOnMap(Vector2(mainBlock->blockPosition));

		DeleteAndCreateBlock();
		refLevel->DeleteAndCreateGhostBlock();
	}

	// 0: ���� / 1: ������.
	// ������ 90�� ȸ��.
	if (Engine::Get().GetKeyDown(VK_UP))
	{
		refLevel->RotateBlock(1);

		UpdateGhostBlockPosition();
	}
	// ���� 90�� ȸ��.
	if (Engine::Get().GetKeyDown(VK_LCONTROL))
	{
		refLevel->RotateBlock(0);
		UpdateGhostBlockPosition();
	}

	// ���.
	if (Engine::Get().GetKeyDown(VK_LSHIFT))
	{
		// ��� �ִ� ����� ���� ���.
		if (holdBlock == nullptr)
		{
			// Ȧ�� ���� ����.
			holdBlock = mainBlock;
			mainBlock = new Block(refLevel->MapPosition());

			// Ȧ�� ��Ʈ ���� ����.
			refLevel->SetHoldGhostBlock(refLevel->GetGhostBlock());
			refLevel->SetGhostBlock(new GhostBlock(mainBlock, refLevel));
		}
		// ��� �ִ� ����� ���� ���.
		else
		{
			// Ȧ�� ��ϰ� ���� ��� ����.
			Block* tempBlock = nullptr;
			tempBlock = mainBlock;
			mainBlock = holdBlock;
			holdBlock = tempBlock;
			tempBlock = nullptr;

			// Ȧ�� ��Ʈ ��ϰ� ���� ��Ʈ ��� ����.
			GhostBlock* tempGhostBlock = nullptr;
			tempGhostBlock = refLevel->GetGhostBlock();
			refLevel->SetGhostBlock(refLevel->GetHoldGhostBlock());
			refLevel->SetHoldGhostBlock(tempGhostBlock);
			tempGhostBlock = nullptr;
		}

		// Ȧ�� ����� ȸ�� �� ��ġ �⺻ ���·� ����
		holdBlock->blockType.rotateIdx = 0;
		holdBlock->blockPosition = mainBlock->blockPosition;

		// ��Ʈ Ȧ�� ��� ȸ�� �� ��ġ �⺻ ���·� ����.
		refLevel->GhostBlockReset();
		UpdateGhostBlockPosition();
	}
}

void Player::DeleteAndCreateBlock()
{
	// ���� ��Ͽ��� ���� �ʿ� ��ġ.
	if (mainBlock != nullptr)
	{
		delete mainBlock;
		mainBlock = nullptr;
	}
	mainBlock = new Block(refLevel->MapPosition());
}

void Player::UpdateGhostBlockPosition()
{
	refLevel->GetGhostBlock()->blockPosition.y = mainBlock->blockPosition.y;
	int possibleN = refLevel->HardDropCanPlayerMove(refLevel->GetGhostBlock()->blockPosition);
	refLevel->GetGhostBlock()->blockPosition.y += possibleN;
}