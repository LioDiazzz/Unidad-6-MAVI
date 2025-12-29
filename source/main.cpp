#ifndef NDEBUG
#include <vld.h> 
#endif
#include "raylib.h"
#include "Game.h"
#include "GameConfig.h"

int main()
{
    InitWindow(screenWidth, screenHeight, "Unidad 6 MAVI - Lionel Diaz");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        game.Run();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}



