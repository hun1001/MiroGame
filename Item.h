#pragma once
#include "Bomb.h"
#include <queue>
using namespace ITEM;

class Item
{
public:
	Item();
	~Item();
private:
	queue<Bomb> bombQueue;
public:
	void PrtItemInfo();
};

