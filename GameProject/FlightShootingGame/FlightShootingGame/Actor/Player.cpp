#include "Player.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"
#include "PreCompiledHeader/PreCompiledHeader.h"

Player::Player(const char* image)
	: Super(image)
{
	position = Vector2(0, 18);
}

void Player::Update(float deltaTime)
{
	// 부모 함수 호출.
	Super::Update(deltaTime);

	// 키 입력 처리.
	if (Engine::Get().Getkey(VK_LEFT))
	{
		// 새 위치 계산.
		Vector2 newPosition = position;
		--newPosition.x;
		if (newPosition.x < 0)
		{
			newPosition.x = 0;
		}

		SetPosition(newPosition);
	}

	if (Engine::Get().Getkey(VK_RIGHT))
	{
		// 새 위치 계산.
		Vector2 newPosition = position;
		++newPosition.x;
		if (newPosition.x > 28)
		{
			newPosition.x = 28;
		}

		SetPosition(newPosition);
	}

	//if (Engine::Get().Getkey(VK_UP))
	//{
	//	// 새 위치 계산.
	//	Vector2 newPosition = position;
	//	--newPosition.y;
	//	if (newPosition.y < 0)
	//	{
	//		newPosition.y = 0;
	//	}

	//	SetPosition(newPosition);
	//}

	//if (Engine::Get().Getkey(VK_DOWN))
	//{
	//	// 새 위치 계산.
	//	Vector2 newPosition = position;
	//	++newPosition.y;
	//	if (newPosition.y > 20)
	//	{
	//		newPosition.y = 20;
	//	}

	//	SetPosition(newPosition);
	//}
}