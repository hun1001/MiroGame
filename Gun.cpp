#include "Gun.h"


Gun::Gun(char** tile, POINT* pos, Direction* dir):_tile(tile), _pos(pos), _dir(dir)
{
}

Gun::~Gun()
{
}

void Gun::Fire()
{
	POINT nextPos = { _pos->x, _pos->y };
	while (_tile[nextPos.y][nextPos.x] != Wall)
	{
		switch (*_dir)
		{
		case Direction::UP:
			nextPos.y--;
			break;
		case Direction::DOWN:
			nextPos.y++;
			break;
		case Direction::LEFT:
			nextPos.x--;
			break;
		case Direction::RIGHT:
			nextPos.x++;
			break;
		default:
			perror("잘못된 방향");
			break;
		}
	}

	_tile[nextPos.y][nextPos.x] = Empty;
}

