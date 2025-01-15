#include "Player.h"
#include "Engine/Engine.h"
#include"Level/GameLevel.h"

Player::Player(const Vector2& position, GameLevel* level)
	: DrawableActor("P"), refLevel(level)
{
	// 위치 설정.
	this->position = position;

	// 색상 설정.
	color = Color::White;

}

void Player::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (Engine::Get().GetkeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}

	// 상하좌우.
	if (Engine::Get().GetkeyDown(VK_LEFT))
	{
		// 이동 가능한지 확인.
		if (refLevel->CanPlayerMove(Vector2(position.x - 1, position.y)))
		{
			position.x -= 1;
		}
		//position.x = position.x < 0 ? 0 : position.x;
	}
	if (Engine::Get().GetkeyDown(VK_RIGHT))
	{
		// 이동 가능한지 확인.
		if (refLevel->CanPlayerMove(Vector2(position.x + 1, position.y)))
		{
			position.x += 1;
		}
		//position.x = position.x >= Engine::Get().ScreenSize().x ?
			//Engine::Get().ScreenSize().x : position.x;
	}
	if (Engine::Get().GetkeyDown(VK_UP))
	{
		// 이동 가능한지 확인.
		if (refLevel->CanPlayerMove(Vector2(position.x, position.y - 1)))
		{
			position.y -= 1;
		}
		//position.y = position.y < 0 ? 0 : position.y;
	}
	if (Engine::Get().GetkeyDown(VK_DOWN))
	{
		// 이동 가능한지 확인.
		if (refLevel->CanPlayerMove(Vector2(position.x, position.y + 1)))
		{
			position.y += 1;
		}
		//position.y = position.y >= Engine::Get().ScreenSize().y ?
			//Engine::Get().ScreenSize().y : position.y;
	}

}
