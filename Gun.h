#pragma once
#include "Direction.h"
#include "console.h"
#include "TileType.h"

class Gun
{
public:
	Gun(char** tile, POINT* pos, Direction* dir);
	~Gun();
	
private:
	char** _tile;
	const POINT* const _pos;
	const Direction* const _dir;
public:
	void Fire();
};

