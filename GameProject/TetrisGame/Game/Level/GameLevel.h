#pragma once

#include <Level/Level.h>
#include <Math/Vector2.h>

// Map Width (constexpr)
const int MAP_WIDTH = 12;
// Map Height (constexpr)
const int MAP_HEIGHT = 22;

// 블록 구조체 정의
struct MapCell {
	// 각 셀 타입 (0: 빈 공간, 1: 벽 등).
	int type = 0;

	// 블록 색상 (기본값: White).
	Color color = Color::White;
};

// 맵 구조체 정의
struct Map {
	// 각 셀이 MapCell 구조체를 포함하는 2D 배열.
	MapCell mapCells[MAP_HEIGHT][MAP_WIDTH]{};
};

class Block;
class Player;
class GameLevel : public Level
{
	RTTI_DECLARATIONS(GameLevel, Level)

public:
	GameLevel();
	~GameLevel();

	// 업데이트 함수.
	virtual void Update(float deltaTime) override;

	// 레벨의 그리기 함수.
	virtual void Draw() override;

	// 플레이어가 이동이 가능한 지 확인하는 함수.
	bool CanPlayerMove(const Vector2& position);

	// 맵에 블럭 배치하는 함수.
	void PlaceBlocksOnMap(const Vector2& position);

	// 라인 클리어 함수.
	void LineClear(const Vector2& position);

	// 블록 회전 함수.
	void RotateBlock();

private:
	// 맵 생성
	Map map;

	// 플레이어 액터.
	Player* player = nullptr;

	// 서브 블럭 액터.
	//List<Block*> subBlock;
};