#pragma once

#include <Engine/Engine.h>

class Game : public Engine
{
public:
	Game();
	virtual ~Game();

	// 레벨 전환 함수.
	void ToggleLevel(const char* Text);

	// 싱글톤 접근 함수.
	static Game& Get() { return *instance; }

	// 게임 오버 레벨 반환 함수.
	inline Level* GetGameOverLevel() { return gameOverLevel; }

	// 게임 클리어 레벨 반환 함수.
	inline Level* GetGameClearLevel() { return gameClearLevel; }

	// 기록 저장 함수.
	void SaveRecord(float record);

private:

	// 시작화면, 게임화면, 메뉴화면, 게임 오버 화면.
	Level* startLevel = nullptr;
	Level* gameLevel = nullptr;
	Level* menuLevel = nullptr;
	Level* gameOverLevel = nullptr;
	Level* gameClearLevel = nullptr;

	// 싱글톤 구현 객체.
	static Game* instance;
};