#include "Fruits.h"
Fruits::Fruits()
{
	pointPrice = 10;
	SetBadge('@');
	srand(time(0));
	set_X(1 + rand() % (WidthField - 2));
	set_Y(1 + rand() % (HeighField - 2));
	SetColor(12); // 12 - red color
}

Fruits::~Fruits()
{

}

void Fruits::newPosition()
{
	SetGameObj(1 + rand() % (WidthField - 2), 1 + rand() % (HeighField - 2));
}

void Fruits::setPointPrice(int pp)
{
	pointPrice = pp;
}


int Fruits::getPointPrice() const
{
	return pointPrice;
}
