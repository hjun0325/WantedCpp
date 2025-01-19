#pragma once

#include <Engine/Engine.h>

class Game : public Engine
{
public:
	Game();
	virtual ~Game();

	// ���� ȭ�� �ҷ����� �Լ�.
	Level* LoadStartLevel();

	// ���� ��ȯ �Լ�.
	void ToggleLevel(const char* Text);

	// �̱��� ���� �Լ�.
	static Game& Get() { return *instance; }

private:

	// ����ȭ��, ����ȭ��, �޴�ȭ��.
	Level* startLevel = nullptr;
	Level* gameLevel = nullptr;
	Level* menuLevel = nullptr;

	// �̱��� ���� ��ü.
	static Game* instance;
};