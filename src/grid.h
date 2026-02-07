#pragma once

#include <vector>
#include <raylib.h>

class Grid
{
public:
    Grid();
    void initialize();
    void print() const;
    void draw() const;
    int grid[20][10];
    bool isCellOutside(int row, int col) const;
private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;
};