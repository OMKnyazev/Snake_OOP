#include "GameObjects.h"

GameObjects::GameObjects()
{
}

GameObjects::GameObjects(int x, int y)
{
	this->x = x;
	this->y = y;
}

void GameObjects::SetGameObj(int x, int y)
{
	this->x = x;
	this->y = y;
}

int GameObjects::GetX()
{
	return x;
}

int GameObjects::GetY()
{
	return y;
}

void GameObjects::MoveUp()
{
	y--;
	if (y < 0)
	y = HeighField - 2;
}

void GameObjects::MoveDown()
{
	y++;
	if (y > HeighField - 2)
	y = 0;
}

void GameObjects::MoveLeft()
{
	x--;
	if (x < 0)
	x = WidthField - 1;
}

void GameObjects::MoveRight()
{
	x++;
	if (x > WidthField - 1)
	x = 0;
}

void GameObjects::Draw()
{
	CursorSetting::gotoxy(x, y);
	std::cout << badge;
}

void GameObjects::Draw(char symbol)
{
	std:: cout << symbol;
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


