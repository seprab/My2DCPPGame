#include "BaseCharacter.h"
#include "raylib.h"
#include "raymath.h"

void BaseCharacter::Tick()
{
    UpdateMovement();
    DrawCharacter();
}
BaseCharacter::BaseCharacter()
{
    hash = Utils::GenerateHash();
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

Rectangle BaseCharacter::getCollision()
{
    return Rectangle();
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

void BaseCharacter::Damage(float points)
{
}

void BaseCharacter::Heal(float points)
{
}

void BaseCharacter::Freeze(float time)
{
}

void BaseCharacter::Burn(float time)
{
}

void BaseCharacter::Buff()
{
}

void BaseCharacter::Spawn()
{
}

void BaseCharacter::Destroy()
{
    
}

std::set<std::string> BaseCharacter::getHash()
{
    return hash;
}

void BaseCharacter::DrawCharacter()
{
    Rectangle sourceRec{rectangle};
    Rectangle destRec{rectangle};
    Vector2 origin{0.f, 0.f};
    DrawTexturePro(getTexture(),sourceRec, destRec, origin, 0.f, WHITE);
}

bool BaseCharacter::operator==(BaseCharacter* obj)
{
    return hash == obj->getHash();
}
