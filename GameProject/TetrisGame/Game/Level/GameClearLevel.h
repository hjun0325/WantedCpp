#pragma once

#include <Level/Level.h>
#include <vector>

// �޴� ������.
struct GameClearItem
{
	// �̺�Ʈ ����.
	using OnSelected = void (*)();

	GameClearItem(const char* text, OnSelected onSelected)
		: onSelected(onSelected)
	{
		size_t length = strlen(text) + 1;
		this->text = new char[length];
		strcpy_s(this->text, length, text);
	}

	~GameClearItem()
	{
		delete[] text;
		text = nullptr;
	}

	// �޴����� ������ �ؽ�Ʈ.
	char* text;

	// �������� �� ������ �Լ��� �����ϴ� ������.
	OnSelected onSelected;
};

class GameClearLevel : public Level
{
	RTTI_DECLARATIONS(GameClearLevel, Level)

public:
	GameClearLevel();
	~GameClearLevel();

	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

	inline void SetRecord(float record) { this->record = record; }

private:
	// ���� ���õ� �޴� ��ȣ (�ε���).
	int currentSelectedIndex = 0;

	// ���õ� �޴��� ����.
	Color selectedColor = Color::Green;

	// ���õ��� ���� �޴��� ����.
	Color unselectedColor = Color::White;

	// �޴� �����.
	std::vector<GameClearItem*> items;

	// �޴� ������ ����.
	int itemCount = 0;

	// ��� ���� ����.
	float record = 0.0f;
};