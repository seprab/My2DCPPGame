#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H
#include "Collidable.h"
#include "stats.hpp"
#include <vector>
class BaseCharacter : public Collidable
{
public:
    BaseCharacter() = default;
    virtual void Tick(float deltaTime);
    virtual void UpdateMovement();
    virtual Rectangle getCollision();
    virtual void DrawCharacter();

protected:
    Rectangle rectangle{};
    Vector2 direction{};
    Texture2D idleSheet;
    Texture2D runSheet;
    float speed;

private:
    int frame{};
    float health = 100.f;
    Stats stats;

public:
    void setSpeed(float spd) { speed = spd; }
    virtual Vector2 getCenter();
    void setPos(Vector2 pos) { position = pos; }
    void setDirection(Vector2 dir) { direction = dir; }
    void setIdleSheet(Texture2D sheet);
    void setRunSheet(Texture2D sheet);
    float getHealth() const { return health;}
    void setHealth(float amount) { health = amount; }
    Rectangle getRectangle() const { return rectangle;}
    void Damage(float points);
    void Heal(float points);
    void Freeze(float time);
    void Burn(float time);
    void Buff();
};

#endif