#include "Board.h"

void MiroInitAlgorithm::Board::Initialize(int size)
{
	if (size % 2 == 0)
	{
		return;
	}

	_tile = new char* [size];
	for (int i = 0; i < size; i++)
	{
		_tile[i] = new char[size];
	}
	_size = size;
}

void MiroInitAlgorithm::Board::GenerateByBinaryTree()
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

			//srand(time(NULL) + x);
			//randNum = rand() % 2;
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
	_tile[1][1] = Player;
	playerPosX = playerPosY = 1;
	_tile[_size - 2][_size - 1] = Goal;
}

void MiroInitAlgorithm::Board::RenderBoard()
{
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (_tile[y][x] == Wall)
			{
				std::cout << "¡Ü";
			}
			else if (_tile[y][x] == Empty)
			{
				std::cout << "¡Û";
			}
			else if (_tile[y][x] == Player)
			{
				std::cout << "¡Ú";
			}
			else if (_tile[y][x] == Goal)
			{
				std::cout << "¢Â";
			}
		}
		std::cout << std::endl;
	}
}

void MiroInitAlgorithm::Board::PlayerMoveInput(char input)
{
	int nextPos;
	switch (input)
	{
	case 'a':
	case 'A':
		nextPos = playerPosX - 1;
		PlayerMove(nextPos, playerPosY);
		break;
	case 'd':
	case 'D':
		nextPos = playerPosX + 1;
		PlayerMove(nextPos, playerPosY);
		break;
	case 's':
	case 'S':
		nextPos = playerPosY + 1;
		PlayerMove(playerPosX, nextPos);
		break;;
	case 'w':
	case 'W':
		nextPos = playerPosY - 1;
		PlayerMove(playerPosX, nextPos);
		break;
	default:
		break;
	}
}

void MiroInitAlgorithm::Board::PlayerMove(int x, int y)
{
	if (_tile[y][x] == Wall)
	{
		return;
	}

	std::swap(_tile[playerPosY][playerPosX], _tile[y][x]);
	playerPosX = x;
	playerPosY = y;
}
