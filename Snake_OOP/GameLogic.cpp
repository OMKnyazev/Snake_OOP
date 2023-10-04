#include "GameLogic.h"


int GameLogic::CalculateCurrentSpeed()
{
	levelSpeed = (int)(playField->getGamePoints() / GamePointsStep);
	return startSpeed - (levelSpeed * increaseSpeedStep);
}

void GameLogic::checkDead()
{
	if (snake->GetX() == 0 || snake->GetY() == 0 || snake->GetX() == WidthField || snake->GetY() == HeighField - 1 || snake->GetState() == 0)
	{
		key = 'e';
	}
}

void GameLogic::SnakeEats()
{
	if (apple->GetX() == snake->GetX() && apple->GetY() == snake->GetY())
	{
		snake->AddCell(0, 0);
		apple->SetGameObj(1 + rand() % (WidthField - 2), 1 + rand() % (HeighField - 2));
		apple->Draw();
		playField->addGamePoints(10);
		playField->setScoreBoard();
	}
};

void GameLogic::Draw(GameObjects* GameObject)
{
	GameObject->Draw();
}
void GameLogic::SnakeDead()
{

	snake->NewSnake();
	playField->setGamePoints(0);
	system("cls");
	cout << endl;
	cout << setw(20) << "Game Over" << endl;
	cout << endl;
	cout << setw(2) << "Press any key to exit the menu" << endl;
	cout << setw(6) << "or E to complete the program";
	key = _getch();
	system("cls");
}
;

const eActoins GameLogic::GetLastUserInput()
{
	return LAST_INPUT;
};

void GameLogic::userChoise()
{
	while (true)
	{
		LAST_INPUT = readingUserInput();
	}
}

eActoins GameLogic::readingUserInput()
{
	if (_kbhit()) {
		key = _getch();
	}

	switch (key)
	{
	case 'w':
	case 'W':
	case KEY_UP:
		return eActoins::UP;
		break;

	case 's':
	case 'S':
	case KEY_DOWN:
		return eActoins::DOWN;
		break;

	case 'a':
	case 'A':
	case KEY_LEFT:
		return eActoins::LEFT;
		break;

	case 'd':
	case 'D':
	case KEY_RIGHT:
		return eActoins::RIGHT;
		break;

	case 'e':
		return eActoins::STOP;
	default:
		break;
	}
	return eActoins::NO_ACTIONS;
}

void GameLogic::ReadLastInput(Snake* snake)
{
	switch (LAST_INPUT)
	{
	case eActoins::LEFT:
		snake->TurnLeft();
		break;
	case eActoins::RIGHT:
		snake->TurnRight();
		break;
	case eActoins::DOWN:
		snake->TurnDown();
		break;
	case eActoins::UP:
		snake->TurnUp();
		break;
	default:

		break;
	}
}

GameLogic::GameLogic()
{
	snake->setSnakeSize(1);
	started = false;

}

void GameLogic::PlayGame()
{
	SetConsoleTitle(L" SNAKE ");
	do
	{
		menu->showMenu();
		system("cls");
		playField->drawPlayField();
		playField->setScoreBoard();
		std::thread InputThread(&GameLogic::userChoise, this);
		InputThread.detach();
		key = 'l';

		do
		{
			Draw(apple);
			Draw(snake);
			ReadLastInput(snake);
			this_thread::sleep_for(chrono::milliseconds(CalculateCurrentSpeed()));
			snake->Move();
			SnakeEats();
			checkDead();
		} while (key != 'e');
		SnakeDead();
	} while (key != 'e');
}






