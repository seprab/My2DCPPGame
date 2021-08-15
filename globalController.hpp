#ifndef GLOBAL_CONTROLLER
#define GLOBAL_CONTROLLER

#include "raylib.h"

class GlobalController
{
public:
    GlobalController(Vector2 winSize);
    ~GlobalController();

    Texture2D map{};
    float mapScale{};

    void Update();

private:
    Vector2 windowDimensions{};
    Vector2 worldOrigin{0,0};
};

#endif