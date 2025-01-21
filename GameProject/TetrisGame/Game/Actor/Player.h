#pragma once

#include <Actor/DrawableActor.h>

class Block;
class GhostBlock;
class GameLevel;
class Player : public DrawableActor
{
	RTTI_DECLARATIONS(Player, DrawableActor)
	friend class GameLevel;

public:
	Player( GameLevel* level);
	~Player();

	virtual void Update(float deltaTime) override;

	// ��ġ�� �� ����� �����ϴ� �Լ�.
	void DeleteAndCreateBlock();

	// ��Ʈ ��� ��ġ ���� �Լ�.
	void UpdateGhostBlockPosition();

	// Ȧ���� ��� ��ȯ �Լ�.
	inline Block* GetHoldBlock() const { return holdBlock; }

private:
	// ������ ��� ����.
	Block* mainBlock = nullptr;

	// Ȧ���� ��� ����.
	Block* holdBlock = nullptr;

	// ���� ������ �����ϴ� ����.
	GameLevel* refLevel = nullptr;
};