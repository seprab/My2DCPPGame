#include "Character.h"
#include "raylib.h"
#include "raymath.h"
#include <limits>
#include <string>

Character::Character()
{
    speed = 6.f;
    drawScale = 5.f;

    animationSheets[0] = LoadTexture("resources/texture/characters/knight_idle_spritesheet.png");
    animationSheets[1] = LoadTexture("resources/texture/characters/knight_run_spritesheet.png");
    framesInState[0] = 6;
    framesInState[1] = 6;
}

void Character::Tick()
{
    if (getHealth() <= 0.f) return;
    if (IsKeyDown(KEY_A)) direction.x -= 1.f;
    if (IsKeyDown(KEY_D)) direction.x += 1.f;
    if (IsKeyDown(KEY_W)) direction.y -= 1.f;
    if (IsKeyDown(KEY_S)) direction.y += 1.f;

    BaseCharacter::Tick();
}

void Character::UpdateMovement()
{
    BaseCharacter::UpdateMovement();
}

void Character::DrawCharacter()
{
    if (getHealth() <= 0.f)
    {
        DrawText("Game Over!", 0, 0, 40, RED);
        return;
    }
    else 
    {
        std::string healthAmount = "Health: " + std::to_string(getHealth());
        DrawText(healthAmount.c_str(), 0, 0, 40, RED);
    }

    BaseCharacter::DrawCharacter();
}
