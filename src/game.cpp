#include "game.h"
#include "blocks.h"
#include <random>
#include <raylib.h>

Game::Game()
{
    grid = Grid();
    blocks = createAllBlocks();
    currentBlock = getRandomBlock();
    nextBlock = getRandomBlock();
}

Block Game::getRandomBlock()
{
    if (blocks.empty())
    {
        blocks = createAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin() + randomIndex);
    return block;
}

std::vector<Block> Game::createAllBlocks()
{
    return {
        IBlock(),
        JBlock(),
        LBlock(),
        OBlock(),
        SBlock(),
        TBlock(),
        ZBlock(),
    };
}

bool Game::isBlockOutside() const
{
    const auto& cells = currentBlock.getCellPositions();
    for(auto& cell : cells)
    {
        if (grid.isCellOutside(cell.row, cell.col)) {
            return true;
        }
    }
    return false;
}

void Game::draw() const
{
    grid.draw();
    currentBlock.draw();
}

void Game::handleInput()
{
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_LEFT:
        moveBlockLeft();
        break;
    case KEY_RIGHT:
        moveBlockRight();
        break;
    case KEY_DOWN:
        moveBlockDown();
        break;
    case KEY_UP:
        rotateBlock();
        break;
    }
}

void Game::moveBlockLeft()
{
    currentBlock.move(0, -1);
    if (isBlockOutside()) 
    {
        currentBlock.move(0, 1);
    }
}

void Game::moveBlockRight()
{
    currentBlock.move(0, 1);
    if (isBlockOutside()) 
    {
        currentBlock.move(0, -1);
    }
}

void Game::moveBlockDown()
{
    currentBlock.move(1, 0);
    if (isBlockOutside())
    {
        currentBlock.move(-1, 0);
    }
}

void Game::rotateBlock()
{
    currentBlock.rotate();
    if (isBlockOutside())
    {
        currentBlock.undoRotate();
    }
}
