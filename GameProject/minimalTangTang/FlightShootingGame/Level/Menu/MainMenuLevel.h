#pragma once
#include "Level/Level.h"
#include "Level/MenuItem.h"
#include <vector>
class MainMenuLevel : public Level
{

	RTTI_DECLARATIONS(MainMenuLevel, Level)
public:
	MainMenuLevel();
	virtual ~MainMenuLevel();

	void Draw() override;
	void Update(float deltaTime) override;

private:
	
	// ���� ���õ� �޴� ��ȣ (�ε���).
	int currentSelectedIndex = 0;

	// menuItems�� ������ üũ ����.
	int menuItemsCount = 0;

private:
	// �޴��� ��� ����.
	std::vector<MenuItem*> menuItems;
};