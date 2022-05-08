#include "Bomb.h"

ITEM::Bomb::Bomb(const POINT pos, const int power, char** const tileInfo)
{
	_power = power;
	_tileInfo = tileInfo;
	SetIcon("¡Ý");
	Plant(pos);
}

ITEM::Bomb::~Bomb()
{
}

void ITEM::Bomb::Plant(POINT pos)
{
	_pos = pos;
	
}

void ITEM::Bomb::Detonate()
{
}

void ITEM::Bomb::SetIcon(string icon)
{
}
