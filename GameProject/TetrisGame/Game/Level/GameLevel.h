#pragma once

#include <deque>
#include <Level/Level.h>
#include <Math/Vector2.h>
#include <Engine/Timer.h>

// Map Width (constexpr)
const int MAP_WIDTH = 12;
// Map Height (constexpr)
const int MAP_HEIGHT = 24;

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

class Player;
class Block;
class GhostBlock;
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

	// 하드 드랍에서 플레이어가 이동 가능한 곳까지 확인하는 함수.
	int HardDropCanPlayerMove(const Vector2& position);

	// 맵에 블럭 배치하는 함수.
	void PlaceBlocksOnMap(const Vector2& position);

	// 라인 클리어 함수.
	void LineClear(const Vector2& position);

	// 블록 회전 함수.
	void RotateBlock(int LR);

	// 배치된 고스트 블럭 지우고 생성하는 함수.
	void DeleteAndCreateGhostBlock();

	// 맵 위치 반환 함수.
	inline Vector2 MapPosition() const { return mapPosition; }

	// 고스트 블록 위치 변환 함수.
	void SetGhostBlockPosition(int V);

	// 고스트 블럭 반환 함수.
	inline GhostBlock* GetGhostBlock() const { return ghostBlock; }

	// 고스트 블록 대입 함수.
	inline void SetGhostBlock(GhostBlock* ghostBlock) { this->ghostBlock = ghostBlock; }

	// 홀드한 블럭의 고스트 블럭 반환 함수.
	inline GhostBlock* GetHoldGhostBlock() const { return holdGhostBlock; }
	
	// 홀드한 블럭의 고스트 블럭 대입 함수.
	inline void SetHoldGhostBlock(GhostBlock* ghostBlock) { holdGhostBlock = ghostBlock; }

	// 고스트 블록 홀드시 위치 및 회전 원상태 복구 함수.
	 // 고스트 블록 위치 수정 함수.
	void GhostBlockReset();

	// 큐에 값을 푸시하는 함수.
	inline void PushToDeque(Block* block) { subBlock.push_back(block); }

	// 큐에서 값을 팝하는 함수.
	void PopToDeque();

	// 큐에 front의 값을 반환하는 함수.
	inline Block* TopDeque() { return subBlock.front(); }

private:
	// 맵 위치.
	Vector2 mapPosition;

	// 맵.
	Map map;

	// 플레이어 액터.
	Player* player = nullptr;

	// 고스트 블럭 변수.
	GhostBlock* ghostBlock = nullptr;

	// 홀드한 블럭의 고스트 블록 변수.
	GhostBlock* holdGhostBlock = nullptr;

	// 서브 블럭 액터.
	std::deque<Block*> subBlock;

	// 서브 블럭 개수 (항상 5개여야함).
	const int SubBlockCount = 5;

	// 게임 오버.
	bool gameOver = false;

	// 게임 클리어.
	bool gameClear = false;

	// 라인 클리어 개수 카운트.
	static int lineClearCount;

	// 시간 측정 변수.
	Timer timer;

	// 현재 시간 변수.
	float currentTime = 0.0f;
};