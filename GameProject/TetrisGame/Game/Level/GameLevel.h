#pragma once

#include <Level/Level.h>
#include <Math/Vector2.h>
#include <Engine/Timer.h>

// Map Width (constexpr)
const int MAP_WIDTH = 12;
// Map Height (constexpr)
const int MAP_HEIGHT = 23;

// ��� ����ü ����
struct MapCell {
	// �� �� Ÿ�� (0: �� ����, 1: �� ��).
	int type = 0;

	// ��� ���� (�⺻��: White).
	Color color = Color::White;
};

// �� ����ü ����
struct Map {
	// �� ���� MapCell ����ü�� �����ϴ� 2D �迭.
	MapCell mapCells[MAP_HEIGHT][MAP_WIDTH]{};
};

class Player;
class GhostBlock;
class GameLevel : public Level
{
	RTTI_DECLARATIONS(GameLevel, Level)

public:
	GameLevel();
	~GameLevel();

	// ������Ʈ �Լ�.
	virtual void Update(float deltaTime) override;

	// ������ �׸��� �Լ�.
	virtual void Draw() override;

	// �÷��̾ �̵��� ������ �� Ȯ���ϴ� �Լ�.
	bool CanPlayerMove(const Vector2& position);

	// �ϵ� ������� �÷��̾ �̵� ������ ������ Ȯ���ϴ� �Լ�.
	int HardDropCanPlayerMove(const Vector2& position);

	// �ʿ� �� ��ġ�ϴ� �Լ�.
	void PlaceBlocksOnMap(const Vector2& position);

	// ���� Ŭ���� �Լ�.
	void LineClear(const Vector2& position);

	// ��� ȸ�� �Լ�.
	void RotateBlock(int LR);

	// ��ġ�� ��Ʈ �� ����� �����ϴ� �Լ�.
	void DeleteAndCreateGhostBlock();

	// �� ��ġ ��ȯ �Լ�.
	inline Vector2 MapPosition() const { return mapPosition; }

	// ��Ʈ ��� ��ġ ��ȯ �Լ�.
	void SetGhostBlockPosition(int V);

	// ��Ʈ �� ��ȯ �Լ�.
	inline GhostBlock* GetGhostBlock() const { return ghostBlock; }

	// ��Ʈ ��� ���� �Լ�.
	inline void SetGhostBlock(GhostBlock* ghostBlock) { this->ghostBlock = ghostBlock; }

	// Ȧ���� ���� ��Ʈ �� ��ȯ �Լ�.
	inline GhostBlock* GetHoldGhostBlock() const { return holdGhostBlock; }
	
	// Ȧ���� ���� ��Ʈ �� ���� �Լ�.
	inline void SetHoldGhostBlock(GhostBlock* ghostBlock) { holdGhostBlock = ghostBlock; }

	// ��Ʈ ��� Ȧ��� ��ġ �� ȸ�� ������ ���� �Լ�.
	 // ��Ʈ ��� ��ġ ���� �Լ�.
	void GhostBlockReset();

private:
	// �� ��ġ.
	Vector2 mapPosition;

	// ��.
	Map map;

	// �÷��̾� ����.
	Player* player = nullptr;

	// ��Ʈ �� ����.
	GhostBlock* ghostBlock = nullptr;

	// Ȧ���� ���� ��Ʈ ��� ����.
	GhostBlock* holdGhostBlock = nullptr;

	// ���� �� ����.
	//List<Block*> subBlock;

	// ��� �ϰ� �ӵ�.
	int autoBlockSpeed = 1;

	// ���� ����.
	bool gameOver = false;

	// ���� Ŭ����.
	bool gameClear = false;

	// ���� Ŭ���� ���� ī��Ʈ.
	static int lineClearCount;

	// �ð� ���� ����.
	Timer timer;

	// ���� �ð� ����.
	float currentTime = 0.0f;
};