#pragma once

#include <Math/Vector2.h>
#include "Actor/DrawableActor.h"

const int GHOST_BLOCK_WIDTH = 4;
const int GHOST_BLOCK_HEIGHT = 4;

struct GhostBlockType
{
    // 4개의 회전 상태 (0°, 90°, 180°, 270°).
    int rotations[4][GHOST_BLOCK_WIDTH][GHOST_BLOCK_HEIGHT]{};

    // 색상 정보.
    Color color = Color::Gray;

    // 블록 회전 인덱스.
    int rotateIdx = 0;
};

class Block;
class GameLevel;
class GhostBlock : public DrawableActor
{
    RTTI_DECLARATIONS(GhostBlock, DrawableActor)
        friend class GameLevel;
    friend class Player;

public:
    GhostBlock(Block* block, GameLevel* level);
    virtual ~GhostBlock();

private:
    // 블록 타입 저장 변수.
    GhostBlockType ghostBlockType;

    // 현재 블록의 위치.
    Vector2 blockPosition;

    // 게임 레벨을 참조하는 변수.
	GameLevel* refLevel = nullptr;
};