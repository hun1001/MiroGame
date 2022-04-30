#include "Player.h"

Player::Player(POINT pos)
{
	_beforePos = pos;
	_pos = pos;
}

POINT Player::GetPos()
{
	return _pos;
}

void Player::SetPos(POINT pos)
{
	_beforePos = _pos;
	_pos = pos;
}

void Player::Move(Direction dir)
{
	_beforePos = _pos;
	switch (dir)
	{
	case Direction::UP:
		_pos.y--;
		break;
	case Direction::DOWN:
		_pos.y++;
		break;
	case Direction::LEFT:
		_pos.x--;
		break;
	case Direction::RIGHT:
		_pos.x++;
		break;
	default:
		perror("Wrong direction");
		break;
	}
}

void Player::Back()
{
	swap(_pos, _beforePos);
}
