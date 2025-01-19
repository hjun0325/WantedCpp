#include "StartLevel.h"
#include "Game/Game.h"

StartLevel::StartLevel()
{
	// �޴� �ʱ�ȭ.
	items.emplace_back(new StartItem(
		"Start Game",
		[]() {Game::Get().ToggleLevel("Start Game");})
	);
	items.emplace_back(new StartItem(
		"Quit Game",
		[]() {Game::Get().QuitGame();})
	);

	// �޴� ���� ����.
	itemCount = (int)items.size();
}

StartLevel::~StartLevel()
{
	for (StartItem* item : items)
	{
		delete item;
	}

	items.clear();
}

void StartLevel::Update(float deltaTime)
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

void StartLevel::Draw()
{
	Super::Draw();

	// ���� ���� ���.
	Engine::Get().Draw(Vector2(0, 0), "Tetris");

	// ���� ��ȸ�ϸ鼭 �޴� �ؽ�Ʈ ���.
	for (int ix = 0; ix < itemCount; ++ix)
	{
		Engine::Get().Draw(Vector2(0, 3 + ix), items[ix]->text, ix == currentSelectedIndex ? selectedColor : unselectedColor);
	}
}
