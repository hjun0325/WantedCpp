#pragma once
#include "Level/Level.h"
#include"Level/MenuItem.h"
#include <vector>
class PauseMenuLevel: public Level
{
	RTTI_DECLARATIONS(PauseMenuLevel, Level)
public:
	PauseMenuLevel();
	virtual ~PauseMenuLevel();
	
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