#include "world.h"

World::World()
{
	filePath = "resources/texture/nature_tileset/OpenWorldMap24x24.png";
	map = LoadTexture(filePath);
	SetWindowSize(map.width, map.height);
}

World::~World()
{
}

void World::Tick()
{
	DrawTextureEx(map, worldOrigin, 0.f, 1, WHITE);
}

void World::InstanceObjects()
{

}
