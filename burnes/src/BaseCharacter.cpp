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
        currentState = State::walk;
        Vector2 input{ Vector2Scale(Vector2Normalize(direction), speed) };
        position.x += input.x;
        position.y += input.y;
        direction = Vector2{ 0.f, 0.f };
    }
    else
    {
        currentState = State::idle;
    }
}

void BaseCharacter::DrawCharacter()
{
    int stateNum = static_cast<int>(getState());
    int framesNum = framesInState[stateNum];
    if (frame >= framesNum)
    {
        frame = 0;
    }

    texture = animationSheets[stateNum];

    Rectangle SubRectTexture{
        texture.width / framesNum * frame,
        0,
        texture.width / framesNum,
        texture.height
    };
    
    frame++;

    DrawTextureRec(texture, SubRectTexture, position, WHITE);
}

void BaseCharacter::Attack()
{
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

BaseCharacter::State BaseCharacter::getState() const
{
    return State();
}

bool BaseCharacter::operator==(BaseCharacter* obj)
{
    return hash == obj->getHash();
}
