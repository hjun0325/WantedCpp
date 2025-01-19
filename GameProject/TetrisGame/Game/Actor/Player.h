#pragma once

#include <Actor/DrawableActor.h>

class Block;
class GameLevel;
class Player : public DrawableActor
{
	RTTI_DECLARATIONS(Player, DrawableActor)
	friend class GameLevel;

public:
	Player( GameLevel* level);
	~Player();

	virtual void Update(float deltaTime) override;

private:
	// ������ ��� ����.
	Block* mainBlock = nullptr;

	// ���� ������ �����ϴ� ����.
	GameLevel* refLevel = nullptr;
};