#include <iostream>
#include <raylib.h>

#include "game.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

void UpdateDrawFrame(void);

Color darkBlue = {44, 44, 127, 255};
Game game = Game();

int main(void)
{    
    const int screenWidth = 300;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "raylib tetris");

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else    
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        UpdateDrawFrame();
    }
#endif    

    CloseWindow();
    
    return 0;
}

void UpdateDrawFrame(void)
{
    game.handleInput();

    BeginDrawing();
    ClearBackground(darkBlue);

    game.draw();

    EndDrawing();
}