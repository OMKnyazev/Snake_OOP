#include "Snake.h"

Snake::Snake()
{
	snakeSize = 1;
	cell[0] = new GameObjects(WidthField / 2, HeighField / 2);
	for (int i = 1; i < maxSnakeSize; i++) {
		cell[i] = NULL;
		state = 0;
	}
}

int Snake::getSankeSize()
{
	return snakeSize;
}

char Snake::getDirection()
{
	return direction;
}

bool Snake::getState()
{
	return state;
}

char Snake::getBadge()
{
	return badge;
}

void Snake::setSnakeSize(int value)
{
	this->snakeSize = value;
}

void Snake::setDirection(char value)
{
	this->direction = value;
}

void Snake::setState(bool value)
{
	this->state = value;
}

int Snake::GetX()
{
	return snake_x;
}

int Snake::GetY()
{
	return snake_y;
}

void Snake::Draw()
{
	getBadge();
}

void Snake::AddCell(int x, int y)
{
	cell[snakeSize++] = new GameObjects(x, y);
}

void Snake::TurnUp()
{
	if (direction != 's')
		direction = 'w'; // w is control key for turning upward
}

void Snake::TurnDown()
{
	if (direction != 'w')
		direction = 's'; // w is control key for turning downward
}

void Snake::TurnLeft()
{
	if (direction != 'd')
		direction = 'a'; // w is control key for turning left
}

void Snake::TurnRight()
{
	if (direction != 'a')
		direction = 'd'; // w is control key for turning right
}

void Snake::Move()
{
	for (int i = 0; i < snakeSize; i++)
	{
		cell[i]->Draw(' ');
	}

	// making snake body follow its head
	for (int i = snakeSize - 1; i > 0; i--)
	{ //1 
		cell[i - 1]->CopyPos(cell[i]);
	}

	// turning snake's head
	switch (direction) { // 2
	case 'w':
		cell[0]->MoveUp();
		break;
	case 's':
		cell[0]->MoveDown();
		break;
	case 'a':
		cell[0]->MoveLeft();
		break;
	case 'd':
		cell[0]->MoveRight();
		break;
	}

	if (cell[0]->GetX() == 0 || cell[0]->GetY() == 0)
	{
		state = 0;
	}
	else if (SelfCollision())
	{
		state = 0;
	}
}

int Snake::SelfCollision()
{
	for (int i = 1; i < snakeSize; i++)
		if (cell[0]->IsEqual(cell[i]))
			return 1;
	return 0;
}

int Snake::GetState()
{
	return state;
}
