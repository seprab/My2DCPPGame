#include "Character.h"
#include "raylib.h"
#include "raymath.h"
#include <limits>
#include <string>

Character::Character()
{
    speed = 6.f;
    drawScale = 5.f;
    setIdleSheet(LoadTexture("resources/texture/characters/knight_idle_spritesheet.png"));
    setRunSheet(LoadTexture("resources/texture/characters/knight_run_spritesheet.png"));
    weapon = LoadTexture("resources/texture/characters/weapon_sword_1.png");
    texture = idleSheet;
    weaponCollisionRec.width = weapon.width;
    weaponCollisionRec.height = weapon.height;
}

void Character::Attack()
{
    if (!attacking)
    {
        attacking = true;
    }
}

void Character::EndAttack()
{
    attacking = false;
}

Vector2 Character::getCenter()
{
    return Vector2{windowDimensions.x/2.f - drawScale*rectangle.width/2.f, windowDimensions.y/2.f - drawScale*rectangle.height/2.f};
}

void Character::UpdateMovement()
{
    if (Vector2Length(direction) != 0.f)
    {
        texture = runSheet;
        Vector2 input{Vector2Scale(Vector2Normalize(direction), speed)};
        direction = Vector2{0.f, 0.f};
    }
    else texture = idleSheet;
}

void Character::Tick()
{
    BaseCharacter::Tick();
    // process input
    if (getHealth() <= 0.f) return;
    if (IsKeyDown(KEY_A)) direction.x -= 1.f;
    if (IsKeyDown(KEY_D)) direction.x += 1.f;
    if (IsKeyDown(KEY_W)) direction.y -= 1.f;
    if (IsKeyDown(KEY_S)) direction.y += 1.f;
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) Attack();

    if (attacking)
    {
        attackTime += GetFrameTime();
        if (attackTime >= attackDuration)
        {
            EndAttack();
            attackTime = 0.f;
        }
    }
    weaponCollisionRec.y = getCenter().y + 10.f;
    DrawRectangleLines(getWeaponCollisionRec().x,getWeaponCollisionRec().y,getWeaponCollisionRec().width,getWeaponCollisionRec().height,BLUE);
}

Rectangle Character::getCollision()
{
    // return collision rec at global position
    float width = getDrawScale()*rectangle.width;
    float height = getDrawScale()*rectangle.height;
    DrawRectangleLines(windowDimensions.x/2.f - drawScale*rectangle.width/2.f,windowDimensions.y/2.f - drawScale*rectangle.height/2.f,width,height,RED);
    return Rectangle{windowDimensions.x/2.f - drawScale*rectangle.width/2.f, windowDimensions.y/2.f - drawScale*rectangle.height/2.f, width, height};
}

Rectangle Character::getWeaponCollisionRec()
{
    return Rectangle{weaponCollisionRec.x, weaponCollisionRec.y,weapon.width * weaponDrawScale, weapon.height * weaponDrawScale};
}

void Character::DrawWeapon()
{
    Vector2 wepPosition = Vector2{windowDimensions.x/2.f + reach - 35.f, windowDimensions.y/2.f + reach};
    if (getHealth() <= 0.f) return;
    Rectangle sourceRec{0.f, 0.f,(float)getWeapon().width,(float)getWeapon().height};
    Rectangle destRec{wepPosition.x, wepPosition.y, getWeaponDrawScale() * getWeapon().width, getDrawScale() * getWeapon().height};
    Vector2 origin{0.f, 0.f};
    DrawTexturePro(getWeapon(),sourceRec, destRec, origin, getWeaponRot(), WHITE);
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

    Rectangle sourceRec{rectangle};
    Rectangle destRec{rectangle};
    Vector2 origin{0.f, 0.f};
    DrawTexturePro(getTexture(),sourceRec, destRec, origin, 0.f, WHITE);
    DrawWeapon();
}
