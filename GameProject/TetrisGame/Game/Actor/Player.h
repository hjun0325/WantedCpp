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

	// 배치된 블럭 지우고 생성하는 함수.
	void DeleteAndCreateBlock();

	// 고스트 블록 위치 갱신 함수.
	void UpdateGhostBlockPosition();

	// 홀드한 블록 반환 함수.
	inline Block* GetHoldBlock() const { return holdBlock; }

private:
	// 조작할 블록 변수.
	Block* mainBlock = nullptr;

	// 홀드한 블록 변수.
	Block* holdBlock = nullptr;

	// 게임 레벨을 참조하는 변수.
	GameLevel* refLevel = nullptr;
};