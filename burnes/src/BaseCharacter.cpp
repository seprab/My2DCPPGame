
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

void BaseCharacter::DrawCharacter()
{
    int stateNum = static_cast<int>(getState());
    int framesNum = framesInState[stateNum];
        
    ////TODO
    //Texture2D currentSheet = animationSheets[stateNum];
    //if (texture != currentSheet)
    //{
    //    texture = animationSheets[stateNum];
    //}
    
    texture = animationSheets[stateNum];
    texture = animationSheets[0];
    rectangle.width = (float)texture.width / framesNum * frame;
    rectangle.width = texture.width;

    if (frame >= framesNum)
    {
        frame = 0;
    }

    DrawTextureRec(texture, rectangle, position, WHITE);

    std::string healthAmount = "x: " + std::to_string(position.x) + "y: " + std::to_string(position.y);
    DrawText(healthAmount.c_str(), 250, 250, 20, RED);
}

bool BaseCharacter::operator==(BaseCharacter* obj)
{
    return hash == obj->getHash();
}
