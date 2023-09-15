#pragma once
#include <Windows.h>
#include "PlayField.h"
#include <iostream>
#include <iomanip>
const int HeighField = 20; // playing field height Y (ordinate) 
const int WidthField = 40; // playing field width X (abscissa)

class PlayField
{
private:
	
	int gamePoints = 0;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // creating an output stream handle
	COORD ScoreCursorPos;

public:
	void drawPlayField();
	void setScoreBoard(); 
	void setGamePoints(int gp); // fruit scoring setter
	int getGamePoints(); //fruit scoring getter
	int addGamePoints(int gp); //method for calculating a set of points
	COORD GetConsoleCursorPosition();
};