#include "raylib.h"
#include "globalController.h"

int main(void)
{
    const Vector2 windowDimensions{1280, 720};
    InitWindow(windowDimensions.x, windowDimensions.y, "RPG!");  
    
    GlobalController globalController;
    SetTargetFPS(15);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            globalController.Update();
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}