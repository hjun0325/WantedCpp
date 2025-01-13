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
	// �θ� �Լ� ȣ��.
	Super::Update(deltaTime);

	// Ű �Է� ó��.
	if (Engine::Get().Getkey(VK_LEFT))
	{
		// �� ��ġ ���.
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
		// �� ��ġ ���.
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
	//	// �� ��ġ ���.
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
	//	// �� ��ġ ���.
	//	Vector2 newPosition = position;
	//	++newPosition.y;
	//	if (newPosition.y > 20)
	//	{
	//		newPosition.y = 20;
	//	}

	//	SetPosition(newPosition);
	//}
}