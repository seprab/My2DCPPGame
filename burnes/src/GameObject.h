#pragma once

#include "Collidable.h"

/*
* Intended to host movable and static objects. Such as buildings, vegetation, obstacles
*/
class GameObject : public Collidable
{
	GameObject();
	~GameObject();
};

