#include "MainMenuLevel.h"
#include "Game/Game.h"

MainMenuLevel::MainMenuLevel()
{
    // �޴� �׸� �ʱ�ȭ
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
    // vector�� MenuItem*�� �����ϱ�
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

	// ���� ���� ���.
	Engine::Get().Draw(Vector2(0, 0), "==== Main Menu ====");

	// ���� ��ȸ�ϸ鼭 �޴� �ؽ�Ʈ ���.
	for (int ix = 0; ix < menuItemsCount; ++ix)
	{
		Engine::Get().Draw(Vector2(0, 1 + ix), menuItems[ix]->menuText, ix == currentSelectedIndex ? Color::Green : Color::White);
	}
}

void MainMenuLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// ���Ʒ� ����Ű.
	if (Game::Get().GetKeyDown(VK_UP))
	{
		// �ε��� ��ȯ.
		currentSelectedIndex
			= (currentSelectedIndex - 1 + menuItemsCount) % menuItemsCount;
	}

	if (Game::Get().GetKeyDown(VK_DOWN))
	{
		currentSelectedIndex
			= (currentSelectedIndex + 1 + menuItemsCount) % menuItemsCount;
	}

	// ����Ű.
	if (Game::Get().GetKeyDown(VK_RETURN))
	{
		menuItems[currentSelectedIndex]->onSelected();
	}

}
