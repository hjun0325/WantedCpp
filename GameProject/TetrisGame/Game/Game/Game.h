#pragma once

#include <Engine/Engine.h>

class Game : public Engine
{
public:
	Game();
	virtual ~Game();

	// 시작 화면 불러오는 함수.
	Level* LoadStartLevel();

	// 레벨 전환 함수.
	void ToggleLevel(const char* Text);

	// 싱글톤 접근 함수.
	static Game& Get() { return *instance; }

private:

	// 시작화면, 게임화면, 메뉴화면.
	Level* startLevel = nullptr;
	Level* gameLevel = nullptr;
	Level* menuLevel = nullptr;

	// 싱글톤 구현 객체.
	static Game* instance;
};