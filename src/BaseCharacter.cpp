#include "BaseCharacter.h"
#include "GameplayManager.h"
#include "raylib.h"
#include "raymath.h"

void BaseCharacter::Tick(float deltaTime)
{
    UpdateMovement();
    DrawCharacter();
}

void BaseCharacter::UpdateMovement()
{
    if (Vector2Length(direction) != 0.f)
    {
        texture = runSheet;
        Vector2 input{Vector2Scale(Vector2Normalize(direction), speed)};
        direction = Vector2{0.f, 0.f};
    }
    else texture = idleSheet;
}

Vector2 BaseCharacter::getCenter()
{
    return Vector2{
        position.x + rectangle.width/2.f,
        position.y + rectangle.height/2.f
    };
}

void BaseCharacter::setIdleSheet(Texture2D sheet)
{
    idleSheet = sheet;
}

void BaseCharacter::setRunSheet(Texture2D sheet) 
{ 
    runSheet = sheet;
}

void BaseCharacter::DrawCharacter()
{
        Rectangle sourceRec{rectangle};
        Rectangle destRec{rectangle};
        Vector2 origin{0.f, 0.f};
        DrawTexturePro(getTexture(),sourceRec, destRec, origin, 0.f, WHITE);
}