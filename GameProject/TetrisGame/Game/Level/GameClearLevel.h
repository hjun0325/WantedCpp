#pragma once

#include <Level/Level.h>
#include <vector>

// 메뉴 아이템.
struct GameClearItem
{
	// 이벤트 선언.
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

	// 메뉴에서 보여줄 텍스트.
	char* text;

	// 선택했을 때 실행할 함수를 저장하는 포인터.
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
	// 현재 선택된 메뉴 번호 (인덱스).
	int currentSelectedIndex = 0;

	// 선택된 메뉴의 색상.
	Color selectedColor = Color::Green;

	// 선택되지 않은 메뉴의 색상.
	Color unselectedColor = Color::White;

	// 메뉴 저장소.
	std::vector<GameClearItem*> items;

	// 메뉴 아이템 개수.
	int itemCount = 0;

	// 기록 저장 변수.
	float record = 0.0f;
};