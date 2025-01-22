#include "MainMenuLevel.h"
#include "Game/Game.h"

MainMenuLevel::MainMenuLevel()
{
    // 메뉴 항목 초기화
    menuItems.emplace_back(new MenuItem("Start Game", []() {
        Game::Get().ChangeLevel(Game::Get().GetMainGameLevel());
        }));
    menuItems.emplace_back(new MenuItem("Weapon Setup", []() {
        Game::Get().ChangeLevel(Game::Get().GetWeaponSetupMenuLevel());
        }));
    menuItems.emplace_back(new MenuItem("Quit", []() {Game::Get().QuitGame();} ));

	menuItemsCount = menuItems.size();
}

MainMenuLevel::~MainMenuLevel()
{
    // vector의 MenuItem*들 해제하기
    for (auto items : menuItems)
    {
        if (items)
        {
            delete items;
        }
    }
}

void MainMenuLevel::Draw()
{

	Super::Draw();

	// 게임 제목 출력.
	Engine::Get().Draw(Vector2(0, 0), "==== Main Menu ====");

	// 루프 순회하면서 메뉴 텍스트 출력.
	for (int ix = 0; ix < menuItemsCount; ++ix)
	{
		Engine::Get().Draw(Vector2(0, 1 + ix), menuItems[ix]->menuText, ix == currentSelectedIndex ? Color::Green : Color::White);
	}
}

void MainMenuLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// 위아래 방향키.
	if (Game::Get().GetKeyDown(VK_UP))
	{
		// 인덱스 변환.
		currentSelectedIndex
			= (currentSelectedIndex - 1 + menuItemsCount) % menuItemsCount;
	}

	if (Game::Get().GetKeyDown(VK_DOWN))
	{
		currentSelectedIndex
			= (currentSelectedIndex + 1 + menuItemsCount) % menuItemsCount;
	}

	// 엔터키.
	if (Game::Get().GetKeyDown(VK_RETURN))
	{
		menuItems[currentSelectedIndex]->onSelected();
	}

}
