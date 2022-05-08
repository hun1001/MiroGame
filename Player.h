#pragma once
#include "console.h"
#include "Direction.h"

class Player
{
public:
	Player(POINT pos);
private:
	POINT _pos;
	POINT _beforePos;
	string _icon;
public:
	POINT GetPos();
	void SetPos(POINT pos);
	void SetIcon(string icon);
	void Move(Direction dir);
	void Back();
	void PrtPlayer();
};
