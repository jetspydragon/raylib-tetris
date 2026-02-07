#include "grid.h"

#include <iostream>
#include "colors.h"

Grid::Grid()
{
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    initialize();
    colors = getCellColors();
}

void Grid::initialize()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int col = 0; col < numCols; col++)
        {
            grid[row][col] = 0;
        }
    }
}

void Grid::print() const
{
    for(int row = 0; row < numRows; row++)
    {
        for(int col = 0; col < numCols; col++)
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::draw(int x, int y) const
{
    for(int row = 0; row < numRows; row++)
    {
        for(int col = 0; col < numCols; col++)
        {
            int cellValue = grid[row][col];
            Color cellColor = colors[cellValue];
            DrawRectangle(
                x + col * cellSize, 
                y + row * cellSize, 
                cellSize - 1, 
                cellSize - 1, 
                cellColor
            );
        }
    }
}
