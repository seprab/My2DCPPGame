#ifndef CHARACTER_H
#define CHARACTER_H
#include "raylib.h"
#include "BaseCharacter.h"
class Character : public BaseCharacter
{
public:
    Character();
    virtual void Tick() override;
    virtual void UpdateMovement() override;
    virtual void DrawCharacter() override;

private:

public:
    
};

#endif