#ifndef WORLD
#define WORLD
#include "raylib.h"


class World
{
public:
	World();
	~World();
	void Tick();

private:
	const char* filePath;
	Texture2D map{};
	Vector2 worldOrigin{ 0,0 };
};

#endif