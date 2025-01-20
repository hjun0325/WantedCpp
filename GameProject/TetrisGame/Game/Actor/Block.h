#pragma once

#include <Math/Vector2.h>
#include "Actor/DrawableActor.h"

const int BLOCK_WIDTH = 4;
const int BLOCK_HEIGHT = 4;

struct BlockType
{
    // 4개의 회전 상태 (0°, 90°, 180°, 270°).
    int rotations[4][BLOCK_WIDTH][BLOCK_HEIGHT]{};

    // 색상 정보.
    Color color = Color::White;

    // 블록 생성 여부.
    bool create = false;

    // 블록 회전 인덱스.
    int rotateIdx = 0;
};


// 블록 초기화
extern BlockType ghostBlockTypes[7];

class GameLevel;
class Block : public DrawableActor
{
    RTTI_DECLARATIONS(Block, DrawableActor)
        friend class GhostBlock;
    friend class GameLevel;
    friend class Player;

public:
    Block(const Vector2& position);
    virtual ~Block();

    // 블록 위치 반환 함수.
    inline Vector2 BlockPosition() const { return blockPosition; }

private:
    // 블록 타입 저장 변수.
    BlockType blockType;

    // 블록 7개씩 반복하기 위한 카운트 변수.
    static int shapeCount;

    // 현재 블록의 위치.
    Vector2 blockPosition;
};