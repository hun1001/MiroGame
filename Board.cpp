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
			switch (_tile[y][x])
			{
			case Wall:
				std::cout << "■";
				break;
			case Empty:
				std::cout << "□";
				break;
			case Player:
				std::cout << "★";
				break;
			case Goal:
				std::cout << "◈";
				break;
			default:
				break;
			}
		}
		std::cout << std::endl;
	}
}

void MiroInitAlgorithm::Board::PlayerMoveInput(char input)
{
	int nextPos;
	bool isGameEnd = false;
	switch (input)
	{
	case 'a':
	case 'A':
		nextPos = playerPosX - 1;
		isGameEnd = PlayerMove(nextPos, playerPosY);
		break;
	case 'd':
	case 'D':
		nextPos = playerPosX + 1;
		isGameEnd = PlayerMove(nextPos, playerPosY);
		break;
	case 's':
	case 'S':
		nextPos = playerPosY + 1;
		isGameEnd = PlayerMove(playerPosX, nextPos);
		break;;
	case 'w':
	case 'W':
		nextPos = playerPosY - 1;
		isGameEnd = PlayerMove(playerPosX, nextPos);
		break;
	default:
		break;
	}
	_isGoal = isGameEnd;
}

bool MiroInitAlgorithm::Board::PlayerMove(int x, int y)
{
	if (_tile[y][x] == Wall)
	{
		return false;
	}
	
	if (_tile[y][x] == Goal)
	{
		std::cout << "You Win!" << std::endl;
		return true;
	}

	std::swap(_tile[playerPosY][playerPosX], _tile[y][x]);
	playerPosX = x;
	playerPosY = y;
	return false;
}

bool MiroInitAlgorithm::Board::InputIdentify(char input)
{
	switch (input)
	{
	case 27:
		// 게임 종료 처리
		exit(0);
		return false;
	default:
		break;
	}
	return true;
}
