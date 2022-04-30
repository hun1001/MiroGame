#pragma once
#include "Maze.h"
#include "Player.h"

class Board
{
public:
	Board(int boardSize);
private:
	Maze* _maze;
	Player* _player;
	int* _size;
public:
	void RenderBoard();
	void ResetBoard();
	void InputCommend(char input);

	void MovePlayer(Direction dir);
	bool CheckCanMove(int x, int y);
};

