#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = getCellColors();
}

void Block::draw() const
{
    auto& tiles = cells.at(rotationState);
    for(const Position& pos : tiles)
    {
        DrawRectangle(
            pos.col * cellSize, 
            pos.row * cellSize, 
            cellSize - 1, 
            cellSize - 1, 
            colors[id]
        );
    }
}
