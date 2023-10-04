#pragma once
#include "CursorSetting.h"
#include "Menu.h"
#include "PlayField.h"
#include "Fruits.h"
#include "Snake.h"
#include "GameObjects.h"
#include <thread>
#include <chrono>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


enum class eActoins
{
	NO_ACTIONS = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3,
	RIGHT = 4,
	STOP = 5
};
static eActoins LAST_INPUT;

using namespace std;
class GameLogic
{
private:
	Menu* menu = new Menu;
	PlayField* playField = new PlayField;
	Fruits* apple = new Fruits;
	Snake* snake = new Snake;
	char key = 'l';
	bool started;
	
	//variables to increase snake speed
	const int startSpeed = 250;
	int increaseSpeedStep = 20;
	int levelSpeed = 0;
	int GamePointsStep = 50;


	int CalculateCurrentSpeed(); // method to increase snake speed
	void checkDead(); // method to check whether a snake has collided with the side of the playing field
	void SnakeEats(); // a method that checks the fruit's achievements and adds points
	void Draw(GameObjects* GameObject); //draw
	void SnakeDead(); // method for action in case of snake death (to make it look nice)

	//functions to implement a separate thread
	const eActoins GetLastUserInput();
	void userChoise();
	eActoins readingUserInput();
	void ReadLastInput(Snake* snake);

public:
	GameLogic();
	// basic method of playing
	void PlayGame();
};

