#pragma once

#include <Level/Level.h>
#include <vector>

// �޴� ������.
struct StartItem
{
	// �̺�Ʈ ����.
	using OnSelected = void (*)();

	StartItem(const char* text, OnSelected onSelected)
		: onSelected(onSelected)
	{
		size_t length = strlen(text) + 1;
		this->text = new char[length];
		strcpy_s(this->text, length, text);
	}

	~StartItem()
	{
		delete[] text;
		text = nullptr;
	}

	// �޴����� ������ �ؽ�Ʈ.
	char* text;

	// �������� �� ������ �Լ��� �����ϴ� ������.
	OnSelected onSelected;
};

class StartLevel : public Level
{
	RTTI_DECLARATIONS(StartLevel, Level)

public:
	StartLevel();
	~StartLevel();

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
	std::vector<StartItem*> items;

	// �޴� ������ ����.
	int itemCount = 0;
};