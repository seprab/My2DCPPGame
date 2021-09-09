#ifndef WORLD
#define WORLD
#include <memory>
#include "raylib.h"
#include "GameObject.h"


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
	std::vector<GameObject*> obstacles;
	void InstanceObjects();
};

#endif