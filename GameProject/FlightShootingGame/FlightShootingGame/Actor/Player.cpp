#include "Player.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"
#include "PreCompiledHeader/PreCompiledHeader.h"
#include "PlayerBullet.h"

Player::Player(const char* image)
	: Super(image)
{
	// �÷��̾� ���� ��ġ.
	//position = Vector2(0, 20);
	position = Vector2(0, Engine::Get().ScreenSize().y - 1);
}

void Player::Update(float deltaTime)
{
	// �θ� �Լ� ȣ��.
	Super::Update(deltaTime);

	// ź�� �߻�.
	if (Engine::Get().GetkeyDown(VK_SPACE))
	{
		Vector2 bulletPosition(position.x + (width / 2), position.y);
		Engine::Get().AddActor(new PlayerBullet(bulletPosition));
	}

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
		if (newPosition.x > Engine::Get().ScreenSize().x - width)
		{
			newPosition.x = Engine::Get().ScreenSize().x - width;
		}

		SetPosition(newPosition);
	}
}