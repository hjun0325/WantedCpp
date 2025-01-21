#include "GameOverLevel.h"
#include "Game/Game.h"

GameOverLevel::GameOverLevel()
{
	// �޴� �ʱ�ȭ.
	items.emplace_back(new GameOverItem(
		"Retry",
		[]() {Game::Get().ToggleLevel("Retry");})
	);

	items.emplace_back(new GameOverItem(
		"Main",
		[]() {Game::Get().ToggleLevel("Main");})
	);

	// �޴� ���� ����.
	itemCount = (int)items.size();
}

GameOverLevel::~GameOverLevel()
{
	for (GameOverItem* item : items)
	{
		delete item;
	}

	items.clear();
}

void GameOverLevel::Update(float deltaTime)
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

void GameOverLevel::Draw()
{
	Super::Draw();

	// ���� ���� ���.
	Engine::Get().Draw(Vector2(0, 0), "Game Over...");

	// ���� ��ȸ�ϸ鼭 �޴� �ؽ�Ʈ ���.
	for (int ix = 0; ix < itemCount; ++ix)
	{
		Engine::Get().Draw(Vector2(0, 3 + ix), items[ix]->text, ix == currentSelectedIndex ? selectedColor : unselectedColor);
	}
}
