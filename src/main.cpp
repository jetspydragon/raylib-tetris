#include <iostream>
#include <raylib.h>

#include "grid.h"
#include "blocks.cpp"

int main(void)
{
    Color darkBlue = {44, 44, 127, 255};
    const int screenWidth = 300;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "raylib tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.print();

    ZBlock block = ZBlock();
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);

        grid.draw(0, 0);
        block.draw();

        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
