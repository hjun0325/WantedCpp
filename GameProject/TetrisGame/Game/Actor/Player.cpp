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

	static float leftKeyTimer = 0.0f;   // 왼쪽 키 타이머
	static float rightKeyTimer = 0.0f;  // 오른쪽 키 타이머
	static float softDropTimer = 0.0f;  // 소프트 드랍 타이머
	const float moveInterval = 0.2f;    // 0.2초마다 한 칸 이동
	const float softDropInterval = 0.1f; // 소프트 드랍 속도 (0.1초마다 한 칸)

	softDropTimer += deltaTime;

	// 좌우 이동.
	if (Engine::Get().GetKeyDown(VK_LEFT))
	{
		leftKeyTimer = moveInterval; // 즉각 이동
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
		rightKeyTimer = moveInterval; // 즉각 이동
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

	// 소프트 드랍.
	if (Engine::Get().GetKey(VK_DOWN) && softDropTimer >= softDropInterval)
	{
		if (refLevel->CanPlayerMove(Vector2(mainBlock->blockPosition.x, mainBlock->blockPosition.y + 1)))
		{
			mainBlock->blockPosition.y += 1;
		}
		// 더 이상 내려갈 수 있는 곳이 없는 경우.
		else
		{
			// 맵에 현재 블록 배치.
			refLevel->PlaceBlocksOnMap(Vector2(mainBlock->blockPosition));

			DeleteAndCreateBlock();
			refLevel->DeleteAndCreateGhostBlock();
		}

		// 타이머 초기화
		softDropTimer = 0.0f;
	}

	// 하드 드랍.
	if (Engine::Get().GetKeyDown(VK_SPACE))
	{
		int possibleN = refLevel->HardDropCanPlayerMove(mainBlock->blockPosition);
		mainBlock->blockPosition.y += possibleN;

		// 맵에 현재 블록 배치.
		refLevel->PlaceBlocksOnMap(Vector2(mainBlock->blockPosition));

		DeleteAndCreateBlock();
		refLevel->DeleteAndCreateGhostBlock();
	}

	// 0: 왼쪽 / 1: 오른쪽.
	// 오른쪽 90도 회전.
	if (Engine::Get().GetKeyDown(VK_UP))
	{
		refLevel->RotateBlock(1);

		UpdateGhostBlockPosition();
	}
	// 왼쪽 90도 회전.
	if (Engine::Get().GetKeyDown(VK_LCONTROL))
	{
		refLevel->RotateBlock(0);
		UpdateGhostBlockPosition();
	}

	// 잡기.
	if (Engine::Get().GetKeyDown(VK_LSHIFT))
	{
		// 잡고 있는 블록이 없을 경우.
		if (holdBlock == nullptr)
		{
			// 홀드 블럭에 저장.
			holdBlock = mainBlock;
			mainBlock = new Block(refLevel->MapPosition());

			// 홀드 고스트 블럭에 저장.
			refLevel->SetHoldGhostBlock(refLevel->GetGhostBlock());
			refLevel->SetGhostBlock(new GhostBlock(mainBlock, refLevel));
		}
		// 잡고 있는 블록이 있을 경우.
		else
		{
			// 홀드 블록과 메인 블록 변경.
			Block* tempBlock = nullptr;
			tempBlock = mainBlock;
			mainBlock = holdBlock;
			holdBlock = tempBlock;
			tempBlock = nullptr;

			// 홀드 고스트 블록과 메인 고스트 블록 변경.
			GhostBlock* tempGhostBlock = nullptr;
			tempGhostBlock = refLevel->GetGhostBlock();
			refLevel->SetGhostBlock(refLevel->GetHoldGhostBlock());
			refLevel->SetHoldGhostBlock(tempGhostBlock);
			tempGhostBlock = nullptr;
		}

		// 홀드 블록은 회전 및 위치 기본 상태로 변경
		holdBlock->blockType.rotateIdx = 0;
		holdBlock->blockPosition = mainBlock->blockPosition;

		// 고스트 홀드 블록 회전 및 위치 기본 상태로 변경.
		refLevel->GhostBlockReset();
		UpdateGhostBlockPosition();
	}
}

void Player::DeleteAndCreateBlock()
{
	// 메인 블록에서 빼고 맵에 배치.
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