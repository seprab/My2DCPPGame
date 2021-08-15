#include "globalController.hpp"

GlobalController::GlobalController(Vector2 winSize)
{
    windowDimensions = winSize;
    map = LoadTexture("resources/texture/nature_tileset/OpenWorldMap24x24.png");
    mapScale = 4.f;
}
GlobalController::~GlobalController()
{

}
void GlobalController::Update()
{
    DrawTextureEx(map, worldOrigin, 0.f, 4.f, WHITE);
}