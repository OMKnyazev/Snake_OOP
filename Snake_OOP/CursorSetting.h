#pragma once
#include <Windows.h>

class CursorSetting
{
public:
	static void gotoxy(int x, int y);
	static void consoleCursorVisible(bool show);
	static void color(int color);
};

