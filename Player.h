#pragma once
#include "console.h"

class Player
{
private:
	POINT _playerCurPos;
public:
	Player(long x, long y);
	void Move(int x, int y);
};

