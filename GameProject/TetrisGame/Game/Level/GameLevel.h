#pragma once

#include <Level/Level.h>
#include <Math/Vector2.h>

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

	// ��Ʈ �� ��ȯ �Լ�.
	inline GhostBlock* GetGonstBlock() const { return ghostBlock; }

	// ��Ʈ ��� ��ġ ��ȯ �Լ�.
	void SetGhostBlock(int V);

private:
	// �� ��ġ.
	Vector2 mapPosition;

	// ��.
	Map map;

	// �÷��̾� ����.
	Player* player = nullptr;

	// ��Ʈ �� ����.
	GhostBlock* ghostBlock = nullptr;

	// ���� �� ����.
	//List<Block*> subBlock;

	// ��� �ϰ� �ӵ�.
	int autoBlockSpeed = 1;
};