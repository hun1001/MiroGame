#pragma once
#include "Direction.h"
#include "console.h"

class Gun
{
public:
	Gun(char** tile, POINT* pos, Direction* dir);
	~Gun();
	
private:
	const char** const _tile;
	const POINT* const _pos;
	const Direction* const _dir;
public:
	void Fire();
};

