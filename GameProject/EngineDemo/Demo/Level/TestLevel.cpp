#include "TestLevel.h"
#include "Engine/Engine.h"
#include <Windows.h>

TestLevel::TestLevel()
{
}

TestLevel::~TestLevel()
{
}

void TestLevel::Update(float deltaTime)
{
	Level::Update(deltaTime);

	if (Engine::Get().GetkeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}
}
