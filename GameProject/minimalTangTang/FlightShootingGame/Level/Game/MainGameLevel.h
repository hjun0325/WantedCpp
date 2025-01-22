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

	// 업데이트 함수.
	virtual void Update(float deltaTime) override;

	// 레벨의 그리기 함수.
	virtual void Draw() override;

private:
	// 현재 선택된 메뉴 번호 (인덱스).
	int currentSelectedIndex = 0;

	// menuItems의 사이즈 체크 변수.
	int menuItemsCount = 0;

	// 맵 위치.
	Vector2 mapPosition;

	// 현재 맵에서 나의 위치
	//Vector2 myPosition;

	// 플레이어.
	Player* player = nullptr;

private:
	// 메뉴를 담는 벡터.
	std::vector<MenuItem*> menuItems;
};