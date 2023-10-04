#pragma once
#include "PlayField.h"
#include "CursorSetting.h"

class GameObjects
{
private:
	int x; // abscissa coordinate of the object 
	int y; // ordinate coordinate of the object
	char badge; // badge for object
	int color = 12;
	int state;

public:
	GameObjects();
	GameObjects(int x, int y);
	virtual ~GameObjects();

	//Gameobjects interface
	virtual void SetGameObj(int x, int y);
	virtual void set_X(int newX);
	virtual void set_Y(int newY);
	virtual void SetBadge(char newBadge);
	virtual void SetColor(int newColor);
	virtual void SetState(int newState);
	
	virtual int GetX() const;
	virtual int GetY() const;
	virtual char GetBadge() const;
	virtual int GetColor() const;
	virtual bool GetState() const;
	
	virtual void Draw(); // method for drawing the sign of an object
	virtual void Draw(char symbol);
	virtual void Debug(); // Debug method to check reading and writing coordinates
	virtual void MoveUp(); //function for move up object
	virtual void MoveDown(); //function for move down object
	virtual void MoveLeft(); //function for move left object
	virtual void MoveRight(); //function for move right object

public:
	void CopyPos(GameObjects* GmO); // Copy position links object 
	int IsEqual(GameObjects* GmO); // gameObject tail check
};

