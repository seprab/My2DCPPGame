#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include <vector>
#include <set>
#include <string>

#include "Collidable.h"
#include "stats.h"
#include "Utils.h"

class BaseCharacter : public Collidable
{
public:
    BaseCharacter();
    virtual void Tick();
    virtual void UpdateMovement();
    virtual Rectangle getCollision();
    virtual void DrawCharacter();
    bool operator == (BaseCharacter* obj);

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
    std::set<std::string> hash;

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
    void Spawn();
    void Destroy();
    std::set<std::string> getHash();
};

#endif