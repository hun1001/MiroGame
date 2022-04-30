#include "Maze.h"

void Maze::Initialize(int size)
{
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
	_size = size;
}

void Maze::GenerateByBinaryTree()
{
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
	std::random_device rd;

	std::mt19937 gen(rd());

	std::uniform_int_distribution<int> dis(0, 1);
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

			randNum = dis(gen);
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

	// 여기 부분 수정 필요
	/*_tile[1][1] = Player;
	_tile[_size - 2][_size - 1] = Goal;*/
}

char** Maze::GetTile()
{
	return _tile;
}

int Maze::GetSize()
{
	return _size;
}
