#pragma once
#include "GameObjects.h"
#include "CursorSetting.h"


class Fruits : public GameObjects
{
private:
	int pointPrice; // fruit cost

public:

	Fruits();
	virtual ~Fruits();

	//Gameobject interface
	void setPointPrice(int pp);
	int getPointPrice() const; 
	
	void newPosition(); // method of changing the position of a fruit in case of being eaten by a snake
};

