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
    virtual void DrawCharacter();
    bool operator == (BaseCharacter* obj);
    enum class State{ 
        idle,
        walk,
        run,
        attack,
        damaged,
        STATE_NR_ITEMS
    };

protected:
    Vector2 direction{};
    int hazeDirection{ 1 };
    Texture2D animationSheets[static_cast<int>(State::STATE_NR_ITEMS)];
    int framesInState[static_cast<int>(State::STATE_NR_ITEMS)]; //how many frames the spritesheet has per state
    float speed;

private:
    int frame{};
    float health = 100.f;
    Stats stats;
    std::set<std::string> hash;
    State currentState;
    virtual void Attack();

public:
    void setSpeed(float spd) { speed = spd; }
    void setPos(Vector2 pos) { position = pos; }
    void setDirection(Vector2 dir) { direction = dir; }
    float getHealth() const { return health;}
    void setHealth(float amount) { health = amount; }
    void Damage(float points);
    void Heal(float points);
    void Freeze(float time);
    void Burn(float time);
    void Buff();
    void Spawn();
    void Destroy();
    std::set<std::string> getHash();
    State getState() const;
};

#endif