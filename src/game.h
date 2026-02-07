#pragma once
#include <vector>
#include "grid.h"
#include "block.h"

class Game
{
public:
    Game();
    Grid grid;
    Block getRandomBlock();
    void draw() const;
    void handleInput();
    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();
private:
    std::vector<Block> blocks;
    std::vector<Block> createAllBlocks();
    Block currentBlock;
    Block nextBlock;
    bool isBlockOutside() const;
};
