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
	Direction _dir;
	string _icon;
	
public:
	POINT GetPos();
	POINT* GetPosp();
	void SetPos(POINT pos);
	void SetIcon(string icon);
	void SetDir(Direction dir);
	void Move(Direction dir);
	void Back();
	void PrtPlayer();

	Direction* GetDir();
};
