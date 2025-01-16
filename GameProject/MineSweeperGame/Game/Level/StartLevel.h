#pragma once

#include <Level/Level.h>
#include <vector>

// �޴� ������.
struct MenuItem
{
	// �̺�Ʈ ����.
	using OnSelected = void (*)();

	MenuItem(const char* text, OnSelected onSelected)
		: onSelected(onSelected)
	{
		size_t length = strlen(text) + 1;
		this->text = new char[length];
		strcpy_s(this->text, length, text);
	}

	~MenuItem()
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
	int selectedColor = FOREGROUND_GREEN | FOREGROUND_INTENSITY;

	// ���õ��� ���� �޴��� ����.
	int unselectedColor =
		FOREGROUND_RED
		| FOREGROUND_GREEN
		| FOREGROUND_BLUE
		| FOREGROUND_INTENSITY;

	// �޴� �����.
	std::vector<MenuItem*> items;

	// �޴� ������ ����.
	int itemCount = 0;
};