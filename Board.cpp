#include "Board.h"



void Board::RenderBoard()
{
	int size = GetMaze().GetSize();
	char** tile = GetMaze().GetTile();

	for (int y = 0; y < size; y++)
	{
		for (int x = 0; x < size; x++)
		{
			switch (tile[y][x])
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

void Board::PlayerMoveInput(char input)
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

bool Board::PlayerMove(int x, int y)
{
	char** tile = GetMaze().GetTile();
	if (tile[y][x] == Wall)
	{
		return false;
	}
	
	if (tile[y][x] == Goal)
	{
		std::cout << "You Win!" << std::endl;
		return true;
	}

	std::swap(tile[playerPosY][playerPosX], tile[y][x]);
	playerPosX = x;
	playerPosY = y;
	return false;
}

bool Board::InputIdentify(char input)
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

Maze Board::GetMaze()
{
	return _maze;
}

bool Board::IsGoal()
{
	return false;
}
