#include "Board.h"

Board::Board(int boardSize)
{
	_maze = new Maze(boardSize);
	_size = _maze->GetSize();
	_isGameEnd = false;
	ResetBoard();
	_gun = new Gun(_maze->GetTile(), &(_player->GetPos()), _player->GetDir());
}

void Board::RenderBoard()
{
	// const char** const tile = _maze->GetTile(); 이거 왜 안됨?
	char** const tile = _maze->GetTile();
	for (int y = 0; y < *_size; y++)
	{
		for (int x = 0; x < *_size; x++)
		{
			// 여기 연산자 오버로딩으로 POINT == POINT 가능하게 만들 수는 있는데 그럴려면 POINT도 새로 만들어야 되서 걍 이렇게 함
			if (IsPOINTEqual(_player->GetPos(), intToPoint(x,y)))
			{
				_player->PrtPlayer();
			}
			else 
			{
				switch (tile[y][x])
				{
				case Empty:
					cout << "□";
					break;
				case Wall:
					cout << "■";
					break;
				case Goal:
					cout << "▣";
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
		break;
	}
}

bool Board::GetIsGameEnd()
{
	return _isGameEnd;
}
