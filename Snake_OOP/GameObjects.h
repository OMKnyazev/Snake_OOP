#pragma once
#include "PlayField.h"
#include "CursorSetting.h"

class GameObjects
{
private:
	int x; // abscissa coordinate of the object 
	int y; // ordinate coordinate of the object
	int badge; // badge for object

public:
	GameObjects();
	GameObjects(int x, int y);
	void SetGameObj(int x, int y); 
	virtual int GetX();
	virtual int GetY();
	void MoveUp(); //function for move up object
	void MoveDown(); //function for move down object
	void MoveLeft(); //function for move left object
	void MoveRight(); //function for move right object
	virtual void Draw(); // method for drawing the sign of an object
	void Draw(char symbol);
	void CopyPos(GameObjects* GmO);
	int IsEqual(GameObjects* GmO); // snake tail check
	void Debug(); // Debug method to check reading and writing coordinates
};

