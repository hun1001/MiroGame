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

		void Initialize(int size);

		void GenerateByBinaryTree();
		
		void RenderBoard();

		void PlayerMoveInput(char input);

		void PlayerMove(int x, int y);
	};
}