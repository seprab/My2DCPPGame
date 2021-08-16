#ifndef GLOBAL_CONTROLLER
#define GLOBAL_CONTROLLER

#include <memory>
#include "raylib.h"
#include "BaseCharacter.h"
#include "world.h"


class GlobalController
{
public:
    GlobalController();
    ~GlobalController();

    void AddCharacter(BaseCharacter* character);
    void RemoveCharacter(BaseCharacter* character);
    void Update();

private:
    World currentWorld;
    std::vector<BaseCharacter*> characters;
};

#endif