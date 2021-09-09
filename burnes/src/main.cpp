#include "raylib.h"
#include "globalController.h"

int main(void)
{
    const Vector2 windowDimensions{1280, 720};
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(windowDimensions.x, windowDimensions.y, "RPG!");  
    
    GlobalController globalController;
    SetTargetFPS(15);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(BLACK);
            globalController.Update();
        DrawFPS(0, 0);       
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
