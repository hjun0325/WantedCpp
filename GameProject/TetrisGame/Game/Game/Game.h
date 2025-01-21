#pragma once

#include <Engine/Engine.h>

class Game : public Engine
{
public:
	Game();
	virtual ~Game();

	// ���� ��ȯ �Լ�.
	void ToggleLevel(const char* Text);

	// �̱��� ���� �Լ�.
	static Game& Get() { return *instance; }

	// ���� ���� ���� ��ȯ �Լ�.
	inline Level* GetGameOverLevel() { return gameOverLevel; }

	// ���� Ŭ���� ���� ��ȯ �Լ�.
	inline Level* GetGameClearLevel() { return gameClearLevel; }

	// ��� ���� �Լ�.
	void SaveRecord(float record);

private:

	// ����ȭ��, ����ȭ��, �޴�ȭ��, ���� ���� ȭ��.
	Level* startLevel = nullptr;
	Level* gameLevel = nullptr;
	Level* menuLevel = nullptr;
	Level* gameOverLevel = nullptr;
	Level* gameClearLevel = nullptr;

	// �̱��� ���� ��ü.
	static Game* instance;
};