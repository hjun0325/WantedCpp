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
	// 조작할 블록 변수.
	Block* mainBlock = nullptr;

	// 게임 레벨을 참조하는 변수.
	GameLevel* refLevel = nullptr;
};