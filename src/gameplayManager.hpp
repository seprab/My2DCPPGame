#ifndef GAMEPLAY_MANAGER_H
#define GAMEPLAY_MANAGER_H
#include <vector>
/*
#include <string>
#include <unordered_map>
#include "raylib.h"
#include "Character.h"
#include "Collidable.h"
#include "Enemy.h"
*/
class GameplayManager
{
public:
    GameplayManager(int winSize[]);
    int windowDimensions[2]{};
    //Texture2D map{};
    //float mapScale{};

    /*
    void Update();
    Vector2 getScreenPosition();
    Vector2 screenPositionLastFrame{};
    Vector2 mainCharacterPosition{};
    //void AddMovementInput(Vector2 direction, float speed);

    std::vector<Collidable*> props;
    std::vector<Collidable*> getProps() const { return props; }
    std::vector<Enemy*> enemies;
    std::vector<Enemy*> getEnemies() const { return enemies; }
    void AddEnemy(Enemy* enemy);

    bool HittingMapBounds();

    // Movement input vector
    Vector2 movementInput;
    void ApplyMovement(Vector2 input);
    void registerMainCharacter(Character& chr);

private:
    Character* mainCharacter;
*/
};

#endif