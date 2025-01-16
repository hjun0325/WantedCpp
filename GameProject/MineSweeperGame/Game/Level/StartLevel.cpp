#include "StartLevel.h"
#include "Game/Game.h"

StartLevel::StartLevel()
{
	// 메뉴 초기화.
	items.emplace_back(new MenuItem(
		"Start Game",
		[]() {Game::Get().PlayGame();})
	);
	items.emplace_back(new MenuItem(
		"Quit Game",
		[]() {Game::Get().QuitGame();})
	);

	// 메뉴 개수 저장.
	itemCount = (int)items.size();
}

StartLevel::~StartLevel()
{
	for (MenuItem* item : items)
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

	// 메뉴 제목 출력.
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, unselectedColor);
	std::cout << "Mine Sweeper\n\n\n";

	// 루프 순회하면서 메뉴 텍스트 출력.
	for (int ix = 0; ix < itemCount; ++ix)
	{
		// 색상 설정.
		SetConsoleTextAttribute(
			handle,
			ix == currentSelectedIndex ? selectedColor : unselectedColor
		);

		// 출력.
		std::cout << items[ix]->text << "\n";
	}
}
