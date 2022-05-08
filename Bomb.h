#pragma once
#include "console.h"

namespace ITEM
{
	class Bomb
	{
	public:
		Bomb(const POINT pos, const int power, char** const tileInfo);
		~Bomb();
	private:
		POINT _pos;
		char** _tileInfo;
		string _icon;
		int _power;
		
	public:
		void Plant(POINT pos);
		void Detonate();
		void SetIcon(string icon);
	};
}

