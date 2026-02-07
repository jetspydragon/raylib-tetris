#include <iostream>
#include <raylib.h>

#include "game.h"

int main(void)
{
    Color darkBlue = {44, 44, 127, 255};
    const int screenWidth = 300;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "raylib tetris");
    SetTargetFPS(60);

    Game game = Game();
    while(!WindowShouldClose())
    {
        game.handleInput();
        
        BeginDrawing();
        ClearBackground(darkBlue);

        game.draw();

        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
