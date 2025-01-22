#pragma once
#include "Level/Level.h"
#include "Level/MenuItem.h"
#include <Math/Vector2.h>
#include <vector>

// Map Width (constexpr)
const int MAP_WIDTH = 20;
// Map Height (constexpr)
const int MAP_HEIGHT = 10;

class Player;
class MainGameLevel : public Level
{

	RTTI_DECLARATIONS(MainGameLevel, Level)
public:
	MainGameLevel();
	virtual ~MainGameLevel();

	// ������Ʈ �Լ�.
	virtual void Update(float deltaTime) override;

	// ������ �׸��� �Լ�.
	virtual void Draw() override;

private:
	// ���� ���õ� �޴� ��ȣ (�ε���).
	int currentSelectedIndex = 0;

	// menuItems�� ������ üũ ����.
	int menuItemsCount = 0;

	// �� ��ġ.
	Vector2 mapPosition;

	// ���� �ʿ��� ���� ��ġ
	//Vector2 myPosition;

	// �÷��̾�.
	Player* player = nullptr;

private:
	// �޴��� ��� ����.
	std::vector<MenuItem*> menuItems;
};