#pragma once

#include <Level/Level.h>
#include <vector>

// �޴� ������.
struct GameOverItem
{
	// �̺�Ʈ ����.
	using OnSelected = void (*)();

	GameOverItem(const char* text, OnSelected onSelected)
		: onSelected(onSelected)
	{
		size_t length = strlen(text) + 1;
		this->text = new char[length];
		strcpy_s(this->text, length, text);
	}

	~GameOverItem()
	{
		delete[] text;
		text = nullptr;
	}

	// �޴����� ������ �ؽ�Ʈ.
	char* text;

	// �������� �� ������ �Լ��� �����ϴ� ������.
	OnSelected onSelected;
};

class GameOverLevel : public Level
{
	RTTI_DECLARATIONS(GameOverLevel, Level)

public:
	GameOverLevel();
	~GameOverLevel();

	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

private:
	// ���� ���õ� �޴� ��ȣ (�ε���).
	int currentSelectedIndex = 0;

	// ���õ� �޴��� ����.
	Color selectedColor = Color::Green;

	// ���õ��� ���� �޴��� ����.
	Color unselectedColor = Color::White;

	// �޴� �����.
	std::vector<GameOverItem*> items;

	// �޴� ������ ����.
	int itemCount = 0;
};