#include "TestLevel.h"
#include "Engine/Engine.h"
#include "Core.h"
#include "Actor/Player.h"
#include "Actor/Enemy.h"

TestLevel::TestLevel()
{
	AddActor(new Player("<A>"));
}

TestLevel::~TestLevel()
{
}

void TestLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// 抗寇 贸府.
	if (deltaTime > 1.0f)
	{
		return;
	}

	if (Engine::Get().GetkeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}

	// 利 积己.
	static float elapsedTime = 0.0f;
	static float spawnTime = RandomPercent(1.0f, 3.0f);

	// 鸥捞赣.
	elapsedTime += deltaTime;
	if (elapsedTime < spawnTime)
	{
		return;
	}

	// 鸥捞赣 府悸.
	elapsedTime = 0.0f;
	spawnTime = RandomPercent(1.0f, 3.0f);

	// 利 积己.
	AddActor(new Enemy("[[0]]", Random(1, 10)));
}
