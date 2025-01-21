#include "GhostBlock.h"
#include "Block.h"
#include "Player.h"
#include "Level/GameLevel.h"

GhostBlock::GhostBlock(Block* block, GameLevel* level)
    : blockPosition(block->BlockPosition().x, block->BlockPosition().y), refLevel(level)
{
    for (int ix = 0;ix < 4;++ix)
    {
        for (int jx = 0;jx < 4;++jx)
        {
            for (int kx = 0;kx < 4;++kx)
            {
                if (block->blockType.rotations[ix][jx][kx] == 2)
                {
                    this->ghostBlockType.rotations[ix][jx][kx]
                        = 3;
                }
                else
                {
                    this->ghostBlockType.rotations[ix][jx][kx]
                        = block->blockType.rotations[ix][jx][kx];
                }
            }
        }
    }

    int possibleN = refLevel->HardDropCanPlayerMove(blockPosition);
    blockPosition.y += possibleN;
}

GhostBlock::~GhostBlock()
{
    
}