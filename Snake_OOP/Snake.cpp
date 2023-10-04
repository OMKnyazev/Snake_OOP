#include "Snake.h"

Snake::Snake()
{
	SetBadge('X');
	SetColor(12); //12- red color
	snakeSize = 1;
	cell[0] = new GameObjects(WidthField / 2, HeighField / 2);
	for (int i = 1; i < maxSnakeSize; i++) {
		cell[i] = NULL;

	};
}

Snake::~Snake()
{
	for (int i = 1; i < maxSnakeSize; i++)
	{
		if (cell[i] != NULL)
		{
			delete cell[i];
		}
	};
}

int Snake::getSankeSize() const
{
	return snakeSize;
}

char Snake::getDirection() const
{
	return direction;
}

void Snake::setSnakeSize(int value)
{
	snakeSize = value;
}

void Snake::setDirection(char value)
{
	direction = value;
}

void Snake::Draw()
{
	for (int i = 0; i < snakeSize; i++)
	{
		cell[i]->Draw(GetBadge());
	}
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
	switch (direction)
	{ // 2
	case 'w':
		MoveUp();
		break;
	case 's':
		MoveDown();
		break;
	case 'a':
		MoveLeft();
		break;
	case 'd':
		MoveRight();
		break;
	}

	set_X(cell[0]->GetX());
	set_Y(cell[0]->GetY());

	if (GetX() == 0 || GetY() == 0)
	{
		SetState(0);
	}
	else if (SelfCollision())
	{
		SetState(0);
	}
}

int Snake::SelfCollision()
{
	for (int i = 1; i < snakeSize; i++)
		if (cell[0]->IsEqual(cell[i]))
			return 1;
	return 0;
}

void Snake::NewSnake()
{
	SetState(1);
	snakeSize = 1;
	cell[0] = new GameObjects(WidthField / 2, HeighField / 2);
	for (int i = 1; i < maxSnakeSize; i++) {
		cell[i] = NULL;
	};
}

void Snake::Debug()
{
	std::cout << "(" << GetX() << "," << GetY() << ") ";
}

void Snake::MoveUp()
{
	cell[0]->MoveUp();
}

void Snake::MoveDown()
{
	cell[0]->MoveDown();
}

void Snake::MoveLeft()
{
	cell[0]->MoveLeft();
}

void Snake::MoveRight()
{
	cell[0]->MoveRight();
}
