#pragma once
#include "GameObjects.h"
#include "CursorSetting.h"
const int maxSnakeSize = 100;

class Snake : public GameObjects
{
private:
	GameObjects* cell[maxSnakeSize];
	int snakeSize = 1;
	char direction;
	int color = 12;

public:
	Snake();
	virtual ~Snake();

	// Gameobject interface
	virtual void Draw() override;
	virtual void Debug() override;

	virtual void MoveUp() override;
	virtual void MoveDown() override;
	virtual void MoveLeft() override;
	virtual void MoveRight() override;

	// snake methods
	void setSnakeSize(int value);
	void setDirection(char value);
	
	int getSankeSize() const;
	char getDirection() const;
	
	void AddCell(int x, int y);//adding links to a snake
	int SelfCollision();
	void NewSnake();//method for cleaning snake

	//moving logic
	void Move();
	void TurnUp();
	void TurnDown();
	void TurnLeft();
	void TurnRight();
};

