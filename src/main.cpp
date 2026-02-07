#include <iostream>
#include <raylib.h>

#include "grid.h"

int main(void)
{
    Color darkBlue = {44, 44, 127, 255};
    const int screenWidth = 300;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "raylib tetris");
    SetTargetFPS(60);

    Grid grid = Grid();
    grid.grid[0][0] = 1;
    grid.grid[10][5] = 3;
    grid.grid[10][6] = 3;
    grid.grid[11][6] = 3;
    grid.grid[15][3] = 6;
    grid.print();
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);

        grid.draw(0, 0);

        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
