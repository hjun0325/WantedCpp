#include "GameClearLevel.h"
#include "Game/Game.h"

GameClearLevel::GameClearLevel()
{
	// �޴� �ʱ�ȭ.
	items.emplace_back(new GameClearItem(
		"Retry",
		[]() {Game::Get().ToggleLevel("Retry");})
	);

	items.emplace_back(new GameClearItem(
		"Main",
		[]() {Game::Get().ToggleLevel("Main");})
	);

	// �޴� ���� ����.
	itemCount = (int)items.size();
}

GameClearLevel::~GameClearLevel()
{
	for (GameClearItem* item : items)
	{
		delete item;
	}

	items.clear();
}

void GameClearLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// ���Ʒ� ����Ű.
	if (Game::Get().GetKeyDown(VK_UP))
	{
		// �ε��� ��ȯ.
		currentSelectedIndex
			= (currentSelectedIndex - 1 + itemCount) % itemCount;
	}

	if (Game::Get().GetKeyDown(VK_DOWN))
	{
		currentSelectedIndex
			= (currentSelectedIndex + 1 + itemCount) % itemCount;
	}

	// ����Ű.
	if (Game::Get().GetKeyDown(VK_RETURN))
	{
		items[currentSelectedIndex]->onSelected();
	}
}

void GameClearLevel::Draw()
{
	Super::Draw();

	// ���� ���� ���.
	Engine::Get().Draw(Vector2(0, 0), "Game Clear!");

	char timerBuffer[20];
	record = record * 100 / 100;
	snprintf(timerBuffer, 20, "Timer: %.1f", record);
	// ��� ǥ��.
	Engine::Get().Draw(Vector2(0, 2), timerBuffer);

	// ���� ��ȸ�ϸ鼭 �޴� �ؽ�Ʈ ���.
	for (int ix = 0; ix < itemCount; ++ix)
	{
		Engine::Get().Draw(Vector2(0, 3 + ix), items[ix]->text, ix == currentSelectedIndex ? selectedColor : unselectedColor);
	}
}
