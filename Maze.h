#pragma once
#include "TileType.h"
#include "console.h"

class Maze
{
private:
	char** _tile;
	int _size;
	POINT _startPos;
	POINT _endPos;

public:
	void Initialize(int size);
	void GenerateByBinaryTree();
	char** GetTile();
	int GetSize();
};

