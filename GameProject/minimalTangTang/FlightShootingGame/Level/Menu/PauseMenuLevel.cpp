#include "PauseMenuLevel.h"
#include"Game/Game.h"

PauseMenuLevel::PauseMenuLevel()
{
    // �޴� �׸� �ʱ�ȭ
    // @Todo : ��� ����?
    menuItems.emplace_back(new MenuItem("Resume Game", []() {
        Game::Get().ChangeLevel(Game::Get().GetMainGameLevel());
        }));
    menuItems.emplace_back(new MenuItem("Restart Game", []() {
        Game::Get().RestartGame(Game::Get().GetMainGameLevel());
        }));  
    menuItems.emplace_back(new MenuItem("Main Menu", []() {
        Game::Get().ChangeLevel(Game::Get().GetMainMenuLevel());
        }));
    menuItems.emplace_back(new MenuItem("Quit", []() {Game::Get().QuitGame();}));

    menuItemsCount = menuItems.size();
}

PauseMenuLevel::~PauseMenuLevel()
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

void PauseMenuLevel::Draw()
{

    Super::Draw();

    // ���� ���� ���.
    Engine::Get().Draw(Vector2(0, 0), "==== Pause Menu ====");

    // ���� ��ȸ�ϸ鼭 �޴� �ؽ�Ʈ ���.
    for (int ix = 0; ix < menuItemsCount; ++ix)
    {
        Engine::Get().Draw(Vector2(0, 1 + ix), menuItems[ix]->menuText, ix == currentSelectedIndex ? Color::Green : Color::White);
    }
}

void PauseMenuLevel::Update(float deltaTime)
{

    Super::Update(deltaTime);
    if (Game::Get().GetKeyDown(VK_ESCAPE))
    {
        Game::Get().ChangeLevel(Game::Get().GetPauseMenuLevel());
    }

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
