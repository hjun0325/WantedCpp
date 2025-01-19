#pragma once

#include <Math/Vector2.h>
#include "Actor/DrawableActor.h"

const int BLOCK_WIDTH = 4;
const int BLOCK_HEIGHT = 4;

struct BlockType
{
    // 4���� ȸ�� ���� (0��, 90��, 180��, 270��).
    int rotations[4][BLOCK_WIDTH][BLOCK_HEIGHT]{};

    // ���� ����.
    Color color = Color::White;

    // ��� ���� ����.
    bool create = false;

    // ��� ȸ�� �ε���.
    int rotateIdx = 0;
};

// ��� �ʱ�ȭ
extern BlockType blockTypes[7];

class GameLevel;
class Block : public DrawableActor
{
    RTTI_DECLARATIONS(Block, DrawableActor)
        friend class GameLevel;
    friend class Player;

public:
    Block();
    virtual ~Block();

    virtual void Update(float deltaTime) override;
    virtual void Draw() override;

private:
    // ��� Ÿ�� ���� ����.
    BlockType blockType;

    // ��� 7���� �ݺ��ϱ� ���� ī��Ʈ ����.
    static int shapeCount;

    // ���� ����� ��ġ.
    Vector2 blockPosition;
};