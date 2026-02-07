#include "block.h"
#include "position.h"

class LBlock : public Block
{
public:
    //  ..x   .x.   ...   xx.
    //  xxx   .x.   xxx   .x.
    //  ...   .xx   x..   .x.
    //   0     1     2     3
    LBlock()
    {
        id = 1;
        cells[0] = {Position(2, 0), Position(0,1), Position(1,1), Position(2,1)};
        cells[1] = {Position(1, 0), Position(1,1), Position(1,2), Position(2,2)};
        cells[2] = {Position(0, 1), Position(1,1), Position(2,1), Position(0,2)};
        cells[3] = {Position(0, 0), Position(1,0), Position(1,1), Position(1,2)};
        move(0, 3);
    }
};

class JBlock : public Block
{
public:
    //  x..   .xx   ...   .x.
    //  xxx   .x.   xxx   .x.
    //  ...   .x.   ..x   xx.
    //   0     1     2     3
    JBlock()
    {
        id = 2;
        cells[0] = {Position(0,0), Position(0,1), Position(1,0), Position(2,0)};
        cells[1] = {Position(1,0), Position(2,0), Position(1,1), Position(1,2)};
        cells[2] = {Position(0,1), Position(1,1), Position(2,1), Position(2,2)};
        cells[3] = {Position(0,0), Position(0,1), Position(1,1), Position(2,1)};
        move(0, 3);
    }
};

class IBlock : public Block
{
public:
    //  ....   ..x.   ....   .x..
    //  xxxx   ..x.   ....   .x..
    //  ....   ..x.   xxxx   .x..
    //  ....   ..x.   ....   .x..
    //   0      1      2      3
    IBlock()
    {
        id = 3;
        cells[0] = {Position(0,1), Position(1,1), Position(2,1), Position(3,1)};
        cells[1] = {Position(2,0), Position(2,1), Position(2,2), Position(2,3)};
        cells[2] = {Position(0,2), Position(1,2), Position(2,2), Position(3,2)};
        cells[3] = {Position(1,0), Position(1,1), Position(1,2), Position(1,3)};
        move(-1, 3);
    }
};

class OBlock : public Block
{
public:
    //  xx   xx   xx   xx
    //  xx   xx   xx   xx
    //  0    1    2    3
    OBlock()
    {
        id = 4;
        cells[0] = {Position(0,0), Position(1,0), Position(0,1), Position(1,1)};
        cells[1] = cells[0];
        cells[2] = cells[0];
        cells[3] = cells[0];
        move(0, 4);
    }
};

class SBlock : public Block
{
public:
    //  .xx   .x.   ...   x..
    //  xx.   .xx   .xx   xx.
    //  ...   ..x   xx.   .x.
    //   0     1     2     3
    SBlock()
    {
        id = 5;
        cells[0] = {Position(1,0), Position(2,0), Position(0,1), Position(1,1)};
        cells[1] = {Position(1,0), Position(1,1), Position(2,1), Position(2,2)};
        cells[2] = {Position(1,1), Position(2,1), Position(0,2), Position(1,2)};
        cells[3] = {Position(0,0), Position(0,1), Position(1,1), Position(1,2)};
        move(0, 3);
    }
};

class TBlock : public Block
{
public:
    //  .x.   .x.   ...   .x.
    //  xxx   .xx   xxx   xx.
    //  ...   .x.   .x.   .x.
    //   0     1     2     3
    TBlock()
    {
        id = 6;
        cells[0] = {Position(1,0), Position(0,1), Position(1,1), Position(2,1)};
        cells[1] = {Position(1,0), Position(1,1), Position(2,1), Position(1,2)};
        cells[2] = {Position(0,1), Position(1,1), Position(2,1), Position(1,2)};
        cells[3] = {Position(0,1), Position(1,0), Position(1,1), Position(1,2)};
        move(0, 3);
    }
};

class ZBlock : public Block
{
public:
    //  xx.   ..x   ...   .x.
    //  .xx   .xx   xx.   xx.
    //  ...   .x.   .xx   x..
    //   0     1     2     3
    ZBlock()
    {
        id = 6;
        cells[0] = {Position(0,0), Position(1,0), Position(1,1), Position(2,1)};
        cells[1] = {Position(2,0), Position(1,1), Position(2,1), Position(1,2)};
        cells[2] = {Position(0,1), Position(1,1), Position(1,2), Position(2,2)};
        cells[3] = {Position(1,0), Position(1,1), Position(2,1), Position(2,2)};
        move(0, 3);
    }
};
