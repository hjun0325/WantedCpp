#pragma once

#include <Level/Level.h>

struct Cell
{
	int surroundingMines = 0;    // �ֺ� ���� ��
	bool hasMine = false;            // ���� ����
	bool isRevealed = false;         // ���� ���� ����
	bool isFlagged = false;          // ��� ����
};


class GameLevel : public Level
{
	RTTI_DECLARATIONS(GameLevel, Level)

public:
	GameLevel();

	// ������Ʈ �Լ�.
	virtual void Update(float deltaTime) override;

	// ������ �׸��� �Լ�.
	virtual void Draw() override;
private:
	// �� ũ��.
	int mapSize = 16;

	// �� ���ڰ���.
	int totalMine = 40;

	Cell cells[16][16]{};
};