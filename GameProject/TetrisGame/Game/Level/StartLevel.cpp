#include "StartLevel.h"
#include "Game/Game.h"

StartLevel::StartLevel()
{
	// 메뉴 초기화.
	items.emplace_back(new StartItem(
		"Start Game",
		[]() {Game::Get().ToggleLevel("Start Game");})
	);
	items.emplace_back(new StartItem(
		"Quit Game",
		[]() {Game::Get().QuitGame();})
	);

	// 메뉴 개수 저장.
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

void StartLevel::Draw()
{
	Super::Draw();

	// 게임 제목 출력.
	Engine::Get().Draw(Vector2(0, 0), "Tetris");

	// 루프 순회하면서 메뉴 텍스트 출력.
	for (int ix = 0; ix < itemCount; ++ix)
	{
		Engine::Get().Draw(Vector2(0, 3 + ix), items[ix]->text, ix == currentSelectedIndex ? selectedColor : unselectedColor);
	}
}
