#pragma once
#include "GameObjects.h"
#include "CursorSetting.h"


class Fruits : public GameObjects 
{
private:
	int x_fruit; // abscissa (X) coordinate of the fruit 
	int y_fryit; // // ordinate (Y) coordinate of the fruit
	char badge; //fruit sign
	int pointPrice; // fruit cost

public:

	Fruits(); // constructor
	void setFruit(int x, int y); // setter for fruit coordinates
	int GetX() override;
	int GetY() override; 
	char getBadge(); // getter for badge
	void setPointPrice(int pp); // setter for fruit price
	int getPointPrice(); // getter for fruit price
	void Draw() override;
};

