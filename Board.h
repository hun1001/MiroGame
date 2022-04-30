#pragma once
#include "Maze.h"
#include "Player.h"
#include "TileState.h"

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
	TileState CheckNextBlock(int x, int y);
};

