#include "Board.h"

Board::Board(int boardSize)
{
	_maze = new Maze(boardSize);
	_size = _maze->GetSize();
	_isGameEnd = false;
	ResetBoard();
}

void Board::RenderBoard()
{
	const char** const tile = _maze->GetTile();
	for (int y = 0; y < *_size; y++)
	{
		for (int x = 0; x < *_size; x++)
		{
			// 여기 연산자 오버로딩으로 POINT == POINT 가능하게 만들 수는 있는데 그럴려면 POINT도 새로 만들어야 되서 걍 이렇게 함
			if (IsPOINTEqual(_player->GetPos(), intToPoint(x,y)))
			{
				cout << "♥";
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
	switch (input)
	{
	case ESC:
		// 게임 종료 처리 함수 실행 지금은 exit로
		exit(0);
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
	default:
		break;
	}
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
