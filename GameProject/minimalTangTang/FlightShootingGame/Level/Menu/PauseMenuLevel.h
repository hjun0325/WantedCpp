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


	// 현재 선택된 메뉴 번호 (인덱스).
	int currentSelectedIndex = 0;

	// menuItems의 사이즈 체크 변수.
	int menuItemsCount = 0;

private:
	// 메뉴를 담는 벡터.
	std::vector<MenuItem*> menuItems;
};