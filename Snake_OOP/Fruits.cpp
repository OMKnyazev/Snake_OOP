#include "Fruits.h"
Fruits::Fruits()
{
	pointPrice = 10;
	badge = '@';
	srand(time(0));
	x_fruit = 1 + rand() % (WidthField - 2);
	y_fryit = 1 + rand() % (HeighField - 2);
}

void Fruits::setFruit(int x, int y)
{
	this->x_fruit = x;
	this->y_fryit = y;
}

int Fruits::GetX()
{
	return x_fruit;
}

int Fruits::GetY()
{
	return y_fryit;
}


char Fruits::getBadge()
{
	return badge;
}

void Fruits::Draw() 
{
	CursorSetting::gotoxy(x_fruit, y_fryit);
	CursorSetting::color(12) ; // 12 - output color (red)
	std::cout << getBadge();
}

void Fruits::setPointPrice(int pp)
{
	this->pointPrice = pp;
}


int Fruits::getPointPrice()
{
	return pointPrice;
}
