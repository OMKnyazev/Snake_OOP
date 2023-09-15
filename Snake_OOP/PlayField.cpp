#include "PlayField.h"



using namespace std;


void PlayField::drawPlayField()
{
	system("cls");
	SetConsoleTextAttribute(h, 14);
	for (int i = 0; i < HeighField; i++)
	{
		for (int j = 0; j < WidthField + 1; j++)
		{
			if (i == 0 || i == HeighField - 1)
			{
				cout << "#";
			}
			else if (j == 0 || j == WidthField)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}
		if (i == 1)
		{
			cout << setw(22) << "Current Score: " << setw(13); //currentScore
			ScoreCursorPos = GetConsoleCursorPosition();
		}
		if (i == 3)
		{
			cout << setw(22) << "Press E to exit";
		}
		cout << "\n";
	}
}

void PlayField::setScoreBoard()
{
	COORD PrevCursorPosition = GetConsoleCursorPosition();
	SetConsoleCursorPosition(h, ScoreCursorPos);
	cout << getGamePoints();
}

void PlayField::setGamePoints(int gp)
{
		this->gamePoints = gp;
}

int PlayField::getGamePoints()
{
	return gamePoints;
}

int PlayField::addGamePoints(int gp)
{
	setGamePoints(gamePoints + gp);
	setScoreBoard();
	return getGamePoints();
}


COORD PlayField::GetConsoleCursorPosition()
{
	CONSOLE_SCREEN_BUFFER_INFO cbsi;
	if (GetConsoleScreenBufferInfo(h, &cbsi))
	{
		return cbsi.dwCursorPosition;
	}
	else
	{
		// The function failed. Call GetLastError() for details.
		COORD invalid = { 0, 0 };
		return invalid;
	}
}
