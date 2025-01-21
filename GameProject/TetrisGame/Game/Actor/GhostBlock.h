#pragma once

#include <Math/Vector2.h>
#include "Actor/DrawableActor.h"

const int GHOST_BLOCK_WIDTH = 4;
const int GHOST_BLOCK_HEIGHT = 4;

struct GhostBlockType
{
    // 4���� ȸ�� ���� (0��, 90��, 180��, 270��).
    int rotations[4][GHOST_BLOCK_WIDTH][GHOST_BLOCK_HEIGHT]{};

    // ���� ����.
    Color color = Color::Gray;

    // ��� ȸ�� �ε���.
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
    // ��� Ÿ�� ���� ����.
    GhostBlockType ghostBlockType;

    // ���� ����� ��ġ.
    Vector2 blockPosition;

    // ���� ������ �����ϴ� ����.
	GameLevel* refLevel = nullptr;
};