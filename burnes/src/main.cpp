#include "raylib.h"
#include "globalController.h"

int main(void)
{
    const Vector2 windowDimensions{1920, 1080};
    InitWindow(windowDimensions.x, windowDimensions.y, "RPG!");
    GlobalController globalController(windowDimensions);
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            globalController.Update();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}