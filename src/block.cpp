#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = getCellColors();
}

void Block::draw() const
{
    const auto& tiles = getCellPositions();
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

void Block::move(int row, int col)
{
    rowOffset += row;
    colOffset += col;
}

void Block::rotate()
{
    rotationState++;
    if (rotationState >= cells.size())
    {
        rotationState = 0;
    }
}

void Block::undoRotate()
{
    rotationState--;
    if (rotationState < 0)
    {
        rotationState = cells.size() - 1;
    }
}

std::vector<Position> Block::getCellPositions() const
{
    std::vector<Position> tiles = cells.at(rotationState);
    for(Position& tile : tiles)
    {
        tile.col += colOffset;
        tile.row += rowOffset;
    }
    return tiles;
}
