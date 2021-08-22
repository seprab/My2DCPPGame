#ifndef BASE_CHARACTER_H
#define BASE_CHARACTER_H

#include <vector>
#include <set>
#include <string>
#include <thread>

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
    enum state{ idle, walk, run, attack, damaged, STATE_NR_ITEMS};

protected:
    Rectangle rectangle{};
    Vector2 direction{};
    Texture2D animationSheets[STATE_NR_ITEMS];
    float speed;

private:
    int frame{};
    float health = 100.f;
    Stats stats;
    std::set<std::string> hash;
    Texture2D getAnimationFrame();
    state currenState;

public:
    void setSpeed(float spd) { speed = spd; }
    virtual Vector2 getCenter();
    void setPos(Vector2 pos) { position = pos; }
    void setDirection(Vector2 dir) { direction = dir; }
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
    state getState() const;
};

#endif