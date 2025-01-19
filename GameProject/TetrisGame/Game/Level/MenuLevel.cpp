#include "MenuLevel.h"
#include "Game/Game.h"

MenuLevel::MenuLevel()
{
	// �޴� �ʱ�ȭ.
	items.emplace_back(new MenuItem(
		"Resume Game",
		[]() {Game::Get().ToggleLevel("Resume Game");})
	);
	items.emplace_back(new MenuItem(
		"Main",
		[]() {Game::Get().ToggleLevel("Main");})
	);

	// �޴� ���� ����.
	itemCount = (int)items.size();
}

MenuLevel::~MenuLevel()
{
	for (MenuItem* item : items)
	{
		delete item;
	}

	items.clear();
}

void MenuLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Game::Get().ToggleLevel("Resume Game");
	}

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

void MenuLevel::Draw()
{
	Super::Draw();

	// �޴� ���� ���.
	Engine::Get().Draw(Vector2(0, 0), "Menu");

	// ���� ��ȸ�ϸ鼭 �޴� �ؽ�Ʈ ���.
	for (int ix = 0; ix < itemCount; ++ix)
	{
		Engine::Get().Draw(Vector2(0, 2 + ix), items[ix]->text, ix == currentSelectedIndex ? selectedColor : unselectedColor);
	}
}
