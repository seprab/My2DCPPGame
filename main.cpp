#include "raylib.h"
#include "globalController.hpp"

int main(void)
{
    const Vector2 windowDimensions{1920, 1080};
    InitWindow(windowDimensions.x, windowDimensions.y, "RPG!");

    GlobalController globalController(windowDimensions);

/*
    // Statically create props
    Collidable Prop(
        LoadTexture("nature_tileset/Rock.png"),
        Vector2{400.f, 330.f});
        manager.props.push_back(&Prop);

    Vector2 mapCenter{manager.map.width/2.f, manager.map.height/2.f};
    Character knight(Vector2{(float)windowDimensions[0], (float)windowDimensions[1]});
    //knight.setPos(mapCenter);
    manager.registerMainCharacter(knight);
    knight.setPosition(mapCenter);

    Enemy goblin{};
    goblin.setIdleSheet(LoadTexture("characters/goblin_idle_spritesheet.png"));
    goblin.setRunSheet(LoadTexture("characters/goblin_run_spritesheet.png"));
    goblin.setPos(Vector2{350.f, 200.f});
    goblin.setTarget(&knight);
    manager.AddEnemy(&goblin);

    Enemy goblin2{};
    goblin2.setIdleSheet(LoadTexture("characters/goblin_idle_spritesheet.png"));
    goblin2.setRunSheet(LoadTexture("characters/goblin_run_spritesheet.png"));
    goblin2.setPos(Vector2{250.f, 600.f});
    goblin2.setTarget(&knight);
    manager.AddEnemy(&goblin2);

    Enemy slime{};
    slime.setIdleSheet(LoadTexture("characters/slime_idle_spritesheet.png"));
    slime.setRunSheet(LoadTexture("characters/slime_run_spritesheeet.png"));
    slime.setPos(Vector2{mapCenter.x + 50.f, mapCenter.y + 50.f});
    slime.setTarget(&knight);
    manager.AddEnemy(&slime);

    Enemy slime2{};
    slime2.setIdleSheet(LoadTexture("characters/slime_run_spritesheeet.png"));
    slime2.setRunSheet(LoadTexture("characters/slime_run_spritesheeet.png"));
    slime2.setPos(Vector2{200.f, 200.f});
    slime2.setTarget(&knight);
    manager.AddEnemy(&slime2);

    SetTargetFPS(60);
*/
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