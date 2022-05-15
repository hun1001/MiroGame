#include "Maze.h"

Maze::Maze(int size)
{
	_startPos = { 0,0 };
	_endPos = { 0,0 };
	
	if (size % 2 == 0)
	{
		size++;
	}
	if (size < 3)
	{
		size = 3;
	}
	if (size > 29)
	{
		size = 29;
	}

	_tile = new char* [size];
	for (int i = 0; i < size; i++)
	{
		_tile[i] = new char[size];
	}

	_isAssign = true;
	_size = size;
}

void Maze::GenerateByBinaryTree()
{
	if (!_isAssign) return;

	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_tile[y][x] = Wall;
			}
			else
			{
				_tile[y][x] = Empty;
			}
		}
	}
	
	int randNum;

	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				continue;
			}

			if (y == _size - 2)
			{
				_tile[y][x + 1] = Empty;
				continue;
			}

			if (x == _size - 2)
			{
				_tile[y + 1][x] = Empty;
				continue;
			}

			randNum = GetRandom(0, 1);
			if (randNum == 0)
			{
				_tile[y][x + 1] = Empty;
			}
			else
			{
				_tile[y + 1][x] = Empty;
			}
		}
	}

	_tile[_size - 1][_size - 1] = Wall;

	SetPos();
}

char** Maze::GetTile()
{
	if (!_isAssign) perror("Is not Setting");
	return _tile;
}

int* Maze::GetSize()
{
	if (!_isAssign) perror("Is not Setting");
	return &_size;
}

POINT Maze::GetStartPos()
{
	return _startPos;
}

POINT Maze::GetEndPos()
{
	return _endPos;
}

void Maze::SetStartPos()
{
	// 여기 부분 보완 필요함
	_startPos.x = GetRandom(1, _size - 1);
	_startPos.y = GetRandom(1, _size - 1);
}

void Maze::SetEndPos()
{
	// 여기도 보완 필요함
	_endPos.x = GetRandom(1, _size - 1);
	_endPos.y = GetRandom(1, _size - 1);
	_tile[_endPos.y][_endPos.x] = Goal;
}

void Maze::SetPos()
{
	SetStartPos();
	SetEndPos();
}
