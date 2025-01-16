#include "StartLevel.h"
#include "Game/Game.h"

StartLevel::StartLevel()
{
	// �޴� �ʱ�ȭ.
	items.emplace_back(new MenuItem(
		"Start Game",
		[]() {Game::Get().PlayGame();})
	);
	items.emplace_back(new MenuItem(
		"Quit Game",
		[]() {Game::Get().QuitGame();})
	);

	// �޴� ���� ����.
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

	// �޴� ���� ���.
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, unselectedColor);
	std::cout << "Mine Sweeper\n\n\n";

	// ���� ��ȸ�ϸ鼭 �޴� �ؽ�Ʈ ���.
	for (int ix = 0; ix < itemCount; ++ix)
	{
		// ���� ����.
		SetConsoleTextAttribute(
			handle,
			ix == currentSelectedIndex ? selectedColor : unselectedColor
		);

		// ���.
		std::cout << items[ix]->text << "\n";
	}
}
