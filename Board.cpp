#include "Board.h"

Board::Board(int boardSize)
{
	_maze = new Maze(boardSize);
	_size = _maze->GetSize();
	_isGameEnd = false;
	ResetBoard();
	_gun = new Gun(_maze->GetTile(), _player->GetPosp(), _player->GetDir());
}

void Board::RenderBoard()
{
	// const char** const tile = _maze->GetTile(); ÀÌ°Å ¿Ö ¾ÈµÊ?
	char** const tile = _maze->GetTile();
	for (int y = 0; y < *_size; y++)
	{
		for (int x = 0; x < *_size; x++)
		{
			if (IsPOINTEqual(_player->GetPos(), intToPoint(x,y)))
			{
				_player->PrtPlayer();
			}
			else 
			{
				switch (tile[y][x])
				{
				case Empty:
					cout << "¡à";
					break;
				case Wall:
					cout << "¡á";
					break;
				case Goal:
					cout << "¢Ã";
					break;
				default:
					perror("Wrong Value");
					break;
				}
			}
		}
		cout << endl;
	}
}

void Board::ResetBoard()
{
	_maze->GenerateByBinaryTree();
	_player = new Player(_maze->GetStartPos());
}

void Board::InputCommend(char input)
{
	LetterIntegrate(input);
	switch (input)
	{
	case ESC:
		ExitGame();
		break;
	case UpArrow:
		MovePlayer(Direction::UP);
		break;
	case DownArrow:
		MovePlayer(Direction::DOWN);
		break;
	case LeftArrow:
		MovePlayer(Direction::LEFT);
		break;
	case RightArrow:
		MovePlayer(Direction::RIGHT);
		break;
	case A:
		_gun->Fire();
		break;
	default:
		break;
	}
}

void Board::ExitGame()
{
	system("cls");
	_isGameEnd = true;
	exit(0);
}

void Board::MovePlayer(Direction dir)
{
	_player->Move(dir);
	if(CheckNextBlock(_player->GetPos().x, _player->GetPos().y) == TileState::CANNOTMOVE)
	{
		_player->Back();
	}
}

TileState Board::CheckNextBlock(int x, int y)
{
	switch (_maze->GetTile()[y][x])
	{
	case Empty:
		return TileState::CANMOVE;
		break;
	case Wall:
		return TileState::CANNOTMOVE;
		break;
	case Goal:
		_isGameEnd = true;
		return TileState::CANMOVE;
		break;
	default:
		perror("Block not found");
		return TileState::CANNOTMOVE;
		break;
	}
}

bool Board::GetIsGameEnd()
{
	return _isGameEnd;
}
