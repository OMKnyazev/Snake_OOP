#pragma once
#include "GameObjects.h"
#include "CursorSetting.h"
const int maxSnakeSize = 100;

class Snake : public GameObjects
{
private:
	int snake_x;
	int snake_y;
	GameObjects* cell[maxSnakeSize];
	int snakeSize;
	char direction;
	bool state;
	char badge = 'X';

public:
	Snake();
	int getSankeSize();
	char getDirection();
	bool getState();;
	char getBadge();
	void setSnakeSize(int value);
	void setDirection(char value);
	void setState(bool value);
	int GetX() override;
	int GetY() override;
	void Draw() override;
	void AddCell(int x, int y);
	void TurnUp();
	void TurnDown();
	void TurnLeft();
	void TurnRight();
	void Move();
	int SelfCollision();
	int GetState();
};

