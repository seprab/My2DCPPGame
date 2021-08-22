#include "Enemy.h"
#include "raylib.h"
#include "raymath.h"

Enemy::Enemy()
{
    setSpeed(2.f);
    drawScale = 3.f;
    attackRange = 25.f;
    agroRange = 100.f;
    agroed = false;
}

void Enemy::Tick()
{
    //if (getHealth() <= 0.f) return;
    //BaseCharacter::Tick();
    //if (target)
    //{
    //    Vector2 toTarget = Vector2Subtract(target->getCenter(), getCenter());
    //    float distance = Vector2Length(toTarget);
    //    if (distance < agroRange) agroed = true;
    //    if (!agroed) return;
    //    if (distance < attackRange)
    //        setDirection(Vector2{0.f, 0.f});
    //    else
    //        setDirection(toTarget);

    //    // deal damage
    //    if (CheckCollisionRecs(getCollision(), target->getCollision()))
    //    {
    //        const float newHealth{target->getHealth() - getDamagePerSecond() * GetFrameTime()};
    //        target->setHealth(newHealth);
    //    }
    //    DrawRectangleLines(
    //        getCollision().x,
    //        getCollision().y,
    //        getCollision().width,
    //        getCollision().height,
    //        PURPLE
    //    );
    //}

}

void Enemy::UpdateMovement()
{
    BaseCharacter::UpdateMovement();
}

