#pragma once

#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
public:
    Block();
    virtual ~Block() = default;
    void draw() const;
    void move(int row, int col);
    void rotate();
    void undoRotate();
    std::vector<Position> getCellPositions() const;
    int id;
    std::map<int, std::vector<Position>> cells;
private:
    int cellSize;
    int rotationState;
    int rowOffset;
    int colOffset;
    std::vector<Color> colors;
};
