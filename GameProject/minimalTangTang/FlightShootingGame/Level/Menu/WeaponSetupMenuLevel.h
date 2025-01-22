#pragma once
#include "Level/Level.h"

#include "Level/MenuItem.h"
#include <vector>
class WeaponSetupMenuLevel: public Level
{

	RTTI_DECLARATIONS(WeaponSetupMenuLevel, Level)
public:
	WeaponSetupMenuLevel();
	virtual ~WeaponSetupMenuLevel();

	void Draw() override;
	void Update(float daltaTime) override;

private:

	// ���� ���õ� �޴� ��ȣ (�ε���).
	int currentSelectedIndex = 0;

	// menuItems�� ������ üũ ����.
	int menuItemsCount = 0;

private:
	// �޴��� ��� ����.
	std::vector<MenuItem*> menuItems;
};