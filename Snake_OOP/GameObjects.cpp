#include "GameObjects.h"

GameObjects::GameObjects()
{
}

GameObjects::GameObjects(int Coordinate_x, int Coordinate_y)
{
	x = Coordinate_x;
	y = Coordinate_y;
}

GameObjects::~GameObjects()
{

}

bool GameObjects::GetState() const
{
	return state;
}

void GameObjects::SetState(int newState)
{
	state = newState;
}

void GameObjects::SetGameObj(int Coordinate_x, int Coordinate_y)
{
	x = Coordinate_x;
	y = Coordinate_y;
}

int GameObjects::GetX() const
{
	return x;
}

int GameObjects::GetY() const
{
	return y;
}

void GameObjects::set_X(int newX)
{
	x = newX;
}

void GameObjects::set_Y(int newY)
{
	y = newY;
}

void GameObjects::MoveUp()
{
	y--;

}

void GameObjects::MoveDown()
{
	y++;
}

void GameObjects::MoveLeft()
{
	x--;
}

void GameObjects::MoveRight()
{
	x++;
}

void GameObjects::Draw()
{
	CursorSetting::gotoxy(x, y);
	CursorSetting::color(color);
	std::cout << badge;
}

void GameObjects::Draw(char symbol)
{
	CursorSetting::gotoxy(x, y);
	CursorSetting::color(color);
	std::cout << symbol;
}

void GameObjects::CopyPos(GameObjects* GmO)
{
	GmO->x = x;
	GmO->y = y;
}

int GameObjects::IsEqual(GameObjects* GmO)
{
	if (GmO->x == x && GmO->y == y)
	{
		return 1;
	}
	return 0;
}

void GameObjects::Debug()
{
	std::cout << "(" << x << "," << y << ") ";
}

char GameObjects::GetBadge() const
{
	return badge;
}

void GameObjects::SetBadge(char newBadge)
{
	badge = newBadge;
}

int GameObjects::GetColor() const
{
	return color;
}

void GameObjects::SetColor(int newColor)
{
	color = newColor;
}


