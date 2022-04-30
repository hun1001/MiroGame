#pragma once
#include <random>
#include <iostream>
#include "Maze.h"

class Board
{
private:
	Maze _maze;
	int playerPosX, playerPosY;
	bool _isGoal = false;

public:
	void RenderBoard();

	void PlayerMoveInput(char input);

	bool PlayerMove(int x, int y);

	bool InputIdentify(char input);

	Maze GetMaze();

	bool IsGoal();
};
