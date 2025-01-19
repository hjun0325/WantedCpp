#include "MenuLevel.h"
#include "Game/Game.h"

MenuLevel::MenuLevel()
{
	// 메뉴 초기화.
	items.emplace_back(new MenuItem(
		"Resume Game",
		[]() {Game::Get().ToggleLevel("Resume Game");})
	);
	items.emplace_back(new MenuItem(
		"Main",
		[]() {Game::Get().ToggleLevel("Main");})
	);

	// 메뉴 개수 저장.
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

	// 위아래 방향키.
	if (Game::Get().GetKeyDown(VK_UP))
	{
		// 인덱스 변환.
		currentSelectedIndex
			= (currentSelectedIndex - 1 + itemCount) % itemCount;
	}

	if (Game::Get().GetKeyDown(VK_DOWN))
	{
		currentSelectedIndex
			= (currentSelectedIndex + 1 + itemCount) % itemCount;
	}

	// 엔터키.
	if (Game::Get().GetKeyDown(VK_RETURN))
	{
		items[currentSelectedIndex]->onSelected();
	}
}

void MenuLevel::Draw()
{
	Super::Draw();

	// 메뉴 제목 출력.
	Engine::Get().Draw(Vector2(0, 0), "Menu");

	// 루프 순회하면서 메뉴 텍스트 출력.
	for (int ix = 0; ix < itemCount; ++ix)
	{
		Engine::Get().Draw(Vector2(0, 2 + ix), items[ix]->text, ix == currentSelectedIndex ? selectedColor : unselectedColor);
	}
}
