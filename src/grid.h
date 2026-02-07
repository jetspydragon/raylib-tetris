#pragma once

#include <vector>
#include <raylib.h>

class Grid
{
public:
    Grid();
    void initialize();
    void print() const;
    void draw(int x, int y) const;
    int grid[20][10];
private:
    std::vector<Color> getCellColors();
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};