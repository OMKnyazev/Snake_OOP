#pragma once
#include <Windows.h>



class CursorSetting
{
public:
	//common class methods to avoid code duplication
	static void gotoxy(int x, int y); // moving the cursor to a given position on the ordinate and abscissa axes
	static void consoleCursorVisible(bool show); // cursor settings
	static void color(int color); // color settings
};

