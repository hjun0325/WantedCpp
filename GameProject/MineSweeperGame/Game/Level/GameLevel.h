#pragma once

#include <Level/Level.h>

struct Cell
{
	int surroundingMines = 0;    // 주변 지뢰 수
	bool hasMine = false;            // 지뢰 여부
	bool isRevealed = false;         // 셀의 공개 여부
	bool isFlagged = false;          // 깃발 여부
};


class GameLevel : public Level
{
	RTTI_DECLARATIONS(GameLevel, Level)

public:
	GameLevel();

	// 업데이트 함수.
	virtual void Update(float deltaTime) override;

	// 레벨의 그리기 함수.
	virtual void Draw() override;
private:
	// 맵 크기.
	int mapSize = 16;

	// 총 지뢰개수.
	int totalMine = 40;

	Cell cells[16][16]{};
};