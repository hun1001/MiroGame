#include "Player.h"

Player::Player(POINT pos)
{
	_beforePos = pos;
	_pos = pos;
	SetDir(Direction::DOWN);
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

void Player::SetIcon(string icon)
{
	_icon = icon;
}

void Player::SetDir(Direction dir)
{
	switch (dir)
	{
	case Direction::UP:
		_dir = Direction::UP;
		SetIcon("¡ã");
		break;
	case Direction::DOWN:
		_dir = Direction::DOWN;
		SetIcon("¡å");
		break;
	case Direction::LEFT:
		_dir = Direction::LEFT;
		SetIcon("¢¸");
		break;
	case Direction::RIGHT:
		_dir = Direction::RIGHT;
		SetIcon("¢º");
		break;
	default:
		perror("Can't found Direction");
		break;
	}
}

void Player::Move(Direction dir)
{
	_beforePos = _pos;
	SetDir(dir);
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

void Player::PrtPlayer()
{
	cout << _icon;
}

Direction* Player::GetDir()
{
	return &_dir;
}
