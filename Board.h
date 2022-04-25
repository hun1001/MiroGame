#pragma once
#include <random>
#include <iostream>

namespace MiroInitAlgorithm
{
	enum TileType
	{
		Empty,
		Wall,
		Player,
		Goal
	};

	class Board
	{
	public:
		char** _tile;
		int _size;
		int playerPosX, playerPosY;
		bool _isGoal = false;

		void Initialize(int size);

		void GenerateByBinaryTree();
		
		void RenderBoard();

		void PlayerMoveInput(char input);

		bool PlayerMove(int x, int y);
	};
}